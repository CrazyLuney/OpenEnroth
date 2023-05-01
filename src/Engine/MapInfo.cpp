#include "Engine/MapInfo.h"

#include "Engine/Engine.h"
#include "Engine/Graphics/Indoor.h"
#include "Engine/LOD.h"
#include "Engine/Objects/ItemTable.h"
#include "Engine/Objects/ObjectList.h"
#include "Engine/Objects/SpriteObject.h"
#include "Engine/Graphics/DecorationList.h"
#include "Engine/Graphics/Level/Decoration.h"

#include "Library/Serialization/EnumSerialization.h"

#include "Library/Random/Random.h"
#include "Utility/Math/TrigLut.h"

#include "OurMath.h"
#include "Party.h"

#include "Engine/TextParsers/SymbolMatcher/SymbolMatcherMiniParser.hpp"

namespace
{
	using SymbolMatcher::Symbol;

	static const std::map<Symbol, uint8_t> EAXEnvMap
	{
		{ Symbol::GENERIC, 0 },
		{ Symbol::PADDEDCELL, 1 },
		{ Symbol::ROOM, 2 },
		{ Symbol::BATHROOM, 3 },
		{ Symbol::LIVINGROOM, 4 },
		{ Symbol::STONEROOM, 5 },
		{ Symbol::AUDITORIUM, 6 },
		{ Symbol::CONCERTHALL, 7 },
		{ Symbol::CAVE, 8 },
		{ Symbol::ARENA, 9 },
		{ Symbol::HANGAR, 10 },
		{ Symbol::CARPETEDHALLWAY, 11 },
		{ Symbol::HALLWAY, 12 },
		{ Symbol::STONECORRIDOR, 13 },
		{ Symbol::ALLEY, 14 },
		{ Symbol::FOREST, 15 },
		{ Symbol::CITY, 16 },
		{ Symbol::MOUNTAIN, 17 },
		{ Symbol::QUARRY, 18 },
		{ Symbol::PLAINS, 19 },
		{ Symbol::PARKINGLOT, 20 },
		{ Symbol::SEWERPIPE, 21 },
		{ Symbol::UNDERWATER, 22 },
		{ Symbol::DRUGGED, 23 },
		{ Symbol::DIZZY, 24 },
		{ Symbol::PSYCHOTIC, 25 },
	};
}

void MapStats::Initialize()
{
	using namespace MiniParser;

	uNumMaps = 0;

	const auto blob = pEvents_LOD->LoadCompressedTexture("MapStats.txt");

	for (const auto& data_line : GetLines(blob.string_view()) | std::views::drop(3) | std::views::take(std::size(pInfos)))
	{
		auto tokens = GetTokens(data_line);
		auto it = std::begin(tokens);

		{
			std::size_t id;

			ParseToken(it, id);

			auto& map_info = pInfos[id];

			ParseToken(it, map_info.pName, StripQuotes);
			ParseToken(it, map_info.pFilename, StripQuotes, ToLowerInplace);
			ParseToken(it, map_info.uNumResets);
			ParseToken(it, map_info.uFirstVisitedAt);
			ParseToken(it, map_info._per);
			ParseToken(it, map_info.uRespawnIntervalDays);
			ParseToken(it, map_info._alert_days);
			ParseToken(it, map_info._steal_perm);
			ParseToken(it, map_info.LockX5);
			ParseToken(it, map_info.Trap_D20);
			ParseToken(it, map_info.Treasure_prob);
			ParseToken(it, map_info.Encounter_percent);
			ParseToken(it, map_info.EncM1percent);
			ParseToken(it, map_info.EncM2percent);
			ParseToken(it, map_info.EncM3percent);
			ParseToken(it, map_info.pEncounterMonster1Texture, StripQuotes);
			DropToken(it);
			ParseToken(it, map_info.Dif_M1);
			ParseTokenSymbol(it, [&minimum = map_info.uEncounterMonster1AtLeast, &maximum = map_info.uEncounterMonster1AtMost](const auto& match)
				{
					switch (match.symbol)
					{
					case Symbol::ENCOUNTERRANGE:
						SymbolParsers::ParseEncounterRange(match.value, minimum, maximum);
						break;
					case Symbol::INTEGER:
						Parse(match.value, minimum);
						maximum = minimum;
						break;
					default:
						__debugbreak();
						return false;
					}
					return true;
				}, Trim);
			ParseToken(it, map_info.pEncounterMonster2Texture, StripQuotes);
			DropToken(it);
			ParseToken(it, map_info.Dif_M2);
			ParseTokenSymbol(it, [&minimum = map_info.uEncounterMonster2AtLeast, &maximum = map_info.uEncounterMonster2AtMost](const auto& match)
				{
					switch (match.symbol)
					{
					case Symbol::ENCOUNTERRANGE:
						SymbolParsers::ParseEncounterRange(match.value, minimum, maximum);
						break;
					case Symbol::INTEGER:
						Parse(match.value, minimum);
						maximum = minimum;
						break;
					default:
						__debugbreak();
						return false;
					}
					return true;
				}, Trim);
			ParseToken(it, map_info.pEncounterMonster3Texture, StripQuotes);
			DropToken(it);
			ParseToken(it, map_info.Dif_M3);
			ParseTokenSymbol(it, [&minimum = map_info.uEncounterMonster3AtLeast, &maximum = map_info.uEncounterMonster3AtMost](const auto& match)
				{
					switch (match.symbol)
					{
					case Symbol::ENCOUNTERRANGE:
						SymbolParsers::ParseEncounterRange(match.value, minimum, maximum);
						break;
					case Symbol::INTEGER:
						Parse(match.value, minimum);
						maximum = minimum;
						break;
					default:
						__debugbreak();
						return false;
					}
					return true;
				}, Trim);
			ParseToken(it, map_info.uRedbookTrackID);
			ParseTokenSymbol(it, map_info.uEAXEnv, EAXEnvMap, static_cast<uint8_t>(std::size(EAXEnvMap)));
		}

		++uNumMaps;
	}
}

