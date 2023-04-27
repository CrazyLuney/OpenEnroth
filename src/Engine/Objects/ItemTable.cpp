#include "ItemTable.h"

#include "Engine/Tables/StorylineTextTable.h"
#include "Engine/Tables/FactionTable.h"
#include "Engine/Spells/Spells.h"
#include "Engine/Objects/Monsters.h"
#include "Engine/LOD.h"
#include "Engine/MapInfo.h"
#include "Engine/mm7_data.h"

#include "GUI/UI/UIHouses.h"

#include "Utility/Strings.h"
#include "Utility/MapAccess.h"
#include "Utility/MiniParser.hpp"
#include "Library/Random/Random.h"

namespace
{
	static const std::map<std::string, ITEM_EQUIP_TYPE, ILess> equipStatMap
	{
		{ "weapon", EQUIP_SINGLE_HANDED },
		{ "weapon2", EQUIP_TWO_HANDED },
		{ "weapon1or2", EQUIP_SINGLE_HANDED },
		{ "missile", EQUIP_BOW },
		{ "bow", EQUIP_BOW },
		{ "armor", EQUIP_ARMOUR },
		{ "shield", EQUIP_SHIELD },
		{ "helm", EQUIP_HELMET },
		{ "belt", EQUIP_BELT },
		{ "cloak", EQUIP_CLOAK },
		{ "gauntlets", EQUIP_GAUNTLETS },
		{ "boots", EQUIP_BOOTS },
		{ "ring", EQUIP_RING },
		{ "amulet", EQUIP_AMULET },
		{ "weaponw", EQUIP_WAND },
		{ "herb", EQUIP_REAGENT },
		{ "reagent", EQUIP_REAGENT },
		{ "bottle", EQUIP_POTION },
		{ "sscroll", EQUIP_SPELL_SCROLL },
		{ "book", EQUIP_BOOK },
		{ "mscroll", EQUIP_MESSAGE_SCROLL },
		{ "gold", EQUIP_GOLD },
		{ "gem", EQUIP_GEM },
	};

	static const std::map<std::string, PLAYER_SKILL_TYPE, ILess> equipSkillMap
	{
		{ "staff", PLAYER_SKILL_STAFF },
		{ "sword", PLAYER_SKILL_SWORD },
		{ "dagger", PLAYER_SKILL_DAGGER },
		{ "axe", PLAYER_SKILL_AXE },
		{ "spear", PLAYER_SKILL_SPEAR },
		{ "bow", PLAYER_SKILL_BOW },
		{ "mace", PLAYER_SKILL_MACE },
		{ "blaster", PLAYER_SKILL_BLASTER },
		{ "shield", PLAYER_SKILL_SHIELD },
		{ "leather", PLAYER_SKILL_LEATHER },
		{ "chain", PLAYER_SKILL_CHAIN },
		{ "plate", PLAYER_SKILL_PLATE },
		{ "club", PLAYER_SKILL_CLUB },
	};

	static const std::map<std::string, ITEM_MATERIAL, ILess> materialMap
	{
		{ "artifact", MATERIAL_ARTIFACT },
		{ "relic", MATERIAL_RELIC },
		{ "special", MATERIAL_SPECIAL },
	};
}

//----- (0045814E) --------------------------------------------------------
void ItemTable::Release()
{
	pMonstersTXT_Raw.clear();
	pMonsterPlacementTXT_Raw.clear();
	pSpcItemsTXT_Raw.clear();
	pStdItemsTXT_Raw.clear();
	pRndItemsTXT_Raw.clear();
	pItemsTXT_Raw.clear();
	pHostileTXT_Raw.clear();
	pHistoryTXT_Raw.clear();
	free(pPotionsTXT_Raw);
	free(pPotionNotesTXT_Raw);
	pPotionsTXT_Raw = nullptr;
	pPotionNotesTXT_Raw = nullptr;
}

