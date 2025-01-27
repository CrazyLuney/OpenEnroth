#pragma once

#include "Engine/Spells/SpellEnums.h"

#include "Utility/Exception.h"
#include "Utility/IndexedArray.h"
#include "Utility/Memory/Blob.h"

#include "ActorEnums.h"
#include "ItemEnums.h"

/*  334 */
enum MONSTER_TYPE
{
	MONSTER_DEVIL_1 = 0x16,
	MONSTER_DEVIL_2 = 0x17,
	MONSTER_DEVIL_3 = 0x18,
	MONSTER_DRAGON_1 = 0x19,
	MONSTER_DRAGON_2 = 0x1A,
	MONSTER_DRAGON_3 = 0x1B,
	MONSTER_ELEMENTAL_WATER_1 = 0x2E,
	MONSTER_ELEMENTAL_WATER_3 = 0x30,
	MONSTER_ELF_ARCHER_1 = 0x31,
	MONSTER_ELF_ARCHER_3 = 0x33,
	MONSTER_ELF_SPEARMAN_1 = 0x34,
	MONSTER_ELF_SPEARMAN_3 = 0x36,
	MONSTER_GHOST_1 = 0x46,
	MONSTER_GHOST_3 = 0x48,
	MONSTER_HARPY_1 = 0x55,
	MONSTER_HARPY_2 = 0x56,
	MONSTER_HARPY_3 = 0x57,
	MONSTER_LICH_1 = 0x5B,
	MONSTER_LICH_3 = 0x5D,
	MONSTER_OOZE_1 = 0x70,
	MONSTER_OOZE_2 = 0x71,
	MONSTER_OOZE_3 = 0x72,
	MONSTER_PEASANT_ELF_FEMALE_1_1 = 0x85,
	MONSTER_PEASANT_ELF_MALE_3_3 = 0x96,
	MONSTER_SKELETON_1 = 0xC7,
	MONSTER_SKELETON_3 = 0xC9,
	MONSTER_TITAN_1 = 0xD3,
	MONSTER_TITAN_3 = 0xD5,
	MONSTER_VAMPIRE_1 = 0xD9,
	MONSTER_VAMPIRE_3 = 0xDB,
	MONSTER_WIGHT_1 = 0xDF,
	MONSTER_WIGHT_3 = 0xE1,
	MONSTER_ZOMBIE_1 = 0xE5,
	MONSTER_ZOMBIE_3 = 0xE7,
	MONSTER_PEASANT_GOBLIN_MALE_3_3 = 0xF9,
	MONSTER_TROLL_1 = 0xFA,
	MONSTER_TROLL_2 = 0xFB,
	MONSTER_TROLL_3 = 0xFC,
	MONSTER_TREANT_1 = 0xFD,
	MONSTER_TREANT_3 = 0xFF,
	MONSTER_GHOUL_1 = 0x100,
	MONSTER_GHOUL_3 = 0x102,
};

/*  335 */
enum MONSTER_SPECIAL_ABILITY_TYPE : uint8_t
{
	MONSTER_SPECIAL_ABILITY_NONE = 0,
	MONSTER_SPECIAL_ABILITY_SHOT = 1,
	MONSTER_SPECIAL_ABILITY_SUMMON = 2,
	MONSTER_SPECIAL_ABILITY_EXPLODE = 3,
};

enum MONSTER_AI_TYPE : uint8_t
{
	MONSTER_AI_SUICIDAL = 0,
	MONSTER_AI_WIMP = 1,
	MONSTER_AI_NORMAL = 2,
	MONSTER_AI_AGGRESSIVE = 3,
};

enum MONSTER_MOVEMENT_TYPE : uint8_t
{
	MONSTER_MOVEMENT_TYPE_SHORT = 0x0,
	MONSTER_MOVEMENT_TYPE_MEDIUM = 0x1,
	MONSTER_MOVEMENT_TYPE_LONG = 0x2,
	MONSTER_MOVEMENT_TYPE_GLOBAL = 0x3,
	MONSTER_MOVEMENT_TYPE_FREE = 0x4,
	MONSTER_MOVEMENT_TYPE_STATIONARY = 0x5,
};