int MapStats::sub_410D99_get_map_index(int a1)
{
	std::string name = pGames_LOD->GetSubNodeName(a1);

	for (int i = 1; i <= pMapStats->uNumMaps; i++)
	{
		if (pMapStats->pInfos[i].pFilename == name)
		{
			return i;
		}
	}
	Error("Map not found");
	return -1;
}

MAP_TYPE MapStats::GetMapInfo(const std::string& Str2)
{
	Assert(uNumMaps >= 2);

	std::string map_name = toLower(Str2);

	for (uint i = 1; i < uNumMaps; ++i)
	{
		if (pInfos[i].pFilename == map_name)
		{
			return (MAP_TYPE)i;
		}
	}

	Error("Map not found!");
	return (MAP_TYPE)-1;  // @TODO: This should be MAP_INVALID!, as it's if'ed later.
}

void MapInfo::SpawnRandomTreasure(SpawnPoint* a2)
{
	Assert(a2->uKind == OBJECT_Item);

	SpriteObject a1a;
	a1a.containing_item.Reset();

	int v34 = 0;
	int v5 = grng->random(100);
	ITEM_TREASURE_LEVEL v13 = grng->randomSample(RemapTreasureLevel(a2->uItemIndex, Treasure_prob));
	if (v13 != ITEM_TREASURE_LEVEL_GUARANTEED_ARTIFACT)
	{
		// [0, 20) -- nothing
		// [20, 60) -- gold
		// [60, 100) -- item

		if (v5 < 20)
			return;

		if (v5 >= 60)
		{
			DropTreasureAt(v13, grng->random(27) + 20, a2->vPosition.x,
				a2->vPosition.y,
				a2->vPosition.z, 0);
			return;
		}

		if (a2->uItemIndex == ITEM_TREASURE_LEVEL_1)
		{
			a1a.containing_item.uItemID = ITEM_GOLD_SMALL;
			v34 = grng->random(51) + 50;
		}
		else if (a2->uItemIndex == ITEM_TREASURE_LEVEL_2)
		{
			a1a.containing_item.uItemID = ITEM_GOLD_SMALL;
			v34 = grng->random(101) + 100;
		}
		else if (a2->uItemIndex == ITEM_TREASURE_LEVEL_3)
		{
			a1a.containing_item.uItemID = ITEM_GOLD_MEDIUM;
			v34 = grng->random(301) + 200;
		}
		else if (a2->uItemIndex == ITEM_TREASURE_LEVEL_4)
		{
			a1a.containing_item.uItemID = ITEM_GOLD_MEDIUM;
			v34 = grng->random(501) + 500;
		}
		else if (a2->uItemIndex == ITEM_TREASURE_LEVEL_5)
		{
			a1a.containing_item.uItemID = ITEM_GOLD_LARGE;
			v34 = grng->random(1001) + 1000;
		}
		else if (a2->uItemIndex == ITEM_TREASURE_LEVEL_6)
		{
			a1a.containing_item.uItemID = ITEM_GOLD_LARGE;
			v34 = grng->random(3001) + 2000;
		}
		a1a.uType = (SPRITE_OBJECT_TYPE)pItemTable->pItems[a1a.containing_item.uItemID].uSpriteID;
		a1a.containing_item.SetIdentified();
		a1a.uObjectDescID = pObjectList->ObjectIDByItemID(a1a.uType);
		a1a.containing_item.special_enchantment = (ITEM_ENCHANTMENT)v34;
	}
	else
	{
		if (!a1a.containing_item.GenerateArtifact())
			return;
		a1a.uType = (SPRITE_OBJECT_TYPE)pItemTable->pItems[a1a.containing_item.uItemID].uSpriteID;
		a1a.uObjectDescID = pObjectList->ObjectIDByItemID(a1a.uType);
		a1a.containing_item.Reset();  // TODO(captainurist): this needs checking
	}
	a1a.vPosition.y = a2->vPosition.y;
	a1a.uAttributes = 0;
	a1a.uSoundID = 0;
	a1a.uFacing = 0;
	a1a.vPosition.z = a2->vPosition.z;
	a1a.vPosition.x = a2->vPosition.x;
	a1a.spell_skill = PLAYER_SKILL_MASTERY_NONE;
	a1a.spell_level = 0;
	a1a.uSpellID = SPELL_NONE;
	a1a.spell_target_pid = 0;
	a1a.spell_caster_pid = 0;
	a1a.uSpriteFrameID = 0;
	a1a.uSectorID = pIndoor->GetSector(a2->vPosition.x, a2->vPosition.y, a2->vPosition.z);
	a1a.Create(0, 0, 0, 0);
}