//----- (00456D84) --------------------------------------------------------
void ItemTable::Initialize()
{
	char* test_string;

	pMapStats = new MapStats;
	pMapStats->Initialize();

	pMonsterStats = new MonsterStats;
	pMonsterStats->Initialize();
	pMonsterStats->InitializePlacements();

	pSpellStats = new SpellStats;
	pSpellStats->Initialize();

	LoadPotions();
	LoadPotionNotes();

	pFactionTable = new FactionTable;
	pFactionTable->Initialize();

	pStorylineText = new StorylineText;
	pStorylineText->Initialize();

	InitializeStandardEnchantments();
	InitializeSpecialEnchantments();

	InitializeBuildingResidents();

	InitializeItems();

	InitializeRandomItems();

	ItemGen::PopulateSpecialBonusMap();
	ItemGen::PopulateArtifactBonusMap();
	ItemGen::PopulateRegularBonusMap();
}

//----- (00456D17) --------------------------------------------------------
void ItemTable::SetSpecialBonus(ItemGen* pItem)
{
	if (pItems[pItem->uItemID].uMaterial == MATERIAL_SPECIAL)
	{
		pItem->uEnchantmentType = pItems[pItem->uItemID]._bonus_type;
		pItem->special_enchantment =
			(ITEM_ENCHANTMENT)pItems[pItem->uItemID]._additional_value;
		pItem->m_enchantmentStrength = pItems[pItem->uItemID]._bonus_strength;
	}
}

//----- (00456D43) --------------------------------------------------------
bool ItemTable::IsMaterialSpecial(ItemGen* pItem)
{
	return this->pItems[pItem->uItemID].uMaterial == MATERIAL_SPECIAL;
}

//----- (00456D5E) --------------------------------------------------------
bool ItemTable::IsMaterialNonCommon(ItemGen* pItem)
{
	return pItems[pItem->uItemID].uMaterial == MATERIAL_SPECIAL ||
		pItems[pItem->uItemID].uMaterial == MATERIAL_RELIC ||
		pItems[pItem->uItemID].uMaterial == MATERIAL_ARTIFACT;
}

//----- (00453B3C) --------------------------------------------------------
void ItemTable::LoadPotions()
{
	using namespace std::literals::string_view_literals;
	using namespace MiniParser;

	static constexpr auto FirstPotionLinePrefix = "222\t"sv;
	static constexpr auto InvalidMixturePrefix = "E"sv;

	//static const std::regex re_mix_result { R"((e)?(\d+))", std::regex::optimize | std::regex::icase };

	const auto blob = pEvents_LOD->LoadCompressedTexture("potion.txt");
	const auto blob_lines = Lines(blob.string_view());

	auto data_lines = blob_lines | std::views::drop_while([](const auto& data_line)
		{
			return !data_line.starts_with(FirstPotionLinePrefix);
		});

	if (data_lines.empty())
	{
		logger->warning("Error Pre-Parsing Potion Table");
		return;
	}

	for (const auto& data_line : data_lines)
	{
		auto [it, it_end] = Tokenize(data_line);

		ITEM_TYPE row;

		ParseToken(it, row);

		SkipToken(it); // name
		SkipToken(it); // desc
		SkipToken(it); // effect
		SkipToken(it); // R
		SkipToken(it); // B
		SkipToken(it); // Y

		for (auto col : Segment<ITEM_TYPE>(ITEM_FIRST_REAL_POTION, ITEM_LAST_REAL_POTION))
		{
			std::string_view token;

			ParseToken(it, token);

			// values like "E{x}" represent damage level {x} when using invalid potion combination
			// plain numbers denote mixture item ID
			if (token.starts_with(InvalidMixturePrefix))
			{
				Parse(token.substr(InvalidMixturePrefix.length()), potionCombination[row][col]);
			}
			else
			{
				Parse(token, potionCombination[row][col], ITEM_NULL);
			}
		}
	}
}

//----- (00453CE5) --------------------------------------------------------
void ItemTable::LoadPotionNotes()
{
	using namespace std::literals::string_view_literals;
	using namespace MiniParser;

	static constexpr auto FirstPotionLinePrefix = "222\t"sv;

	const auto blob = pEvents_LOD->LoadCompressedTexture("potion.txt");
	const auto blob_lines = Lines(blob.string_view());

	auto data_lines = blob_lines | std::views::drop_while([](const auto& data_line)
		{
			return !data_line.starts_with(FirstPotionLinePrefix);
		});

	if (data_lines.empty())
	{
		logger->warning("Error Pre-Parsing Potion Table");
		return;
	}

	for (const auto& data_line : data_lines)
	{
		auto [it, it_end] = Tokenize(data_line);

		ITEM_TYPE row;

		ParseToken(it, row);

		SkipToken(it); // name
		SkipToken(it); // desc
		SkipToken(it); // effect
		SkipToken(it); // R
		SkipToken(it); // B
		SkipToken(it); // Y

		for (auto col : Segment<ITEM_TYPE>(ITEM_FIRST_REAL_POTION, ITEM_LAST_REAL_POTION))
		{
			std::string_view token;

			ParseToken(it, potionNotes[row][col]);
		}
	}
}

