#include "Engine/Objects/Monsters.h"

#include "Engine/Engine.h"
#include "Engine/Serialization/Deserializer.h"
#include "Engine/Serialization/Serializer.h"
#include "Engine/Serialization/LegacyImages.h"

#include "MonsterInfoParser/MonsterInfoParser.hpp"


#include "../LOD.h"
#include "../Tables/FrameTableInc.h"


struct MonsterStats* pMonsterStats;
struct MonsterList* pMonsterList;

//----- (004598FC) --------------------------------------------------------
bool MonsterList::FromFileTxt(const char* Args)
{
	FILE* v3;               // eax@1
	unsigned int v4;        // esi@3
	void* v5;               // eax@9
	FILE* v6;               // ST14_4@11
	char* i;                // eax@11
	signed int v8;          // esi@12
	uint16_t v9;    // ax@16
	const char* v10;        // ST18_4@16
	uint16_t v11;   // ax@16
	const char* v12;        // ST14_4@16
	uint16_t v13;   // ax@16
	const char* v14;        // ST10_4@16
	int16_t v15;            // ax@16
	const char* v16;        // ST0C_4@16
	int v17;                // esi@16
	uint8_t v18;    // al@16
	signed int v19;         // esi@16
	uint16_t v20;   // ax@17
	int v21;                // ecx@17
	char Buf[490];           // [sp+4h] [bp-304h]@3
	FrameTableTxtLine v24;  // [sp+1F8h] [bp-110h]@4
	FrameTableTxtLine v25;  // [sp+274h] [bp-94h]@4
	int v26;                // [sp+2F0h] [bp-18h]@16
	FILE* File;             // [sp+304h] [bp-4h]@1
	unsigned int Argsa;     // [sp+310h] [bp+8h]@3
	int Argsb;              // [sp+310h] [bp+8h]@16

	v3 = fopen(Args, "r");
	File = v3;
	if (!v3) Error("MonsterRaceListStruct::load - Unable to open file: %s.");

	v4 = 0;
	Argsa = 0;
	if (fgets(Buf, sizeof(Buf), v3))
	{
		do
		{
			*strchr(Buf, 10) = 0;
			memcpy(&v25, frame_table_txt_parser(Buf, &v24), sizeof(v25));
			if (v25.uPropCount && *v25.pProperties[0] != 47) ++Argsa;
		} while (fgets(Buf, sizeof(Buf), File));
		v4 = Argsa;
	}

	this->pMonsters.clear();
	v6 = File;
	fseek(v6, 0, 0);
	for (i = fgets(Buf, sizeof(Buf), File); i; i = fgets(Buf, sizeof(Buf), File))
	{
		*strchr(Buf, 10) = 0;
		memcpy(&v25, frame_table_txt_parser(Buf, &v24), sizeof(v25));
		v8 = 0;
		if (v25.uPropCount && *v25.pProperties[0] != 47)
		{
			MonsterDesc& monster = this->pMonsters.emplace_back();

			monster.pMonsterName = v25.pProperties[0];

			constexpr std::array<std::pair<ActorAnimation, int>, 8> mapping = { {
				{ANIM_Standing, 1},
				{ANIM_Walking, 2},
				{ANIM_Bored, 3},
				{ANIM_AtkMelee, 4},
				{ANIM_AtkRanged, 4},
				{ANIM_GotHit, 5},
				{ANIM_Dying, 6},
				{ANIM_Dead, 7},
			} };

			do
			{
				monster.pSpriteNames[mapping[v8].first] = v25.pProperties[mapping[v8].second];
				++v8;
			} while (v8 < 8);
			v9 = atoi(v25.pProperties[8]);
			v10 = v25.pProperties[9];
			monster.uMonsterHeight = v9;
			v11 = atoi(v10);
			v12 = v25.pProperties[10];
			monster.uMovementSpeed = v11;
			v13 = atoi(v12);
			v14 = v25.pProperties[11];
			monster.uMonsterRadius = v13;
			v15 = atoi(v14);
			v16 = v25.pProperties[12];
			monster.uToHitRadius = v15;
			v17 = (uint8_t)atoi(v16);
			Argsb = atoi(v25.pProperties[13]) & 0xFF;
			v26 = atoi(v25.pProperties[14]) & 0xFF;
			v18 = atoi(v25.pProperties[15]);
			monster.sTintColor =
				v18 | ((v26 | ((Argsb | (v17 << 8)) << 8)) << 8);
			v19 = 0;
			do
			{
				v20 = atoi(v25.pProperties[v19 + 16]);
				v21 = v19++;
				monster.pSoundSampleIDs[v21] = v20;
			} while (v19 < 4);
		}
	}
	fclose(File);
	return 1;
}