MM_DEFINE_ENUM_SERIALIZATION_FUNCTIONS(MapStartPoint, CASE_SENSITIVE, {
	{MapStartPoint_Party, "Party Start"},
	{MapStartPoint_North, "North Start"},
	{MapStartPoint_South, "South Start"},
	{MapStartPoint_East, "East Start"},
	{MapStartPoint_West, "West Start"}
	})

	void TeleportToStartingPoint(MapStartPoint point)
{
	std::string pName = toString(point);

	if (pDecorationList->GetDecorIdByName(pName))
	{
		if (!pLevelDecorations.empty())
		{
			for (size_t i = 0; i < pLevelDecorations.size(); ++i)
			{
				if (pLevelDecorations[i].uDecorationDescID == pDecorationList->GetDecorIdByName(pName))
				{
					pParty->vPosition.x = pLevelDecorations[i].vPosition.x;
					pParty->vPosition.y = pLevelDecorations[i].vPosition.y;
					pParty->vPosition.z = pLevelDecorations[i].vPosition.z;
					pParty->uFallStartZ = pParty->vPosition.z;
					pParty->_viewYaw = (int)(TrigLUT.HalfPi *
						pLevelDecorations[i].field_1A) /
						90;
					if (pLevelDecorations[i]._yawAngle)
						pParty->_viewYaw = pLevelDecorations[i]._yawAngle;
					pParty->_viewPitch = 0;
					pParty->uFallSpeed = 0;
				}
			}
		}
		if (Start_Party_Teleport_Flag)
		{
			if (Party_Teleport_X_Pos)
				pParty->vPosition.x = Party_Teleport_X_Pos;
			if (Party_Teleport_Y_Pos)
				pParty->vPosition.y = Party_Teleport_Y_Pos;
			if (Party_Teleport_Z_Pos)
			{
				pParty->vPosition.z = Party_Teleport_Z_Pos;
				pParty->uFallStartZ = Party_Teleport_Z_Pos;
			}
			if (Party_Teleport_Cam_Yaw != -1)
				pParty->_viewYaw = Party_Teleport_Cam_Yaw;
			if (Party_Teleport_Cam_Pitch)
				pParty->_viewPitch = Party_Teleport_Cam_Pitch;
			if (Party_Teleport_Z_Speed) pParty->uFallSpeed = Party_Teleport_Z_Speed;
		}
		Party_Teleport_Cam_Yaw = -1;
		Start_Party_Teleport_Flag = 0;
		Party_Teleport_Z_Speed = 0;
		Party_Teleport_Cam_Pitch = 0;
		Party_Teleport_Z_Pos = 0;
		Party_Teleport_Y_Pos = 0;
		Party_Teleport_X_Pos = 0;
	}
}