//----- (00456620) --------------------------------------------------------
void ItemTable::GenerateItem(ITEM_TREASURE_LEVEL treasure_level, unsigned int uTreasureType, ItemGen* out_item)
{
	Assert(IsRandomTreasureLevel(treasure_level));

	int current_chance;           // ebx@43
	int tmp_chance;               // ecx@47
	ITEM_TYPE artifact_random_id;       // ebx@57
	int v18;                      // edx@62
	unsigned int special_chance;  // edx@86
	unsigned int v26;             // edx@89
	unsigned int v27;             // eax@89
	int v32;                      // ecx@91
	int v33;                      // eax@91
	//    unsigned int v34; // eax@97
	int j;              // eax@121
	std::array<ITEM_TYPE, 800> val_list;  // [sp+Ch] [bp-C88h]@33
	std::array<ITEM_ENCHANTMENT, 800> val_list2;
	int total_chance;   // [sp+C8Ch] [bp-8h]@33
	int artifact_found = 0;       // [sp+CA0h] [bp+Ch]@55
	int v57;            // [sp+CA0h] [bp+Ch]@62

	if (!out_item) out_item = (ItemGen*)malloc(sizeof(ItemGen));
	memset(out_item, 0, sizeof(*out_item));

	if (uTreasureType)
	{
		// generate known treasure type
		ITEM_EQUIP_TYPE requested_equip;
		PLAYER_SKILL_TYPE requested_skill = PLAYER_SKILL_INVALID;
		switch (uTreasureType)
		{
		case 20:
			requested_equip = EQUIP_SINGLE_HANDED;
			break;
		case 21:
			requested_equip = EQUIP_ARMOUR;
			break;
		case 22:
			requested_skill = PLAYER_SKILL_MISC;
			break;
		case 23:
			requested_skill = PLAYER_SKILL_SWORD;
			break;
		case 24:
			requested_skill = PLAYER_SKILL_DAGGER;
			break;
		case 25:
			requested_skill = PLAYER_SKILL_AXE;
			break;
		case 26:
			requested_skill = PLAYER_SKILL_SPEAR;
			break;
		case 27:
			requested_skill = PLAYER_SKILL_BOW;
			break;
		case 28:
			requested_skill = PLAYER_SKILL_MACE;
			break;
		case 29:
			requested_skill = PLAYER_SKILL_CLUB;
			break;
		case 30:
			requested_skill = PLAYER_SKILL_STAFF;
			break;
		case 31:
			requested_skill = PLAYER_SKILL_LEATHER;
			break;
		case 32:
			requested_skill = PLAYER_SKILL_CHAIN;
			break;
		case 33:
			requested_skill = PLAYER_SKILL_PLATE;
			break;
		case 34:
			requested_equip = EQUIP_SHIELD;
			break;
		case 35:
			requested_equip = EQUIP_HELMET;
			break;
		case 36:
			requested_equip = EQUIP_BELT;
			break;
		case 37:
			requested_equip = EQUIP_CLOAK;
			break;
		case 38:
			requested_equip = EQUIP_GAUNTLETS;
			break;
		case 39:
			requested_equip = EQUIP_BOOTS;
			break;
		case 40:
			requested_equip = EQUIP_RING;
			break;
		case 41:
			requested_equip = EQUIP_AMULET;
			break;
		case 42:
			requested_equip = EQUIP_WAND;
			break;
		case 43:
			requested_equip = EQUIP_SPELL_SCROLL;
			break;
		case 44:
			requested_equip = EQUIP_POTION;
			break;
		case 45:
			requested_equip = EQUIP_REAGENT;
			break;
		case 46:
			requested_equip = EQUIP_GEM;
			break;
		default:
			__debugbreak();  // check this condition
			// TODO(captainurist): explore
			requested_equip = (ITEM_EQUIP_TYPE)(uTreasureType - 1);
			break;
		}
		val_list.fill(ITEM_NULL);
		total_chance = 0;
		j = 0;
		// a2a = 1;
		if (requested_skill == PLAYER_SKILL_INVALID)
		{
			// no skill for this item needed
			for (ITEM_TYPE i : SpawnableItems())
			{
				if (pItems[i].uEquipType == requested_equip)
				{
					val_list[j] = i;
					++j;
					total_chance += pItems[i].uChanceByTreasureLvl[treasure_level];
				}
			}
		}
		else
		{
			// have needed skill
			for (ITEM_TYPE i : SpawnableItems())
			{
				if (pItems[i].uSkillType == requested_skill)
				{
					val_list[j] = i;
					++j;
					total_chance +=
						pItems[i].uChanceByTreasureLvl[treasure_level];
				}
			}
		}

		current_chance = 0;
		if (total_chance)
		{
			current_chance = grng->random(total_chance) + 1;
			tmp_chance = 0;
			j = 0;
			while (tmp_chance < current_chance)
			{
				out_item->uItemID = val_list[j];
				tmp_chance += pItems[val_list[j]].uChanceByTreasureLvl[treasure_level];
				++j;
			}
		}
		else
		{
			out_item->uItemID = ITEM_CRUDE_LONGSWORD;
		}
	}
	else
	{
		// artifact
		if (treasure_level == ITEM_TREASURE_LEVEL_6)
		{
			for (ITEM_TYPE i : SpawnableArtifacts())
				artifact_found += pParty->pIsArtifactFound[i];
			artifact_random_id = grng->randomSample(SpawnableArtifacts());
			if ((grng->random(100) < 5) && !pParty->pIsArtifactFound[artifact_random_id] &&
				(engine->config->gameplay.ArtifactLimit.value() == 0 || artifact_found < engine->config->gameplay.ArtifactLimit.value()))
			{
				pParty->pIsArtifactFound[artifact_random_id] = 1;
				out_item->uAttributes = 0;
				out_item->uItemID = artifact_random_id;
				SetSpecialBonus(out_item);
				return;
			}
		}

		v57 = 0;
		v18 = grng->random(this->uChanceByTreasureLvlSumm[treasure_level]) + 1;
		while (v57 < v18)
		{
			// TODO(captainurist): what's going on here? Get rid of casts.
			out_item->uItemID = ITEM_TYPE(std::to_underlying(out_item->uItemID) + 1);
			v57 += pItems[out_item->uItemID].uChanceByTreasureLvl[treasure_level];
		}
	}
	if (out_item->isPotion() && out_item->uItemID != ITEM_POTION_BOTTLE)
	{  // if it potion set potion spec
		out_item->uEnchantmentType = 0;
		for (int i = 0; i < 2; ++i)
		{
			out_item->uEnchantmentType += grng->random(4) + 1;
		}
		out_item->uEnchantmentType = out_item->uEnchantmentType * std::to_underlying(treasure_level);
	}

	if (out_item->uItemID == ITEM_SPELLBOOK_DIVINE_INTERVENTION &&
		!(uint16_t)_449B57_test_bit(pParty->_quest_bits, 239))
		out_item->uItemID = ITEM_SPELLBOOK_SUNRAY;
	if (pItemTable->pItems[out_item->uItemID].uItemID_Rep_St)
		out_item->uAttributes = 0;
	else
		out_item->uAttributes = ITEM_IDENTIFIED;

	if (!out_item->isPotion())
	{
		out_item->special_enchantment = ITEM_ENCHANTMENT_NULL;
		out_item->uEnchantmentType = 0;
	}
	// try get special enhansment
	switch (out_item->GetItemEquipType())
	{
	case EQUIP_SINGLE_HANDED:
	case EQUIP_TWO_HANDED:
	case EQUIP_BOW:
		if (!uBonusChanceWpSpecial[treasure_level]) return;
		if (grng->random(100) >= uBonusChanceWpSpecial[treasure_level])
			return;
		break;
	case EQUIP_ARMOUR:
	case EQUIP_SHIELD:
	case EQUIP_HELMET:
	case EQUIP_BELT:
	case EQUIP_CLOAK:
	case EQUIP_GAUNTLETS:
	case EQUIP_BOOTS:
	case EQUIP_RING:

		if (!uBonusChanceStandart[treasure_level]) return;
		special_chance = grng->random(100);
		if (special_chance < uBonusChanceStandart[treasure_level])
		{
			v26 = grng->random(pEnchantmentsSumm[out_item->GetItemEquipType()]) + 1;
			v27 = 0;
			while (v27 < v26)
			{
				++out_item->uEnchantmentType;
				v27 += pEnchantments[out_item->uEnchantmentType].to_item[out_item->GetItemEquipType()];
			}

			v33 = grng->random(bonus_ranges[treasure_level].maxR - bonus_ranges[treasure_level].minR + 1);
			out_item->m_enchantmentStrength =
				v33 + bonus_ranges[treasure_level].minR;
			v32 = out_item->uEnchantmentType - 1;
			if (v32 == 21 || v32 == 22 ||
				v32 == 23)  // Armsmaster skill, Dodge skill, Unarmed skill
				out_item->m_enchantmentStrength =
				out_item->m_enchantmentStrength / 2;
			if (out_item->m_enchantmentStrength <= 0)
				out_item->m_enchantmentStrength = 1;
			return;

		}
		else if (special_chance >=
			uBonusChanceStandart[treasure_level] +
			uBonusChanceSpecial[treasure_level])
		{
			return;
		}
		break;
	case EQUIP_WAND:
		out_item->uNumCharges = grng->random(6) + out_item->GetDamageMod() + 1;
		out_item->uMaxCharges = out_item->uNumCharges;
		return;
	default:
		return;
	}

	j = 0;
	int spc_sum = 0;
	int spc;
	val_list2.fill(ITEM_ENCHANTMENT_NULL);
	for (ITEM_ENCHANTMENT i : pSpecialEnchantments.indices())
	{
		int tr_lv = (pSpecialEnchantments[i].iTreasureLevel) & 3;

		// tr_lv  0 = treasure level 3/4
		// tr_lv  1 = treasure level 3/4/5
		// tr_lv  2 = treasure level 4/5
		// tr_lv  3 = treasure level 5/6

		if ((treasure_level == ITEM_TREASURE_LEVEL_3) && (tr_lv == 1 || tr_lv == 0) ||
			(treasure_level == ITEM_TREASURE_LEVEL_4) && (tr_lv == 2 || tr_lv == 1 || tr_lv == 0) ||
			(treasure_level == ITEM_TREASURE_LEVEL_5) && (tr_lv == 3 || tr_lv == 2 || tr_lv == 1) ||
			(treasure_level == ITEM_TREASURE_LEVEL_6) && (tr_lv == 3))
		{
			spc = pSpecialEnchantments[i].to_item[out_item->GetItemEquipType()];
			spc_sum += spc;
			if (spc)
			{
				val_list2[j++] = i;
			}
		}
	}

	int target = grng->random(spc_sum);
	for (int currentSum = 0, k = 0; k < j; k++)
	{
		currentSum += pSpecialEnchantments[val_list2[k]].to_item[out_item->GetItemEquipType()];
		if (currentSum > target)
		{
			out_item->special_enchantment = val_list2[k];
			return;
		}
	}
	assert(false); // Should never get here.
}

