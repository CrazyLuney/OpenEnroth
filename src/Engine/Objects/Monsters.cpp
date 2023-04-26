#include "Engine/Objects/Monsters.h"

#include "Engine/Engine.h"
#include "Engine/Serialization/Deserializer.h"
#include "Engine/Serialization/Serializer.h"
#include "Engine/Serialization/LegacyImages.h"

#include "MonsterInfoParser/MonsterInfoParser.hpp"

#include "Utility/MiniParser.hpp"

#include "../LOD.h"
#include "../Tables/FrameTableInc.h"

struct MonsterStats* pMonsterStats;
struct MonsterList* pMonsterList;

//----- (004598AF) --------------------------------------------------------
void MonsterList::FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8)
{
	Assert(!data_mm6);
	Assert(!data_mm8);

	pMonsters.clear();

	if (data_mm6)
	{
		BlobDeserializer stream(data_mm6);
		stream.ReadLegacyVector<data::mm6::MonsterDesc>(&pMonsters, Deserializer::Append);
	}

	if (data_mm7)
	{
		BlobDeserializer stream(data_mm7);
		stream.ReadLegacyVector<data::mm7::MonsterDesc>(&pMonsters, Deserializer::Append);
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
	const auto blob = pEvents_LOD->LoadCompressedTexture("placemon.txt");
	const auto blob_view = blob.string_view();

	const auto data_view = MiniParser::SkipLines(blob_view, 1);

	auto [tokens_begin, tokens_end] { MiniParser::Tokenize(data_view) };

	for (auto it = tokens_begin; it != tokens_end; )
	{
		MonsterPlacementInfo info;

		MiniParser::ParseToken(it, info.uID);
		MiniParser::ParseToken(it, info.pName, MiniParser::TrimAndStripQuotes);

		pPlaceStrings.emplace_back(std::move(info));
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
