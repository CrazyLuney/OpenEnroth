#pragma once

#include "Engine/Objects/ItemEnchantment.h"
#include "Engine/Objects/Items.h"
#include "Utility/IndexedArray.h"

#pragma pack(push, 1)
struct BonusRange
{
	unsigned int minR;
	unsigned int maxR;
}; // TODO(captainurist): Segment<int>?
#pragma pack(pop)

/*  176 */
#pragma pack(push, 1)
struct ItemTable
{
	void Initialize();
	void LoadPotions();
	void LoadPotionNotes();
	void GenerateItem(ITEM_TREASURE_LEVEL treasure_level, unsigned int uTreasureType, ItemGen* pItem);
	void SetSpecialBonus(ItemGen* pItem);
	bool IsMaterialSpecial(ItemGen* pItem);
	bool IsMaterialNonCommon(ItemGen* pItem);
	void Release();
	void PrintItemTypesEnum();

	void InitializeStandardEnchantments();
	void InitializeSpecialEnchantments();
	void InitializeItems();
	void InitializeRandomItems();

	IndexedArray<ItemDesc, ITEM_FIRST_VALID, ITEM_LAST_VALID> pItems;                   // 4-9604h
	std::array<ItemEnchantment, 24> pEnchantments;                // 9604h
	IndexedArray<ItemSpecialEnchantment, ITEM_ENCHANTMENT_FIRST_VALID, ITEM_ENCHANTMENT_LAST_VALID> pSpecialEnchantments;  // 97E4h -9FC4h
	char field_9FC4[5000];
	char field_B348[5000];
	char field_C6D0[5000];
	char field_DA58[5000];
	char field_EDE0[384];
	// 77B2h*2=EF64h  -102ECh
	IndexedArray<IndexedArray<ITEM_TYPE, ITEM_FIRST_REAL_POTION, ITEM_LAST_REAL_POTION>, ITEM_FIRST_REAL_POTION, ITEM_LAST_REAL_POTION> potionCombination;
	// 8176h*2=102ECh -11674
	IndexedArray<IndexedArray<uint16_t, ITEM_FIRST_REAL_POTION, ITEM_LAST_REAL_POTION>, ITEM_FIRST_REAL_POTION, ITEM_LAST_REAL_POTION> potionNotes;
	std::string pItemsTXT_Raw;              // 11674h
	std::string pRndItemsTXT_Raw;
	std::string pStdItemsTXT_Raw;           // 1167Ch
	std::string pSpcItemsTXT_Raw;           // 11680h
	IndexedArray<unsigned int, ITEM_TREASURE_LEVEL_FIRST_RANDOM, ITEM_TREASURE_LEVEL_LAST_RANDOM> uChanceByTreasureLvlSumm;   // 11684
	IndexedArray<unsigned int, ITEM_TREASURE_LEVEL_FIRST_RANDOM, ITEM_TREASURE_LEVEL_LAST_RANDOM> uBonusChanceStandart;       // 1169c
	IndexedArray<unsigned int, ITEM_TREASURE_LEVEL_FIRST_RANDOM, ITEM_TREASURE_LEVEL_LAST_RANDOM> uBonusChanceSpecial;        // 116B4
	IndexedArray<unsigned int, ITEM_TREASURE_LEVEL_FIRST_RANDOM, ITEM_TREASURE_LEVEL_LAST_RANDOM> uBonusChanceWpSpecial;      // 116cc -116e4
	IndexedArray<unsigned int, EQUIP_FIRST_NORMAL_ENCHANTABLE, EQUIP_LAST_NORMAL_ENCHANTABLE> pEnchantmentsSumm; // 116E4h -11708h
	IndexedArray<BonusRange, ITEM_TREASURE_LEVEL_FIRST_RANDOM, ITEM_TREASURE_LEVEL_LAST_RANDOM> bonus_ranges;                 // 45C2h*4 =11708h
	unsigned int pSpecialEnchantments_count;    // 11798h
	char field_1179C;
	char field_1179D;
	char field_1179E;
	char field_1179F;
};
#pragma pack(pop)

extern struct ItemTable* pItemTable;