// TODO: use std::string::contains once Android have full C++23 support.
auto contains = [](const std::string& haystack, const std::string& needle)
{
	return haystack.find(needle) != std::string::npos;
};

void ItemTable::PrintItemTypesEnum()
{
	std::unordered_map<std::string, int> countByName;
	std::unordered_map<std::string, int> indexByName;
	std::vector<std::pair<std::string, std::string>> items;

	items.emplace_back("NULL", "");

	for (ITEM_TYPE i : pItems.indices())
	{
		const ItemDesc& desc = pItems[i];
		std::string icon = desc.pIconName;
		std::string name = desc.pName;
		std::string description = desc.pDescription;

		if (icon.empty() || icon == "null")
		{
			items.emplace_back("", "Unused.");
			continue;
		}

		std::string enumName;
		for (char c : name)
		{
			if (isalnum(c))
			{
				enumName += static_cast<char>(toupper(c));
			}
			else if (isspace(c) || c == '/' || c == '-')
			{
				if (!enumName.ends_with('_'))
					enumName += '_';
			}
		}

		if (enumName == "EMPTY_MESSAGE_SCROLL" || enumName == "NAME_OF_MESSAGE")
		{
			items.emplace_back("", "Empty scroll placeholder, unused.");
			continue;
		}

		if (enumName == "NEWNAME_KEY")
		{
			items.emplace_back("", "Key placeholder, unused.");
			continue;
		}

		if (contains(enumName, "PLACEHOLDER") || contains(enumName, "SEALED_LETTER"))
		{
			items.emplace_back("", name + ", unused.");
			continue;
		}

		if (contains(enumName, "ORDERS_FROM_SNERGLE"))
		{
			items.emplace_back("", name + ", unused remnant from MM6.");
			continue;
		}

		if (enumName == "LICH_JAR")
		{
			if (contains(description, "Empty"))
			{
				enumName += "_EMPTY";
			}
			else
			{
				enumName += "_FULL";
			}
		}

		if (enumName == "THE_PERFECT_BOW")
			if (!contains(description, "off-balance"))
				enumName += "_FIXED";

		if (desc.uEquipType == EQUIP_REAGENT)
		{
			enumName = "REAGENT_" + enumName;
		}
		else if (desc.uEquipType == EQUIP_POTION)
		{
			if (!enumName.starts_with("POTION_"))
				enumName = "POTION_" + enumName;
			if (enumName.ends_with("_POTION"))
				enumName = enumName.substr(0, enumName.size() - 7);
		}
		else if (desc.uEquipType == EQUIP_SPELL_SCROLL)
		{
			enumName = "SCROLL_" + enumName;
		}
		else if (desc.uEquipType == EQUIP_BOOK)
		{
			enumName = "SPELLBOOK_" + enumName;
		}
		else if (desc.uEquipType == EQUIP_MESSAGE_SCROLL)
		{
			if (enumName.ends_with("_RECIPE"))
			{
				enumName = "RECIPE_" + enumName.substr(0, enumName.size() - 7);
			}
			else if (!enumName.starts_with("MESSAGE_"))
			{
				enumName = "MESSAGE_" + enumName;
			}
		}
		else if (desc.uEquipType == EQUIP_GOLD)
		{
			if (description == "A small pile of gold coins.")
			{
				enumName = "GOLD_SMALL";
			}
			else if (description == "A pile of gold coins.")
			{
				enumName = "GOLD_MEDIUM";
			}
			else if (description == "A large pile of gold coins.")
			{
				enumName = "GOLD_LARGE";
			}
			else
			{
				Assert(false);
			}
		}
		else if (desc.uEquipType == EQUIP_GEM)
		{
			enumName = "GEM_" + enumName;
		}

		if (desc.uMaterial == MATERIAL_ARTIFACT)
		{
			enumName = "ARTIFACT_" + enumName;
		}
		else if (desc.uMaterial == MATERIAL_RELIC)
		{
			enumName = "RELIC_" + enumName;
		}
		else if (desc.uMaterial == MATERIAL_SPECIAL)
		{
			enumName = "RARE_" + enumName;
		}
		else if (description.starts_with("Quest"))
		{
			enumName = "QUEST_" + enumName;
		}

		if (indexByName.contains(enumName))
		{
			int count = ++countByName[enumName];
			if (count == 2)
				items[indexByName[enumName]].first = enumName + "_1";

			enumName = enumName + "_" + std::to_string(count);
		}
		else
		{
			indexByName[enumName] = items.size();
			countByName[enumName] = 1;
		}

		items.emplace_back(enumName, "");
	}

	printf("enum ITEM_TYPE {\n");
	for (size_t i = 0; i < items.size(); i++)
	{
		if (!items[i].first.empty())
		{
			printf("    ITEM_%s = %d,\n", items[i].first.c_str(), static_cast<int>(i));
		}
		else
		{
			printf("    ITEM_%d = %d, // %s\n", static_cast<int>(i), static_cast<int>(i), items[i].second.c_str());
		}
	}
	printf("};\n");
}

