#include "Engine/Engine.h"
#include "Engine/LOD.h"
#include "Engine/Localization.h"
#include "Utility/MiniParser.hpp"

Localization* localization = nullptr;

const char* Localization::GetString(unsigned int index) const
{
	Assert(index < localization_strings.size());
	return localization_strings[index].c_str();
}

std::string Localization::FormatString(unsigned int index, ...) const
{
	va_list args_ptr;

	const char* format = GetString(index);
	char buf[2048];

	va_start(args_ptr, index);  // ?? sometimes args_ptr has junk at start ??
	// args must pass as type c_str() ??
	vsprintf(buf, format, args_ptr);
	va_end(args_ptr);

	extern int sprintfex_internal(char* str);
	sprintfex_internal(buf);
	return std::string(buf);
}

//----- (00452C49) --------------------------------------------------------
bool Localization::Initialize()
{
	localization_strings.resize(MAX_LOC_STRINGS);

	{
		auto blob = pEvents_LOD->LoadCompressedTexture("global.txt");
		auto blob_view = blob.string_view();

		auto data_view = MiniParser::SkipLines(blob_view, 2);

		auto [tokens_begin, tokens_end] = MiniParser::Tokenize(data_view);

		for (auto it = tokens_begin; it != tokens_end; )
		{
			std::size_t id;

			MiniParser::ParseToken(it, id);
			MiniParser::ParseToken(it, localization_strings[id], MiniParser::StripQuotes);
		}
	}

	// TODO: should be moved to localization files eventually
	if (localization_strings[LSTR_FMT_S_STOLE_D_ITEM].empty())
		localization_strings[LSTR_FMT_S_STOLE_D_ITEM] = "%s stole %s!";
	if (localization_strings[LSTR_FMT_RECOVERY_TIME_D].empty())
		localization_strings[LSTR_FMT_RECOVERY_TIME_D] = "Recovery time: %d";
	if (localization_strings[LSTR_FMT_S_U_OUT_OF_U].empty())
		localization_strings[LSTR_FMT_S_U_OUT_OF_U] = "%s: %lu out of %lu";
	if (localization_strings[LSTR_NOBODY_IS_IN_CONDITION].empty())
		localization_strings[LSTR_NOBODY_IS_IN_CONDITION] = "Nobody is in a condition to do anything!";
	if (localization_strings[LSTR_KEY_CONFLICT].empty())
		localization_strings[LSTR_KEY_CONFLICT] = "Please resolve all key conflicts!";

	InitializeMm6ItemCategories();

	InitializeMonthNames();
	InitializeDayNames();
	InitializeMoonPhaseNames();

	InitializeClassNames();
	InitializeAttributeNames();
	InitializeSkillNames();
	InitializeCharacterConditionNames();

	InitializeSpellSchoolNames();
	InitializeSpellNames();

	InitializeNpcProfessionNames();

	return true;
}

void Localization::InitializeSpellNames()
{
	spell_names[0] = GetString(202);  // Protection from Air
	spell_names[1] = GetString(204);
	spell_names[2] = GetString(219);
	spell_names[3] = GetString(215);
	spell_names[4] = GetString(208);
	spell_names[5] = GetString(454);  // Feather Fall
	spell_names[6] = GetString(24);
	spell_names[7] = GetString(455);
	spell_names[8] = GetString(441);
	spell_names[9] = GetString(440);
	spell_names[10] = GetString(218);  // Ring of Fire
	spell_names[11] = GetString(217);
	spell_names[12] = GetString(213);
	spell_names[13] = GetString(462);
	spell_names[14] = GetString(279);
	spell_names[15] = GetString(442);  // Stoneskin
	spell_names[16] = GetString(452);
	spell_names[17] = GetString(194);
	spell_names[18] = GetString(456);
	spell_names[19] = GetString(453);
	spell_names[20] = GetString(202);  // Protection from Air
	spell_names[21] = GetString(443);
	spell_names[22] = GetString(204);
	spell_names[23] = GetString(208);
	spell_names[24] = GetString(221);
	spell_names[25] = GetString(24);  // Protection from Fire
	spell_names[26] = GetString(228);
	spell_names[27] = GetString(441);
	spell_names[28] = GetString(440);
	spell_names[29] = GetString(213);
	spell_names[30] = GetString(229);  // Pain Reflection
	spell_names[31] = GetString(233);
	spell_names[32] = GetString(234);
	spell_names[33] = GetString(279);
	spell_names[34] = GetString(442);
	spell_names[35] = GetString(235);  // Temporary Accuracy
	spell_names[36] = GetString(246);
	spell_names[37] = GetString(247);
	spell_names[38] = GetString(248);
	spell_names[39] = GetString(674);
	spell_names[40] = GetString(249);  // Temporary Willpower
	spell_names[41] = GetString(258);
	spell_names[42] = GetString(194);
	spell_names[43] = GetString(657);  // Water Breathing
}