//----- (004598AF) --------------------------------------------------------
void MonsterList::FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8)
{
	Assert(!data_mm8);

	if (data_mm7)
	{
		BlobDeserializer stream(data_mm7);
		stream.ReadLegacyVector<data::mm7::MonsterDesc>(&pMonsters);
	}

	if (data_mm6)
	{
		BlobDeserializer stream(data_mm6);
		stream.ReadLegacyVector<data::mm6::MonsterDesc>(&pMonsters, Deserializer::Append);
	}

	if (data_mm8)
	{
		BlobDeserializer stream(data_mm8);
		stream.ReadLegacyVector<data::mm8::MonsterDesc>(&pMonsters, Deserializer::Append);
	}

	Assert(!pMonsters.empty());
}

//----- (00459860) --------------------------------------------------------
void MonsterList::ToFile()
{
	FileSerializer stream(MakeDataPath("data", "dmonlist.bin"));
	stream.WriteLegacyVector<data::mm7::MonsterDesc>(this->pMonsters);
	stream.Close();
}

//----- (004563FF) --------------------------------------------------------
signed int MonsterStats::FindMonsterByTextureName(const char* monster_textr_name)
{
	auto it = std::find_if(std::begin(pInfos), std::end(pInfos), [=](const MonsterInfo& monster_info)
		{
			return !monster_info.pName.empty() && iequals(monster_info.pPictureName, monster_textr_name);
		});
	if (it == std::end(pInfos))
		return -1;

	return std::distance(std::begin(pInfos), it) + 1;
}

//----- (00454F4E) --------------------------------------------------------
void MonsterStats::InitializePlacements()
{
	using MonsterInfoParser::re_token_separator;

	auto blob = pEvents_LOD->LoadCompressedTexture("placemon.txt");
	auto blob_view = blob.string_view();
	auto data_view = Strings::SkipLines(blob_view, 1);

	using sv_regex_token_iterator = std::regex_token_iterator<std::string_view::iterator>;
	using sv_match_results = std::match_results<std::string_view::iterator>;

	auto tokens_begin = sv_regex_token_iterator(std::begin(data_view), std::end(data_view), re_token_separator);
	auto tokens_end = sv_regex_token_iterator();

	for (auto it = tokens_begin; it != tokens_end; )
	{
		MonsterPlacementInfo info;

		std::from_chars(std::to_address(it->first), std::to_address(it->second), info.uID);
		++it;
		info.pName.assign(it->first, it->second);
		++it;
	}
}

//----- (0045501E) --------------------------------------------------------
void MonsterStats::Initialize()
{
	const auto blob = pEvents_LOD->LoadCompressedTexture("monsters.txt");
	const auto blob_view = blob.string_view();
	const auto data_view = Strings::SkipLines(blob_view, 4);

	auto OnMonsterInfoReady = [this](MonsterInfo&& monster_info)
	{
		pInfos.emplace_back(std::move(monster_info));
	};

	if (MonsterInfoParser::Parser(OnMonsterInfoReady).Parse(data_view))
	{

	}
	else
	{
		__debugbreak();
		Error("Failed to parse monsters.txt!");
	}
}