void ItemTable::InitializeStandardEnchantments()
{
	pEnchantmentsSumm.fill(0);

	using namespace MiniParser;

	const auto blob = pEvents_LOD->LoadCompressedTexture("stditems.txt");
	const auto blob_lines = Lines(blob.string_view());

	{
		const auto data_lines = blob_lines | std::views::drop(4) | std::views::take(pEnchantments.size());

		std::size_t i = 0;

		for (const auto& data_line : data_lines)
		{
			auto [it, it_end] { Tokenize(data_line) };

			auto& enchantment = pEnchantments[i++];

			ParseToken(it, enchantment.pBonusStat, StripQuotes);
			ParseToken(it, enchantment.pOfName, StripQuotes);

			for (auto item_equip_type : enchantment.to_item.indices())
			{
				ParseToken(it, enchantment.to_item[item_equip_type]);

				pEnchantmentsSumm[item_equip_type] += enchantment.to_item[item_equip_type];
			}
		}
	}

	{
		const auto data_lines = blob_lines | std::views::drop(4) | std::views::drop(pEnchantments.size()) | std::views::drop(5) | std::views::take(bonus_ranges.size());

		for (const auto& data_line : data_lines)
		{
			auto [it, it_end] { Tokenize(data_line) };

			ITEM_TREASURE_LEVEL level;

			SkipToken(it);
			ParseToken(it, level);

			auto& bonus_range = bonus_ranges[level];

			ParseToken(it, bonus_range.minR);
			ParseToken(it, bonus_range.maxR);
		}
	}
}