void Localization::InitializeNpcProfessionNames()
{
	npc_profession_names[NoProfession] = GetString(153);  // Nothing
	npc_profession_names[Smith] = GetString(308);  // smith
	npc_profession_names[Armorer] = GetString(309);  // armsmaster // TODO(captainurist): the comment is off here, investigate
	npc_profession_names[Alchemist] = GetString(7);  // alchemist
	npc_profession_names[Scholar] = GetString(306);
	npc_profession_names[Guide] = GetString(310);
	npc_profession_names[Tracker] = GetString(311);
	npc_profession_names[Pathfinder] = GetString(312);
	npc_profession_names[Sailor] = GetString(313);
	npc_profession_names[Navigator] = GetString(314);
	npc_profession_names[Healer] = GetString(105);
	npc_profession_names[ExpertHealer] = GetString(315);
	npc_profession_names[MasterHealer] = GetString(316);
	npc_profession_names[Teacher] = GetString(317);
	npc_profession_names[Instructor] = GetString(115);
	npc_profession_names[Armsmaster] = GetString(318);
	npc_profession_names[Weaponsmaster] = GetString(319);
	npc_profession_names[Apprentice] = GetString(320);
	npc_profession_names[Mystic] = GetString(321);
	npc_profession_names[Spellmaster] = GetString(322);
	npc_profession_names[Trader] = GetString(323);
	npc_profession_names[Merchant] = GetString(293);
	npc_profession_names[Scout] = GetString(324);
	npc_profession_names[Herbalist] = GetString(498);
	npc_profession_names[Apothecary] = GetString(525);
	npc_profession_names[Tinker] = GetString(327);
	npc_profession_names[Locksmith] = GetString(328);
	npc_profession_names[Fool] = GetString(329);
	npc_profession_names[ChimneySweep] = GetString(330);
	npc_profession_names[Porter] = GetString(331);
	npc_profession_names[QuarterMaster] = GetString(332);
	npc_profession_names[Factor] = GetString(333);
	npc_profession_names[Banker] = GetString(334);
	npc_profession_names[Cook] = GetString(335);
	npc_profession_names[Chef] = GetString(336);
	npc_profession_names[Horseman] = GetString(337);
	npc_profession_names[Bard] = GetString(338);
	npc_profession_names[Enchanter] = GetString(339);
	npc_profession_names[Cartographer] = GetString(340);
	npc_profession_names[WindMaster] = GetString(341);
	npc_profession_names[WaterMaster] = GetString(342);
	npc_profession_names[GateMaster] = GetString(343);
	npc_profession_names[Acolyte] = GetString(596);
	npc_profession_names[Piper] = GetString(345);
	npc_profession_names[Explorer] = GetString(346);
	npc_profession_names[Pirate] = GetString(347);
	npc_profession_names[Squire] = GetString(348);
	npc_profession_names[Psychic] = GetString(349);
	npc_profession_names[Gypsy] = GetString(350);
	npc_profession_names[Diplomat] = GetString(597);
	npc_profession_names[Duper] = GetString(352);
	npc_profession_names[Burglar] = GetString(353);
	npc_profession_names[FallenWizard] = GetString(598);
	npc_profession_names[Acolyte2] = GetString(344);
	npc_profession_names[Initiate] = GetString(26);
	npc_profession_names[Prelate] = GetString(599);
	npc_profession_names[Monk] = GetString(21);
	npc_profession_names[Sage] = GetString(600);
	npc_profession_names[Hunter] = GetString(370);
}