//----- (0044FA08) --------------------------------------------------------
int16_t MonsterList::GetMonsterIDByName(const char* pMonsterName)
{
	if (!pMonsterName) return -1;
	for (int16_t i = 0; i < pMonsters.size(); ++i)
	{
		if (iequals(pMonsters[i].pMonsterName, pMonsterName))
			return i;
	}
	Error("Monster not found: %s", pMonsterName);
}
//----- (00438BDF) --------------------------------------------------------
bool MonsterStats::BelongsToSupertype(unsigned int uMonsterInfoID,
	enum MONSTER_SUPERTYPE eSupertype)
{
	switch (eSupertype)
	{
	case MONSTER_SUPERTYPE_UNDEAD:
		if ((signed int)uMonsterInfoID >= MONSTER_GHOST_1 &&
			(signed int)uMonsterInfoID <= MONSTER_GHOST_3  // 70<=id<=72
			|| (signed int)uMonsterInfoID >= MONSTER_LICH_1 &&
			(signed int)uMonsterInfoID <= MONSTER_LICH_3  // 91-93
			||
			(signed int)uMonsterInfoID >= MONSTER_SKELETON_1 &&
			(signed int)uMonsterInfoID <= MONSTER_SKELETON_3  // 199-201
			||
			(signed int)uMonsterInfoID >= MONSTER_VAMPIRE_1 &&
			(signed int)uMonsterInfoID <= MONSTER_VAMPIRE_3  // 217-219
			|| (signed int)uMonsterInfoID >= MONSTER_WIGHT_1 &&
			(signed int)uMonsterInfoID <= MONSTER_WIGHT_3  // 223-225
			||
			(signed int)uMonsterInfoID >= MONSTER_ZOMBIE_1 &&
			(signed int)uMonsterInfoID <= MONSTER_ZOMBIE_3  // 229-231
			||
			(signed int)uMonsterInfoID >= MONSTER_GHOUL_1 &&
			(signed int)uMonsterInfoID <= MONSTER_GHOUL_3)  // 256-258
			return true;
		return false;
	case MONSTER_SUPERTYPE_KREEGAN:
		if ((signed int)uMonsterInfoID >= MONSTER_DEVIL_1 &&
			(signed int)uMonsterInfoID <= MONSTER_DEVIL_3)  // 22-24
			return true;
		return false;
	case MONSTER_SUPERTYPE_ELF:
		if ((signed int)uMonsterInfoID >= MONSTER_PEASANT_ELF_FEMALE_1_1 &&
			(signed int)uMonsterInfoID <=
			MONSTER_PEASANT_ELF_MALE_3_3  // 133 - 150
			||
			(signed int)uMonsterInfoID >= MONSTER_ELF_ARCHER_1 &&
			(signed int)uMonsterInfoID <= MONSTER_ELF_ARCHER_3  // 49-51
			|| (signed int)uMonsterInfoID >= MONSTER_ELF_SPEARMAN_1 &&
			(signed int)uMonsterInfoID <=
			MONSTER_ELF_SPEARMAN_3)  // 52-54
			return true;
		return false;
	case MONSTER_SUPERTYPE_DRAGON:
		if ((signed int)uMonsterInfoID >= MONSTER_DRAGON_1 &&
			(signed int)uMonsterInfoID <= MONSTER_DRAGON_3)  // 25-27
			return true;
		return false;
	case MONSTER_SUPERTYPE_WATER_ELEMENTAL:
		if ((signed int)uMonsterInfoID >= MONSTER_ELEMENTAL_WATER_1 &&
			(signed int)uMonsterInfoID <=
			MONSTER_ELEMENTAL_WATER_3)  // 46-48
			return true;
		return false;
	case MONSTER_SUPERTYPE_TREANT:
		if ((signed int)uMonsterInfoID >= MONSTER_TREANT_1 &&
			(signed int)uMonsterInfoID <= MONSTER_TREANT_3)  // 253-255
			return true;
		return false;
	case MONSTER_SUPERTYPE_TITAN:
		if ((signed int)uMonsterInfoID >= MONSTER_TITAN_1 &&
			(signed int)uMonsterInfoID <= MONSTER_TITAN_3)  // 211-213
			return true;
		return false;
	default:
		return false;
	}
	return false;
}