void ItemTable::InitializeSpecialEnchantments()
{
	static const std::regex re_value_or_multiplier{ R"((\s*x\s*(\d+))|(\d+))", std::regex::optimize | std::regex::icase };

	using namespace MiniParser;

	const auto blob = pEvents_LOD->LoadCompressedTexture("spcitems.txt");
	const auto blob_lines = Lines(blob.string_view());

	const auto data_lines = blob_lines | std::views::drop(4) | std::views::take(pSpecialEnchantments.size());

	auto i = std::begin(pSpecialEnchantments.indices());

	for (const auto& data_line : data_lines)
	{
		auto [it, it_end] { Tokenize(data_line) };

		auto& enchantment = pSpecialEnchantments[*i];
		++i;

		ParseToken(it, enchantment.pBonusStatement, StripQuotes);
		ParseToken(it, enchantment.pNameAdd, StripQuotes);

		for (auto item_equip_type : enchantment.to_item.indices())
		{
			ParseToken(it, enchantment.to_item[item_equip_type]);
		}

		enchantment.iTreasureLevel = 0;

		ParseToken(it, re_value_or_multiplier, [&](const auto& mr)
			{
				if (mr[1].matched)
				{
					Parse(mr[2], enchantment.iValue);
					enchantment.iTreasureLevel |= 0x04;
				}
				else
				{
					Parse(mr[3], enchantment.iValue);
				}
				return true;
			});

		std::string treasure_level;

		ParseToken(it, treasure_level, ToUpperInplace);

		enchantment.iTreasureLevel |= treasure_level[0] - 'A';
	}

	pSpecialEnchantments_count = pSpecialEnchantments.size();
}