void Localization::InitializeCharacterConditionNames()
{
	character_conditions[0] = GetString(52);  // Cursed
	character_conditions[1] = GetString(241);
	character_conditions[2] = GetString(14);   // Asleep
	character_conditions[3] = GetString(4);    // Fear
	character_conditions[4] = GetString(69);   // Drunk
	character_conditions[5] = GetString(117);  // Insane
	character_conditions[6] = GetString(166);                             // Poisoned
	character_conditions[7] = GetString(65);  // Diseased
	character_conditions[8] = GetString(166);                             // Poisoned
	character_conditions[9] = GetString(65);  // Diseased
	character_conditions[10] = GetString(166);  // Poisoned
	character_conditions[11] = GetString(65);  // Diseased
	character_conditions[12] = GetString(162);  // Paralyzed
	character_conditions[13] = GetString(231);  // Unconcious
	character_conditions[14] = GetString(58);  // Dead
	character_conditions[15] = GetString(220);  // Pertified
	character_conditions[16] = GetString(76);  // Eradicated
	character_conditions[17] = GetString(601);  // Zombie
	character_conditions[18] = GetString(98);   // Good
}

void Localization::InitializeSkillNames()
{
	skill_names[PLAYER_SKILL_STAFF] = GetString(271);  // Staff
	skill_names[PLAYER_SKILL_SWORD] = GetString(272);
	skill_names[PLAYER_SKILL_DAGGER] = GetString(273);
	skill_names[PLAYER_SKILL_AXE] = GetString(274);
	skill_names[PLAYER_SKILL_SPEAR] = GetString(275);
	skill_names[PLAYER_SKILL_BOW] = GetString(276);  // Bow
	skill_names[PLAYER_SKILL_MACE] = GetString(277);
	skill_names[PLAYER_SKILL_BLASTER] = GetString(278);
	skill_names[PLAYER_SKILL_SHIELD] = GetString(279);
	skill_names[PLAYER_SKILL_LEATHER] = GetString(280);
	skill_names[PLAYER_SKILL_CHAIN] = GetString(281);  // Chain
	skill_names[PLAYER_SKILL_PLATE] = GetString(282);
	skill_names[PLAYER_SKILL_FIRE] = GetString(283);
	skill_names[PLAYER_SKILL_AIR] = GetString(284);
	skill_names[PLAYER_SKILL_WATER] = GetString(285);
	skill_names[PLAYER_SKILL_EARTH] = GetString(286);  // Earth
	skill_names[PLAYER_SKILL_SPIRIT] = GetString(289);
	skill_names[PLAYER_SKILL_MIND] = GetString(290);
	skill_names[PLAYER_SKILL_BODY] = GetString(291);
	skill_names[PLAYER_SKILL_LIGHT] = GetString(287);
	skill_names[PLAYER_SKILL_DARK] = GetString(288);  // Dark
	skill_names[PLAYER_SKILL_ITEM_ID] = GetString(292);
	skill_names[PLAYER_SKILL_MERCHANT] = GetString(293);
	skill_names[PLAYER_SKILL_REPAIR] = GetString(294);
	skill_names[PLAYER_SKILL_BODYBUILDING] = GetString(295);
	skill_names[PLAYER_SKILL_MEDITATION] = GetString(296);  // Meditation
	skill_names[PLAYER_SKILL_PERCEPTION] = GetString(297);
	skill_names[PLAYER_SKILL_DIPLOMACY] = GetString(298);
	skill_names[PLAYER_SKILL_THIEVERY] = GetString(299);
	skill_names[PLAYER_SKILL_TRAP_DISARM] = GetString(300);
	skill_names[PLAYER_SKILL_DODGE] = GetString(50);  // Dodge
	skill_names[PLAYER_SKILL_UNARMED] = GetString(77);
	skill_names[PLAYER_SKILL_MONSTER_ID] = GetString(88);
	skill_names[PLAYER_SKILL_ARMSMASTER] = GetString(89);
	skill_names[PLAYER_SKILL_STEALING] = GetString(90);
	skill_names[PLAYER_SKILL_ALCHEMY] = GetString(95);  // Alchemy
	skill_names[PLAYER_SKILL_LEARNING] = GetString(301);
	skill_names[PLAYER_SKILL_INVALID] = GetString(153); // "None", used during character creation.

	// TODO(captainurist): Not currently used anywhere
	// skill_names[PLAYER_SKILL_CLUB]        = GetString(568);
	// skill_descriptions[PLAYER_SKILL_CLUB] = "Everyone is able to wield a club without any prior training and bonk anything with it. "
	//    "But there is not much room to improve finesse or mastery for such a rudimentary weapon though. "
	//    "So don't expect to become thwonking killer and devastating anyone beyond weaklings.";

	{
		auto blob = pEvents_LOD->LoadCompressedTexture("skilldes.txt");
		auto blob_view = blob.string_view();

		auto data_view = MiniParser::SkipLines(blob_view, 1);

		auto [tokens_begin, tokens_end] { MiniParser::Tokenize(data_view) };

		auto it_skill = std::begin(VisibleSkills());
		auto it_skill_end = std::end(VisibleSkills());
		for (auto it = tokens_begin; it != tokens_end && it_skill != it_skill_end; ++it_skill)
		{
			MiniParser::SkipToken(it);
			MiniParser::ParseToken(it, skill_descriptions[*it_skill], MiniParser::StripQuotes);
			MiniParser::ParseToken(it, skill_descriptions_normal[*it_skill], MiniParser::StripQuotes);
			MiniParser::ParseToken(it, skill_descriptions_expert[*it_skill], MiniParser::StripQuotes);
			MiniParser::ParseToken(it, skill_descriptions_master[*it_skill], MiniParser::StripQuotes);
			MiniParser::ParseToken(it, skill_descriptions_grand[*it_skill], MiniParser::StripQuotes);
		}
	}
}

