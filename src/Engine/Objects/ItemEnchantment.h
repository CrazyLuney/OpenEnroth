#pragma once

#include "Engine/Objects/Items.h"

#include "Utility/IndexedArray.h"

struct Player;

struct Enchantment
{
	Enchantment() {}

	explicit Enchantment(int bonus, uint16_t Player::* skillPtr = nullptr)
		: statPtr(skillPtr)
		, statBonus(bonus)
	{
	}

	uint16_t Player::* statPtr = nullptr;
	int statBonus = 0;
};

struct ItemEnchantment
{
	// Bonus|Sta|Of
	// Name|Arm|Shld|Helm|Belt|Cape|Gaunt|Boot|Ring|Amul

	std::string pBonusStat;
	std::string pOfName;
	IndexedArray<uint8_t, EQUIP_FIRST_NORMAL_ENCHANTABLE, EQUIP_LAST_NORMAL_ENCHANTABLE> to_item;
};

struct ItemSpecialEnchantment
{
	// Bonus Stat|Name
	// Add|W1|W2|Miss|Arm|Shld|Helm|Belt|Cape|Gaunt|Boot|Ring|Amul|Value|Lvl|Description
	// fo special Bonuses and values

	std::string pBonusStatement;
	std::string pNameAdd;
	IndexedArray<char, EQUIP_FIRST_SPECIAL_ENCHANTABLE, EQUIP_LAST_SPECIAL_ENCHANTABLE> to_item;
	int iValue;
	int iTreasureLevel;
};
