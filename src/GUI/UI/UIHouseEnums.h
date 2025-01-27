#pragma once

#include "Utility/Segment.h"

enum HOUSE_ID
{
	HOUSE_INVALID = 0,
	HOUSE_SMITH_EMERALD_ISLE = 1,
	HOUSE_ARMOURER_EMERALD_ISLE = 15,
	HOUSE_MAGE_EMERALD_ISLE = 29,
	HOUSE_MAGE_HARMONDALE = 30,
	HOUSE_ALCHEMIST_EMERALD_ISLE = 42,
	HOUSE_ALCHEMIST_HARMONDALE = 43,
	HOUSE_STABLES_HARMONDALE = 54,
	HOUSE_STABLES_STEADWICK = 55,
	HOUSE_STABLES_TULAREAN_FOREST = 56,
	HOUSE_STABLES_DEYJA = 57,
	HOUSE_STABLES_BRACADA_DESERT = 58,
	HOUSE_STABLES_TATALIA = 59,
	HOUSE_STABLES_AVLEE = 60,
	HOUSE_STABLES_PLACEHOLDER_1 = 61,
	HOUSE_STABLES_PLACEHOLDER_2 = 62,
	HOUSE_BOATS_EMERALD_ISLE = 63,
	HOUSE_BOATS_ERATHIA = 64,
	HOUSE_BOATS_TULAREAN_FOREST = 65,
	HOUSE_BOATS_BRACADA_DESERT = 66,
	HOUSE_BOATS_EVENMORN_ISLAND = 67,
	HOUSE_BOATS_PIT = 68, // Not made it in MM7, but boat with the same name exist in MM8
	HOUSE_BOATS_TATALIA = 69,
	HOUSE_BOATS_AVLEE = 70,
	HOUSE_BOATS_CELESTE = 71, // Not made it in MM7
	HOUSE_BOATS_PLACEHOLDER_1 = 72,
	HOUSE_BOATS_PLACEHOLDER_2 = 73,
	HOUSE_TEMPLE_EMERALD_ISLE = 74,
	HOUSE_TEMPLE_HARMONDALE = 75,
	HOUSE_TRAINING_HALL_EMERALD_ISLE = 89,
	HOUSE_TRAINING_HALL_HARMONDALE = 90,
	HOUSE_TRAINING_HALL_STEADWICK = 91,
	HOUSE_TRAINING_HALL_PIERPOINT = 92,
	HOUSE_TRAINING_HALL_CELESTE = 93,
	HOUSE_TRAINING_HALL_PIT = 94,
	HOUSE_TRAINING_HALL_NIGHON = 95,
	HOUSE_TRAINING_HALL_AVLEE = 97,

	HOUSE_TOWNHALL_HARMONDALE = 102,
	HOUSE_TOWNHALL_ERATHIA = 103, // aka Steadwick Townhall.
	HOUSE_TOWNHALL_TULAREAN_FOREST = 104, // aka Pierpont Townhall.
	HOUSE_TOWNHALL_CELESTE = 105, // aka Hall of Dawn.
	HOUSE_TOWNHALL_THE_PIT = 106, // aka Hall of Midnight.
	HOUSE_TAVERN_EMERALD_ISLE = 107,
	HOUSE_TAVERN_STONE_CITY = 120,
	HOUSE_BANK_HARMONDALE = 128,
	HOUSE_FIRE_GUILD_INITIATE_EMERALD_ISLE = 139,
	HOUSE_AIR_GUILD_INITIATE_EMERALD_ISLE = 143,
	HOUSE_SPIRIT_GUILD_INITIATE_EMERALD_ISLE = 155,
	HOUSE_BODY_GUILD_INITIATE_EMERALD_ISLE = 163,
	HOUSE_BODY_GUILD_ERATHIA = 165,
	HOUSE_DARK_GUILD_PIT = 170,
	HOUSE_SELF_GUILD_1 = 171,
	HOUSE_SELF_GUILD_2 = 172,
	HOUSE_LORD_AND_JUDGE_EMERALD_ISLE = 186,
	HOUSE_JAIL = 187,
	HOUSE_JUDGE_HARMONDALE = 190,
	HOUSE_224_EMERALD_ISLE = 224,
	HOUSE_225_EMERALD_ISLE = 225,
	HOUSE_238_EMERALD_ISLE = 238,
	HOUSE_466_HARMONDALE = 466,
	HOUSE_467_HARMONDALE = 467,
	HOUSE_468_HARMONDALE = 468,
	HOUSE_472_HARMONDALE = 472,
	HOUSE_488_HARMONDALE = 488,
	HOUSE_489_HARMONDALE = 489,
	HOUSE_THRONEROOM_WIN_GOOD = 600,  // Final task completion for good side
	HOUSE_THRONEROOM_WIN_EVIL = 601,   // Final task completion for evil side

	HOUSE_FIRST_TOWNHALL = HOUSE_TOWNHALL_HARMONDALE,
	HOUSE_LAST_TOWNHALL = HOUSE_TOWNHALL_THE_PIT,
};

inline Segment<HOUSE_ID> townhallHouses()
{
	return { HOUSE_FIRST_TOWNHALL, HOUSE_LAST_TOWNHALL };
}

enum HouseSoundID : uint32_t
{
	HouseSound_Greeting = 1,  // General greeting
	HouseSound_NotEnoughMoney = 2,
	HouseSound_Greeting_2 = 3,  // Polite Greeting when you're guild member
	HouseSound_Goodbye = 4      // farewells when bought something
};