void ItemTable::InitializeItems()
{
	static const std::regex re_number_or_dice_or_spell_or_message{ R"((\d+)|((\d+)d(\d+))|(([SM])(\d+)))", std::regex::optimize | std::regex::icase };

	using namespace MiniParser;

	const auto blob = pEvents_LOD->LoadCompressedTexture("items.txt");
	const auto blob_lines = Lines(blob.string_view());

	const auto data_lines = blob_lines | std::views::drop(2) | std::views::take(pItems.size());

	for (const auto& data_line : data_lines)
	{
		auto [it, it_end] { Tokenize(data_line) };

		ITEM_TYPE id;

		ParseToken(it, id);

		auto& item = pItems[id];

		ParseToken(it, item.pIconName);
		ParseToken(it, item.pName);
		ParseToken(it, item.uValue);
		ParseToken(it, item.uEquipType, equipStatMap, EQUIP_NONE);
		ParseToken(it, item.uSkillType, equipSkillMap, PLAYER_SKILL_MISC);
		ParseToken(it, re_number_or_dice_or_spell_or_message, [&](const auto& mr)
			{
				// either none or item-specific
				if (mr[1].matched)
				{
					Parse(mr[1], item.uDamageDice);
					item.uDamageRoll = std::min(uint8_t(1), item.uDamageDice);
					return true;
				}

				// damage
				if (mr[2].matched)
				{
					Parse(mr[3], item.uDamageDice);
					Parse(mr[4], item.uDamageRoll);
					return true;
				}

				// spell or message
				if (mr[5].matched)
				{
					switch (*mr[6].first)
					{
					case 'M':
					case 'S':
					case 'm':
					case 's':
						Parse(mr[7], item.uDamageDice);
						item.uDamageRoll = 2;
						break;
					}
					return true;
				}

				__debugbreak();
				return false;
			});
		ParseToken(it, item.uDamageMod);
		ParseToken(it, item.uMaterial, materialMap, MATERIAL_COMMON);
		ParseToken(it, item.uItemID_Rep_St);
		ParseToken(it, item.pUnidentifiedName, StripQuotes);
		ParseToken(it, item.uSpriteID);

		item._additional_value = 0;
		item._bonus_type = 0;

		std::string item_suffix;

		ParseToken(it, item_suffix);

		if (item.uMaterial == MATERIAL_SPECIAL)
		{
			for (int ii = 0; ii < 24; ++ii)
			{
				if (iequals(item_suffix, pEnchantments[ii].pOfName))
				{
					item._bonus_type = ii + 1;
					break;
				}
			}
			if (!item._bonus_type)
			{
				for (ITEM_ENCHANTMENT ii : pSpecialEnchantments.indices())
				{
					if (iequals(item_suffix, pSpecialEnchantments[ii].pNameAdd))
					{
						item._additional_value = ii;
						break;
					}
				}
			}
		}

		int item_bonus_strength;

		ParseToken(it, item_bonus_strength);

		if (item.uMaterial == MATERIAL_SPECIAL && item._bonus_type)
		{
			item._bonus_strength = std::max(item_bonus_strength, 1);
		}

		ParseToken(it, item.uEquipX);
		ParseToken(it, item.uEquipY);
		ParseToken(it, item.pDescription, StripQuotes);
	}
}