/*  336 */
enum MONSTER_SUPERTYPE
{
	MONSTER_SUPERTYPE_UNDEAD = 0x1,
	MONSTER_SUPERTYPE_KREEGAN = 0x2,
	MONSTER_SUPERTYPE_DRAGON = 0x3,
	MONSTER_SUPERTYPE_ELF = 0x4,
	MONSTER_SUPERTYPE_WATER_ELEMENTAL = 0x5,
	MONSTER_SUPERTYPE_TREANT = 0x6,
	MONSTER_SUPERTYPE_TITAN = 0x7,
	MONSTER_SUPERTYPE_8 = 0x8,
};

enum SPECIAL_ATTACK_TYPE : uint8_t
{
	SPECIAL_ATTACK_NONE = 0,
	SPECIAL_ATTACK_CURSE = 1,
	SPECIAL_ATTACK_WEAK = 2,
	SPECIAL_ATTACK_SLEEP = 3,
	SPECIAL_ATTACK_DRUNK = 4,
	SPECIAL_ATTACK_INSANE = 5,
	SPECIAL_ATTACK_POISON_WEAK = 6,
	SPECIAL_ATTACK_POISON_MEDIUM = 7,
	SPECIAL_ATTACK_POISON_SEVERE = 8,
	SPECIAL_ATTACK_DISEASE_WEAK = 9,
	SPECIAL_ATTACK_DISEASE_MEDIUM = 10,
	SPECIAL_ATTACK_DISEASE_SEVERE = 11,
	SPECIAL_ATTACK_PARALYZED = 12,
	SPECIAL_ATTACK_UNCONSCIOUS = 13,
	SPECIAL_ATTACK_DEAD = 14,
	SPECIAL_ATTACK_PETRIFIED = 15,
	SPECIAL_ATTACK_ERADICATED = 16,
	SPECIAL_ATTACK_BREAK_ANY = 17,
	SPECIAL_ATTACK_BREAK_ARMOR = 18,
	SPECIAL_ATTACK_BREAK_WEAPON = 19,
	SPECIAL_ATTACK_STEAL = 20,
	SPECIAL_ATTACK_AGING = 21,
	SPECIAL_ATTACK_MANA_DRAIN = 22,
	SPECIAL_ATTACK_FEAR = 23,
};

enum MONSTER_HOSTILITY_RADIUS : uint8_t
{
	MONSTER_HOSTILITY_RADIUS_FRIENDLY = 0,
	MONSTER_HOSTILITY_RADIUS_CLOSE = 1,
	MONSTER_HOSTILITY_RADIUS_SHORT = 2,
	MONSTER_HOSTILITY_RADIUS_MEDIUM = 3,
	MONSTER_HOSTILITY_RADIUS_LONG = 4,
};

