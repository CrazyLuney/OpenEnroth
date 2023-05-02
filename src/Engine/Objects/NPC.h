#pragma once

#include "Utility/IndexedArray.h"

#include "Engine/Objects/NPCEnums.h"

struct NPCTopic
{
	std::string pTopic;
	std::string pText;
};

extern std::array<NPCTopic, 789> pNPCTopics;

/*  136 */
#pragma pack(push, 1)
struct NPCData
{  // 4Ch
	inline bool Hired() { return (uFlags & 0x80) != 0; }

	std::string pName;               // 0
	unsigned int uPortraitID = 0;  // 4
	unsigned int uFlags = 0;  // 8    // & 0x80    no greeting on dialogue start;
	// looks like hired
	int fame = 0;                  // c
	int rep = 0;                   // 10
	unsigned int Location2D = 0;   // 14  house_id
	NPCProf profession = NoProfession;  // 18
	int greet = 0;                 // 1c
	int is_joinable = 0;           // 20
	int field_24 = 0;
	unsigned int dialogue_1_evt_id = 0;  // dialogue options that are defined by script
	unsigned int dialogue_2_evt_id = 0;  // = 0  == unused
	unsigned int dialogue_3_evt_id = 0;  // can also be idx in pNPCTopics
	unsigned int dialogue_4_evt_id = 0;  // and absolutely crazy stuff when it's in party hierlings (npc2)
	unsigned int dialogue_5_evt_id = 0;
	unsigned int dialogue_6_evt_id = 0;
	unsigned int uSex = 0;       // 40
	int bHasUsedTheAbility = 0;  // 44
	int news_topic = 0;          // 48
};
#pragma pack(pop)

/*  138 */
#pragma pack(push, 1)
struct NPCProfession
{
	uint32_t uHirePrice = 0;
	std::string pBenefits;
	std::string pActionText;
	std::string pJoinText;
	std::string pDismissText;
};
#pragma pack(pop)

/*  139 */
#pragma pack(push, 1)
struct NPCProfessionChance
{
	unsigned int uTotalprofChance{};     // summ
	char professionChancePerArea[60]{};  // prof position
};
#pragma pack(pop)

/*  140 */
#pragma pack(push, 1)
struct NPCGreeting
{
	std::string pGreeting1;  // at first meet
	std::string pGreeting2;  // at latest meets

	constexpr inline const std::string& operator[](const std::size_t& i) const noexcept
	{
		assert(i < 2);
		switch (i)
		{
		case 0:
			return pGreeting1;
		case 1:
			return pGreeting2;
		}
	}
};
#pragma pack(pop)

/*  137 */
#pragma pack(push, 1)
struct NPCStats
{
	inline NPCStats()
	{
		uNumNPCNames.fill(0);
	}

	void InitializeNPCText();
	void InitializeNPCData();
	void Initialize();
	void Release();
	void InitializeAdditionalNPCs(NPCData* pNPCDataBuff, int npc_uid, int uLocation2D, int uMapId);
	void OnLoadSetNPC_Names();
	const char* sub_495366_MispronounceName(uint8_t firstLetter, uint8_t genderId);

	std::array<NPCData, 501> pNPCData;     // 0 - 94BCh count from 1
	std::array<NPCData, 501> pNewNPCData;  // 94BCh- 12978h count from 1
	std::array<std::string[2], 540> pNPCNames;
	IndexedArray<NPCProfession, NPC_PROFESSION_FIRST, NPC_PROFESSION_LAST> pProfessions = { {} };  // count from 1
	std::array<NPCData, 100> pAdditionalNPC;
	std::array<std::string, 51> pCatchPhrases; // 15CA4h
	std::array<std::string, 501> pNPCUniqueNames; // from first batch
	NPCProfessionChance pProfessionChance[77];  // 16544h profession chance in each area
	int field_17884 = 0;
	int field_17888 = 0;
	NPCGreeting pNPCGreetings[206];
	std::array<uint16_t, 51> pGroups = { {} };
	std::array<uint16_t, 51> pGroups_copy = { {} };
	unsigned int uNewlNPCBufPos{};
	unsigned int uNumNewNPCs{};
	int field_17FC8 = 0;
	size_t uNumNPCProfessions{};
	std::array<size_t, 2> uNumNPCNames;

	static int dword_AE336C_LastMispronouncedNameFirstLetter;
	static int dword_AE3370_LastMispronouncedNameResult;
};
#pragma pack(pop)

extern int pDialogueNPCCount;
extern std::array<class Image*, 6> pDialogueNPCPortraits;
extern int uNumDialogueNPCPortraits;
extern struct NPCStats* pNPCStats;

bool PartyHasDragon();
bool CheckHiredNPCSpeciality(NPCProf prof);

int UseNPCSkill(NPCProf profession, int id);
void NPCHireableDialogPrepare();
void _4B4224_UpdateNPCTopics(int _this);
const char* GetProfessionActionText(NPCProf prof);
struct NPCData* GetNPCData(signed int npcid);
struct NPCData* GetNewNPCData(signed int npcid, int* npc_indx);
int GetGreetType(signed int SpeakingNPC_ID);
int NPCDialogueEventProcessor(int npc_event_id, int entry_line = 0);

class FlatHirelings
{
public:
	/**
	 * Populates this structure.
	 */
	void Prepare();

	/**
	 * @return                          Total number of hirelings in this structure.
	 */
	size_t Size() const
	{
		return count;
	}

	/**
	 * @param index                     Hireling index.
	 * @return                          Whether a hireling is actually a follower (doesn't count towards the total
	 *                                  hireling count, e.g. Margaret the guide on Emerald island).
	 */
	bool IsFollower(size_t index) const;

	/**
	 * @param index                     Hireling index.
	 * @return                          Associated `NPCData`.
	 */
	NPCData* Get(size_t index) const;

private:
	/** Hireling / follower NPC ids.
	 * If 0 or 1, then it's an index into `pParty->pHirelings`.
	 * If 2 or more, then you have to subtract 2 to get an index into `pNPCStats->pNewNPCData`. */
	std::array<int8_t, 1024> ids = { {} };

	/** Number of valid ids in the array above. */
	size_t count = 0;
};