void ItemTable::InitializeRandomItems()
{
	static constexpr auto TreasureLevels = { ITEM_TREASURE_LEVEL_1, ITEM_TREASURE_LEVEL_2, ITEM_TREASURE_LEVEL_3, ITEM_TREASURE_LEVEL_4, ITEM_TREASURE_LEVEL_5, ITEM_TREASURE_LEVEL_6 };

	using namespace MiniParser;

	uChanceByTreasureLvlSumm.fill(0);

	const auto blob = pEvents_LOD->LoadCompressedTexture("rnditems.txt");
	const auto blob_lines = Lines(blob.string_view());

	std::size_t lines_parsed = 0;

	{
		const auto data_lines = blob_lines | std::views::drop(4);

		for (const auto& data_line : data_lines)
		{
			auto [it, it_end] { Tokenize(data_line) };

			if (it == it_end)
				break;

			ITEM_TYPE id;

			ParseToken(it, id);

			auto& item = pItems[id];

			SkipToken(it);

			for (auto treasure_level : TreasureLevels)
			{
				ParseToken(it, item.uChanceByTreasureLvl[treasure_level]);

				uChanceByTreasureLvlSumm[treasure_level] += item.uChanceByTreasureLvl[treasure_level];
			}

			++lines_parsed;
		}
	}

	{
		const auto data_lines = blob_lines | std::views::drop(4) | std::views::drop(lines_parsed) | std::views::drop(5) | std::views::take(3);

		std::size_t line = 0;

		for (const auto& data_line : data_lines)
		{
			auto [it, it_end] { Tokenize(data_line) };

			SkipToken(it);
			SkipToken(it);

			switch (line)
			{
			case 0:
				for (auto treasure_level : TreasureLevels)
				{
					ParseToken(it, uBonusChanceStandart[treasure_level]);
				}
				break;
			case 1:
				for (auto treasure_level : TreasureLevels)
				{
					ParseToken(it, uBonusChanceSpecial[treasure_level]);
				}
				break;
			case 2:
				for (auto treasure_level : TreasureLevels)
				{
					ParseToken(it, uBonusChanceWpSpecial[treasure_level]);
				}
				break;
			}

			++line;
		}
	}
}