void Localization::InitializeClassNames()
{
	class_names[0] = GetString(253);  // Knight
	class_names[1] = GetString(254);  // Cavalier
	class_names[2] = GetString(255);  // Champion
	class_names[3] = GetString(2);    // Black Knight

	class_names[4] = GetString(307);  // Thief
	class_names[5] = GetString(114);  // Rogue
	class_names[6] = GetString(3);    // Spy
	class_names[7] = GetString(13);   // Assassin

	class_names[8] = GetString(21);    // Monk
	class_names[9] = GetString(26);    // Initiate
	class_names[10] = GetString(432);  // Master
	class_names[11] = GetString(27);   // Ninja

	class_names[12] = GetString(262);  // Paladin
	class_names[13] = GetString(263);  // Crusader
	class_names[14] = GetString(264);  // Hero
	class_names[15] = GetString(28);   // Villian

	class_names[16] = GetString(265);  // Archer
	class_names[17] = GetString(267);  // Battle Mage
	class_names[18] = GetString(119);
	class_names[19] = GetString(124);  // Sniper

	class_names[20] = GetString(31);   // Ranger
	class_names[21] = GetString(370);  // Hunter
	class_names[22] = GetString(33);   // Ranger Lord
	class_names[23] = GetString(40);

	class_names[24] = GetString(256);  // Cleric
	class_names[25] = GetString(257);
	class_names[26] = GetString(44);
	class_names[27] = GetString(46);

	class_names[28] = GetString(268);  // Druid
	class_names[29] = GetString(269);
	class_names[30] = GetString(270);
	class_names[31] = GetString(48);  // Warlock

	class_names[32] = GetString(259);  // Sorcerer
	class_names[33] = GetString(260);  // Wizard
	class_names[34] = GetString(261);  // Archmage
	class_names[35] = GetString(49);   // Lich

	{
		auto blob = pEvents_LOD->LoadCompressedTexture("class.txt");
		auto blob_view = blob.string_view();

		auto data_view = MiniParser::SkipLines(blob_view, 1);

		auto [tokens_begin, tokens_end] { MiniParser::Tokenize(data_view) };

		const auto classes_range = std::ranges::views::iota(std::size_t(0), class_descriptions.size());
		auto it_class = std::begin(classes_range);
		auto it_class_end = std::end(classes_range);
		for (auto it = tokens_begin; it != tokens_end && it_class != it_class_end; ++it_class)
		{
			MiniParser::SkipToken(it);
			MiniParser::ParseToken(it, class_descriptions[*it_class], MiniParser::StripQuotes);
			MiniParser::SkipToken(it);
		}
	}
}