/*  187 */
#pragma pack(push, 1)
struct MonsterInfo
{
	std::string pName;
	std::string pPictureName;
	uint8_t uLevel = 0;
	uint8_t uTreasureDropChance = 0;
	uint8_t uTreasureDiceRolls = 0;
	uint8_t uTreasureDiceSides = 0;
	ITEM_TREASURE_LEVEL uTreasureLevel = ITEM_TREASURE_LEVEL_INVALID;
	uint8_t uTreasureType = 0;
	uint8_t uFlying = 0;
	MONSTER_MOVEMENT_TYPE uMovementType = MONSTER_MOVEMENT_TYPE_SHORT;
	MONSTER_AI_TYPE uAIType = MONSTER_AI_SUICIDAL;
	MONSTER_HOSTILITY_RADIUS uHostilityType = MONSTER_HOSTILITY_RADIUS_FRIENDLY;
	char field_12 = 0;
	SPECIAL_ATTACK_TYPE uSpecialAttackType = SPECIAL_ATTACK_NONE;
	uint8_t uSpecialAttackLevel = 0;
	DAMAGE_TYPE uAttack1Type;
	uint8_t uAttack1DamageDiceRolls = 0;
	uint8_t uAttack1DamageDiceSides = 0;
	uint8_t uAttack1DamageBonus = 0;
	uint8_t uMissleAttack1Type = 0;
	uint8_t uAttack2Chance = 0;
	DAMAGE_TYPE uAttack2Type;
	uint8_t uAttack2DamageDiceRolls = 0;
	uint8_t uAttack2DamageDiceSides = 0;
	uint8_t uAttack2DamageBonus = 0;
	uint8_t uMissleAttack2Type = 0;
	uint8_t uSpell1UseChance = 0;
	SPELL_TYPE uSpell1ID = SPELL_NONE;
	uint8_t uSpell2UseChance = 0;
	SPELL_TYPE uSpell2ID = SPELL_NONE;
	uint8_t uResFire = 0;
	uint8_t uResAir = 0;
	uint8_t uResWater = 0;
	uint8_t uResEarth = 0;
	uint8_t uResMind = 0;
	uint8_t uResSpirit = 0;
	uint8_t uResBody = 0;
	uint8_t uResLight = 0;
	uint8_t uResDark = 0;
	uint8_t uResPhysical = 0;
	MONSTER_SPECIAL_ABILITY_TYPE uSpecialAbilityType = MONSTER_SPECIAL_ABILITY_NONE;
	uint8_t uSpecialAbilityDamageDiceRolls = 0;
	uint8_t uSpecialAbilityDamageDiceSides = 0;
	uint8_t uSpecialAbilityDamageDiceBonus = 0;
	uint8_t uNumCharactersAttackedPerSpecialAbility = 0;
	char field_33 = 0;
	uint16_t uID = 0;
	bool bBloodSplatOnDeath = 0;  // true for bloodsplat on death
	uint16_t uSpellSkillAndMastery1 = 0;
	uint16_t uSpellSkillAndMastery2 = 0;
	int16_t field_3C_some_special_attack = 0;
	int16_t field_3E = 0;
	unsigned int uHP = 0;
	unsigned int uAC = 0;
	unsigned int uExp = 0;
	unsigned int uBaseSpeed = 0;
	signed int uRecoveryTime = 0;
	unsigned int uAttackPreference = 0;
};
#pragma pack(pop)

struct MonsterPlacementInfo
{
	uint16_t uID;
	std::string pName;
};

/*  189 */
#pragma pack(push, 1)
class MonsterStats
{
public:
	void Initialize();
	void InitializePlacements();
	signed int FindMonsterByTextureName(const char* Str2);

	static bool BelongsToSupertype(unsigned int uMonsterInfoID, enum MONSTER_SUPERTYPE eSupertype);

	const MonsterInfo& GetMonsterInfo(const unsigned uMonsterInfoID) const
	{
		assert(uMonsterInfoID > 0);
		return pInfos[uMonsterInfoID - 1];
	}

	const MonsterPlacementInfo& GetMonsterPlacementInfo(const unsigned uMonsterInfoID) const
	{
		assert(uMonsterInfoID > 0);
		return pPlaceStrings[uMonsterInfoID - 1];
	}
private:
	std::vector<MonsterInfo> pInfos;
	std::vector<MonsterPlacementInfo> pPlaceStrings;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct MonsterDesc
{
	uint16_t uMonsterHeight;
	uint16_t uMonsterRadius;
	uint16_t uMovementSpeed;
	int16_t uToHitRadius;
	uint32_t sTintColor;
	std::array<uint16_t, 4> pSoundSampleIDs; // TODO: actually this one should also be an IndexedArray
	std::string pMonsterName;
	IndexedArray<std::string, ANIM_Count> pSpriteNames;
};
#pragma pack(pop)

struct MonsterList
{
	int16_t GetMonsterIDByName(const char* pMonsterName);
	void ToFile();
	void FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8);

	std::vector<MonsterDesc> pMonsters;
};

extern struct MonsterStats* pMonsterStats;
extern struct MonsterList* pMonsterList;