//----- (00452B95) --------------------------------------------------------
void Localization::InitializeMm6ItemCategories()
{
	mm6_item_categories[0] = GetString(568);  // Club
	mm6_item_categories[1] = GetString(271);  // Staff
	mm6_item_categories[2] = GetString(272);  // Sword
	mm6_item_categories[3] = GetString(273);  // Dagger
	mm6_item_categories[4] = GetString(274);  // Axe
	mm6_item_categories[5] = GetString(275);  // Spear
	mm6_item_categories[6] = GetString(276);  // Bow
	mm6_item_categories[7] = GetString(277);  // Mace
	mm6_item_categories[8] = GetString(278);  // Blaster
	mm6_item_categories[9] = GetString(279);  // Shield
	mm6_item_categories[10] = GetString(280);  // Leather armour
	mm6_item_categories[11] = GetString(281);  // Chainmail
	mm6_item_categories[12] = GetString(282);  // Plate armour
	mm6_item_categories[13] = GetString(143);  // Other
}

//----- (00413FF1) --------------------------------------------------------
void Localization::InitializeMonthNames()
{
	month_names[0] = GetString(415);  // january
	month_names[1] = GetString(416);
	month_names[2] = GetString(417);
	month_names[3] = GetString(418);
	month_names[4] = GetString(419);
	month_names[5] = GetString(420);
	month_names[6] = GetString(421);
	month_names[7] = GetString(422);
	month_names[8] = GetString(423);
	month_names[9] = GetString(424);
	month_names[10] = GetString(425);
	month_names[11] = GetString(426);  // december
}

//----- (0041406F) --------------------------------------------------------
void Localization::InitializeDayNames()
{
	day_names[0] = GetString(145);  // monday
	day_names[1] = GetString(230);
	day_names[2] = GetString(243);
	day_names[3] = GetString(227);
	day_names[4] = GetString(91);
	day_names[5] = GetString(188);
	day_names[6] = GetString(222);  // sunday
}

//----- (004140BB) --------------------------------------------------------
void Localization::InitializeSpellSchoolNames()
{
	spell_school_names[0] = GetString(87);   // Fire
	spell_school_names[1] = GetString(6);    // Air
	spell_school_names[2] = GetString(240);  // Water
	spell_school_names[3] = GetString(70);   // Earth
	spell_school_names[4] = GetString(142);  // Mind
	spell_school_names[5] = GetString(214);  // Spirit
	spell_school_names[6] = GetString(29);   // Body
	spell_school_names[7] = GetString(133);  // Light
	spell_school_names[8] = GetString(54);   // Dark
}

//----- (0041411B) --------------------------------------------------------
void Localization::InitializeAttributeNames()
{
	attribute_names[TEMP_ATTRIBUTE_MIGHT] = GetString(LSTR_MIGHT);
	attribute_names[TEMP_ATTRIBUTE_INTELLECT] = GetString(LSTR_INTELLECT);
	attribute_names[TEMP_ATTRIBUTE_PERSONALITY] = GetString(LSTR_PERSONALITY);
	attribute_names[TEMP_ATTRIBUTE_ENDURANCE] = GetString(LSTR_ENDURANCE);
	attribute_names[TEMP_ATTRIBUTE_ACCURACY] = GetString(LSTR_ACCURACY);
	attribute_names[TEMP_ATTRIBUTE_SPEED] = GetString(LSTR_SPEED);
	attribute_names[TEMP_ATTRIBUTE_LUCK] = GetString(LSTR_LUCK);
	attribute_names[TEMP_ATTRIBUTE_HIT_POINTS] = GetString(LSTR_HIT_POINTS);
	attribute_names[TEMP_ATTRIBUTE_ARMOR_CLASS] = GetString(LSTR_AC);
	attribute_names[TEMP_ATTRIBUTE_SPELL_POINTS] = GetString(LSTR_SPELL_POINTS);
	attribute_names[TEMP_ATTRIBUTE_CONDITION] = GetString(LSTR_CONDITION);
	attribute_names[TEMP_ATTRIBUTE_QUICK_SPELL] = GetString(LSTR_QUICK_SPELL);
	attribute_names[TEMP_ATTRIBUTE_AGE] = GetString(LSTR_AGE);
	attribute_names[TEMP_ATTRIBUTE_LEVEL] = GetString(LSTR_LEVEL);
	attribute_names[TEMP_ATTRIBUTE_EXPERIENCE] = GetString(LSTR_EXPERIENCE);
	attribute_names[TEMP_ATTRIBUTE_ATTACK_BONUS] = GetString(LSTR_ATTACK_BONUS);
	attribute_names[TEMP_ATTRIBUTE_ATTACK_DAMAGE] = GetString(LSTR_ATTACK_DAMAGE);
	attribute_names[TEMP_ATTRIBUTE_SHOOT_BONUS] = GetString(LSTR_SHOOT_BONUS);
	attribute_names[TEMP_ATTRIBUTE_SHOOT_DAMAGE] = GetString(LSTR_SHOOT_DAMAGE);
	attribute_names[TEMP_ATTRIBUTE_FIRE] = GetString(LSTR_FIRE);
	attribute_names[TEMP_ATTRIBUTE_AIR] = GetString(LSTR_AIR);
	attribute_names[TEMP_ATTRIBUTE_WATER] = GetString(LSTR_WATER);
	attribute_names[TEMP_ATTRIBUTE_EARTH] = GetString(LSTR_EARTH);
	attribute_names[TEMP_ATTRIBUTE_MIND] = GetString(LSTR_MIND);
	attribute_names[TEMP_ATTRIBUTE_BODY] = GetString(LSTR_BODY);
	attribute_names[TEMP_ATTRIBUTE_SKILL_POINTS] = GetString(LSTR_SKILL_POINTS);

	{
		auto blob = pEvents_LOD->LoadCompressedTexture("stats.txt");
		auto blob_view = blob.string_view();

		auto data_view = MiniParser::SkipLines(blob_view, 1);

		auto [tokens_begin, tokens_end] { MiniParser::Tokenize(data_view) };

		const auto attributes_range = std::ranges::views::iota(std::size_t(0), attribute_descriptions.size());
		auto it_attribute = std::begin(attributes_range);
		auto it_attribute_end = std::end(attributes_range);
		for (auto it = tokens_begin; it != tokens_end && it_attribute != it_attribute_end; ++it_attribute)
		{
			MiniParser::SkipToken(it);
			MiniParser::ParseToken(it, attribute_descriptions[*it_attribute], MiniParser::StripQuotes);
		}
	}
}

//----- (00410AF5) --------------------------------------------------------
void Localization::InitializeMoonPhaseNames()
{
	moon_phase_names[0] = GetString(150);
	moon_phase_names[1] = GetString(171);
	moon_phase_names[2] = GetString(102);
	moon_phase_names[3] = GetString(169);
	moon_phase_names[4] = GetString(92);
}
