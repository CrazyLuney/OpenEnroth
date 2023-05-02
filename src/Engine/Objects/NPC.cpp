#include "Engine/Objects/NPC.h"

#include "Engine/Autonotes.h"
#include "Engine/Engine.h"
#include "Engine/EngineGlobals.h"
#include "Engine/Awards.h"
#include "Engine/Events.h"
#include "Engine/Graphics/Indoor.h"
#include "Engine/Graphics/Overlays.h"
#include "Engine/Localization.h"
#include "Engine/LOD.h"
#include "Engine/MapInfo.h"
#include "Engine/Objects/Actor.h"
#include "Engine/Party.h"
#include "Engine/Spells/CastSpellInfo.h"

#include "GUI/GUIButton.h"
#include "GUI/UI/UIHouses.h"
#include "GUI/UI/UIStatusBar.h"
#include "GUI/UI/UITransition.h"

#include "Media/Audio/AudioPlayer.h"

#include "Library/Random/Random.h"

#include "Engine/TextParsers/SymbolMatcher/SymbolMatcherMiniParser.hpp"



int pDialogueNPCCount;
std::array<class Image*, 6> pDialogueNPCPortraits;
int uNumDialogueNPCPortraits;
struct NPCStats* pNPCStats = nullptr;

int NPCStats::dword_AE336C_LastMispronouncedNameFirstLetter = -1;
int NPCStats::dword_AE3370_LastMispronouncedNameResult = -1;

void InitializeAwards();
void InitializeScrolls();
void InitializeMerchants();
void InitializeTransitions();
void InitializeAutonotes();
void InitializeQuests();
bool CheckPortretAgainstSex(int portret_num, int sex);

// All conditions for alive character excluding zombie
static const Segment<Condition> standardConditionsExcludeDead = { Condition_Cursed, Condition_Unconscious };

// All conditions including dead character ones, but still excluding zombie
static const Segment<Condition> standardConditionsIncludeDead = { Condition_Cursed, Condition_Eradicated };

//----- (004459F9) --------------------------------------------------------
NPCData* GetNPCData(signed int npcid)
{
	NPCData* result;

	if (npcid >= 0)
	{
		if (npcid < 5000)
		{
			if (npcid >= 501)
			{
				logger->warning("NPC id exceeds MAX_DATA!");
			}
			return &pNPCStats->pNewNPCData[npcid];  // - 1];
		}
		return &pNPCStats->pAdditionalNPC[npcid - 5000];
	}

	if (npcid >= 5000) return &pNPCStats->pAdditionalNPC[npcid - 5000];
	if (sDialogue_SpeakingActorNPC_ID >= 0)
	{
		result = 0;
	}
	else
	{
		FlatHirelings buf;
		buf.Prepare();

		result = buf.Get(abs(sDialogue_SpeakingActorNPC_ID) - 1);
	}
	return result;
}

//----- (00445B2C) --------------------------------------------------------
struct NPCData* GetNewNPCData(signed int npcid, int* npc_indx)
{
	NPCData* result;

	if (npcid >= 0)
	{
		if (npcid < 5000)
		{
			if (npcid >= 501)
			{
				logger->warning("NPC id exceeds MAX_DATA!");
			}
			*npc_indx = npcid;
			return &pNPCStats->pNewNPCData[npcid];
		}
		*npc_indx = npcid - 5000;
		return &pNPCStats->pAdditionalNPC[npcid - 5000];
	}
	if (npcid >= 5000)
	{
		*npc_indx = npcid - 5000;
		return &pNPCStats->pAdditionalNPC[npcid - 5000];
	}
	if (sDialogue_SpeakingActorNPC_ID >= 0)
	{
		*npc_indx = 0;
		result = nullptr;
	}
	else
	{
		FlatHirelings buf;
		buf.Prepare();

		result = buf.Get(abs(sDialogue_SpeakingActorNPC_ID) - 1);
	}
	return result;
}

//----- (00476977) --------------------------------------------------------
void NPCStats::InitializeNPCText()
{
	using namespace MiniParser;

	{
		const auto blob = pEvents_LOD->LoadCompressedTexture("npctext.txt");

		for (const auto& data_line : GetLines(blob.string_view()) | std::views::drop(1) | std::views::take(std::size(pNPCTopics)))
		{
			auto tokens = GetTokens(data_line);
			auto it = std::begin(tokens);

			std::size_t id;

			ParseToken(it, id);
			ParseToken(it, pNPCTopics[id].pText, StripQuotes);
		}
	}

	{
		const auto blob = pEvents_LOD->LoadCompressedTexture("npctopic.txt");

		// NPC topics count limit
		for (const auto& data_line : GetLines(blob.string_view()) | std::views::drop(1) | std::views::take(579))
		{
			auto tokens = GetTokens(data_line);
			auto it = std::begin(tokens);

			std::size_t id;

			ParseToken(it, id);
			ParseToken(it, pNPCTopics[id].pTopic, StripQuotes);
		}
	}

	{
		const auto blob = pEvents_LOD->LoadCompressedTexture("npcdist.txt");

		const auto areas_range = std::views::iota(1, 77);
		const auto professions_range = std::views::iota(1, 59);

		auto it_profession = std::begin(professions_range);

		for (const auto& data_line : GetLines(blob.string_view()) | std::views::drop(2) | std::views::take(58))
		{
			auto tokens = GetTokens(data_line);
			auto it = std::begin(tokens);

			DropToken(it);

			for (auto area : areas_range)
			{
				ParseToken(it, pProfessionChance[area].professionChancePerArea[*it_profession]);
			}

			++it_profession;
		}

		{
			auto& record = pProfessionChance[0];

			record.uTotalprofChance = 0;

			std::fill(std::begin(record.professionChancePerArea), std::end(record.professionChancePerArea), 0);
		}

		for (auto area : areas_range)
		{
			auto& record = pProfessionChance[area];

			record.uTotalprofChance = 0;
			record.professionChancePerArea[0] = 0;
			record.professionChancePerArea[59] = 0;

			for (auto profession : professions_range)
			{
				record.uTotalprofChance += record.professionChancePerArea[profession];
			}
		}
	}
}

//----- (00476C60) --------------------------------------------------------
void NPCStats::OnLoadSetNPC_Names()
{
	for (unsigned int i = 1; i < uNumNewNPCs; ++i)
		pNewNPCData[i].pName = pNPCUniqueNames[i];

	if (!pParty->pHirelings[0].pName.empty())
		pParty->pHirelings[0].pName = pParty->pHireling1Name;
	if (!pParty->pHirelings[1].pName.empty())
		pParty->pHirelings[1].pName = pParty->pHireling2Name;
}

//----- (00476CB5) --------------------------------------------------------
void NPCStats::InitializeNPCData()
{
	using namespace MiniParser;

	{
		const auto blob = pEvents_LOD->LoadCompressedTexture("npcdata.txt");

		for (const auto& data_line : GetLines(blob.string_view()) | std::views::drop(2) | std::views::take(500))
		{
			auto tokens = GetTokens(data_line);
			auto it = std::begin(tokens);

			std::size_t id;

			ParseToken(it, id);

			auto& npc_data = pNPCData[id];

			ParseToken(it, npc_data.pName, StripQuotes);
			ParseToken(it, npc_data.uPortraitID);
			DropTokens(it, 3);
			ParseToken(it, npc_data.Location2D);
			ParseToken(it, npc_data.profession);
			ParseToken(it, npc_data.greet);
			ParseTokenSymbol(it, [&](const auto& match)
				{
					return SymbolParsers::ParseBool(match, npc_data.is_joinable);
				});
			ParseToken(it, npc_data.dialogue_1_evt_id);
			ParseToken(it, npc_data.dialogue_2_evt_id);
			ParseToken(it, npc_data.dialogue_3_evt_id);
			ParseToken(it, npc_data.dialogue_4_evt_id);
			ParseToken(it, npc_data.dialogue_5_evt_id);
			ParseToken(it, npc_data.dialogue_6_evt_id);

			pNPCUniqueNames[id] = npc_data.pName;
		}
	}

	uNumNewNPCs = 501;

	{
		const auto blob = pEvents_LOD->LoadCompressedTexture("npcgreet.txt");

		for (const auto& data_line : GetLines(blob.string_view()) | std::views::drop(1) | std::views::take(205))
		{
			auto tokens = GetTokens(data_line);
			auto it = std::begin(tokens);

			std::size_t id;

			ParseToken(it, id);
			ParseToken(it, pNPCGreetings[id].pGreeting1, StripQuotes);
			ParseToken(it, pNPCGreetings[id].pGreeting2, StripQuotes);
		}
	}

	{
		const auto blob = pEvents_LOD->LoadCompressedTexture("npcgroup.txt");

		for (const auto& data_line : GetLines(blob.string_view()) | std::views::drop(2) | std::views::take(51))
		{
			auto tokens = GetTokens(data_line);
			auto it = std::begin(tokens);

			std::size_t id;

			ParseToken(it, id);
			ParseToken(it, pGroups[id]);
		}
	}

	{
		const auto blob = pEvents_LOD->LoadCompressedTexture("npcnews.txt");

		for (const auto& data_line : GetLines(blob.string_view()) | std::views::drop(2) | std::views::take(50))
		{
			auto tokens = GetTokens(data_line);
			auto it = std::begin(tokens);

			std::size_t id;

			ParseToken(it, id);
			ParseToken(it, pCatchPhrases[id], StripQuotes);
		}
	}
}

//----- (0047702F) --------------------------------------------------------
void NPCStats::Initialize()
{
	using namespace MiniParser;

	int i;
	char* test_string;
	unsigned char c;
	bool break_loop;
	unsigned int temp_str_len;
	char* tmp_pos = nullptr;
	int decode_step;

	InitializeNPCData();
	InitializeNPCText();
	InitializeQuests();
	InitializeAutonotes();
	InitializeAwards();
	InitializeTransitions();
	InitializeMerchants();
	InitializeScrolls();

	uNumNPCNames.fill(0);

	{
		const auto blob = pEvents_LOD->LoadCompressedTexture("npcnames.txt");

		std::size_t i = 0;

		for (const auto& data_line : GetLines(blob.string_view()) | std::views::drop(1) | std::views::take(std::size(pNPCNames)))
		{
			auto tokens = GetTokens(data_line);

			auto it = std::begin(tokens);
			auto it_end = std::end(tokens);

			if (it != it_end)
			{
				ParseToken(it, pNPCNames[i][0]);
				++uNumNPCNames[0];
			}

			if (it != it_end)
			{
				ParseToken(it, pNPCNames[i][1]);
				++uNumNPCNames[1];
			}

			++i;
		}
	}

	uNewlNPCBufPos = 0;
	uNumNPCProfessions = 0;

	{
		const auto blob = pEvents_LOD->LoadCompressedTexture("npcprof.txt");

		const auto professions_range = std::views::iota(std::to_underlying(NPC_PROFESSION_FIRST_VALID), std::to_underlying(NPC_PROFESSION_LAST_VALID) + 1);

		for (const auto& data_line : GetLines(blob.string_view()) | std::views::drop(4))
		{
			auto tokens = GetTokens(data_line);
			auto it = std::begin(tokens);

			NPCProf id;

			if (!ParseToken(it, id))
				break;

			auto& profession_info = pProfessions[id];

			DropToken(it);
			ParseToken(it, profession_info.uHirePrice);
			ParseToken(it, profession_info.pActionText, StripQuotes);
			ParseToken(it, profession_info.pBenefits, StripQuotes);
			ParseToken(it, profession_info.pJoinText, StripQuotes);
			ParseToken(it, profession_info.pDismissText, StripQuotes);

			++uNumNPCProfessions;
		}
	}
}

//----- (00477266) --------------------------------------------------------
void NPCStats::Release()
{
}

//----- (0047730C) --------------------------------------------------------
bool CheckPortretAgainstSex(int a1, int) { return true; }
// 47730C: using guessed type int __stdcall const_1(int);

//----- (0047732C) --------------------------------------------------------
void NPCStats::InitializeAdditionalNPCs(NPCData* pNPCDataBuff, int npc_uid,
	int uLocation2D, int uMapId)
{
	int rep_gen;
	int uNPCSex;              // esi@1
	int uGeneratedPortret;    // ecx@23
	int test_prof_summ;       // ecx@37
	int gen_profession;       // eax@37
	int max_prof_cap;         // edx@37
	// signed int result; // eax@39
	int uRace;                // [sp+Ch] [bp-Ch]@1
	bool break_gen;           // [sp+10h] [bp-8h]@1
	signed int gen_attempts;  // [sp+14h] [bp-4h]@1
	int uPortretMin;          // [sp+24h] [bp+Ch]@1
	int uPortretMax;

	static const uint8_t NPCSexGenTable[86] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0,
		1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
	static const uint8_t NPCRaceGenTable[86] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3,
		1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0 };

	uint8_t seed = (uint8_t)((double)(npc_uid - 1) / 3.0);
	uNPCSex = NPCSexGenTable[seed];
	uRace = NPCRaceGenTable[seed];
	pNPCDataBuff->uSex = uNPCSex;
	pNPCDataBuff->pName = pNPCNames[grng->random(uNumNPCNames[uNPCSex])][uNPCSex];

	gen_attempts = 0;
	break_gen = false;

	do
	{
		switch (uRace)
		{
		case 0:
			if (uNPCSex == 0)
			{
				uPortretMin = 2;
				uPortretMax = 100;
			}
			else
			{
				uPortretMin = 201;
				uPortretMax = 250;
			}
		case 1:
			if (uNPCSex == 0)
			{
				uPortretMin = 400;
				uPortretMax = 430;
			}
			else
			{
				uPortretMin = 460;
				uPortretMax = 490;
			}
			break;
		case 2:
			if (uNPCSex == 0)
			{
				uPortretMin = 500;
				uPortretMax = 520;
			}
			else
			{
				uPortretMin = 530;
				uPortretMax = 550;
			}
			break;
		case 3:
			if (uNPCSex == 0)
			{
				uPortretMin = 300;
				uPortretMax = 330;
			}
			else
			{
				uPortretMin = 360;
				uPortretMax = 387;
			}

			break;
		}

		uGeneratedPortret =
			uPortretMin + grng->random(uPortretMax - uPortretMin + 1);
		if (CheckPortretAgainstSex(uGeneratedPortret, uNPCSex))
			break_gen = true;
		++gen_attempts;
		if (gen_attempts >= 4)
		{
			uGeneratedPortret = uPortretMin;
			break_gen = true;
		}
	} while (!break_gen);

	pNPCDataBuff->uPortraitID = uGeneratedPortret;
	pNPCDataBuff->uFlags = 0;
	pNPCDataBuff->fame = 0;
	// generate reputation
	rep_gen = grng->random(100) + 1;

	if (rep_gen >= 60)
	{
		if (rep_gen >= 90)
		{
			if (rep_gen >= 95)
			{
				if (rep_gen >= 98)
					pNPCDataBuff->rep = -600;
				else
					pNPCDataBuff->rep = 400;
			}
			else
			{
				pNPCDataBuff->rep = -300;
			}
		}
		else
		{
			pNPCDataBuff->rep = 200;
		}
	}
	else
	{
		pNPCDataBuff->rep = 0;
	}

	max_prof_cap = grng->random(pProfessionChance[uMapId].uTotalprofChance) + 1;
	test_prof_summ = 0;
	gen_profession = 0;

	if (max_prof_cap > 0)
	{
		do
		{
			test_prof_summ += pProfessionChance[uMapId]
				.professionChancePerArea[gen_profession++];
		} while (test_prof_summ < max_prof_cap);
	}
	pNPCDataBuff->profession = (NPCProf)(gen_profession - 1);
	pNPCDataBuff->Location2D = uLocation2D;
	pNPCDataBuff->field_24 = 1;
	pNPCDataBuff->is_joinable = 1;
	pNPCDataBuff->dialogue_1_evt_id = 0;
	pNPCDataBuff->dialogue_2_evt_id = 0;
	pNPCDataBuff->dialogue_3_evt_id = 0;
	pNPCDataBuff->dialogue_4_evt_id = 0;
	pNPCDataBuff->dialogue_5_evt_id = 0;
	pNPCDataBuff->dialogue_6_evt_id = 0;
}

//----- (00495366) --------------------------------------------------------
const char* NPCStats::sub_495366_MispronounceName(uint8_t firstLetter, uint8_t genderId)
{
	int pickedName;  // edx@2

	if (firstLetter == dword_AE336C_LastMispronouncedNameFirstLetter)
	{
		pickedName = dword_AE3370_LastMispronouncedNameResult;
	}
	else
	{
		dword_AE336C_LastMispronouncedNameFirstLetter = firstLetter;
		if (uNumNPCNames[genderId] == 0)
		{
			pickedName = vrng->random(uNumNPCNames[(genderId + 1) % 2]);
			// originally without " + 1) % 2", but
			// that would yield a div by zero
		}
		else
		{
			int rangeBottom = 0;
			int rangeTop = 0;
			for (uint i = 0; i < uNumNPCNames[genderId]; ++i)
			{
				if (tolower(pNPCNames[i][genderId][0]))
				{
					if (rangeBottom)
						rangeTop = i;
					else
						rangeBottom = i;
				}
			}
			if (rangeTop != 0)
				pickedName = rangeBottom + vrng->random(rangeTop - rangeBottom);
			else
				pickedName = vrng->random(uNumNPCNames[genderId]);
		}
	}
	dword_AE3370_LastMispronouncedNameResult = pickedName;
	return pNPCNames[pickedName][genderId].c_str();
}

//----- (00476387) --------------------------------------------------------
bool PartyHasDragon()
{
	return pNPCStats->pNewNPCData[57].Hired();
}

//----- (00476395) --------------------------------------------------------
// 0x26 Wizard eye at skill level 2
bool CheckHiredNPCSpeciality(NPCProf prof)
{
	if (bNoNPCHiring == 1) return false;

	for (uint i = 0; i < pNPCStats->uNumNewNPCs; ++i)
	{
		if (pNPCStats->pNewNPCData[i].profession == prof &&
			(pNPCStats->pNewNPCData[i].uFlags & 0x80))
		{
			return true;
		}
	}
	return pParty->pHirelings[0].profession == prof
		|| pParty->pHirelings[1].profession == prof;
}

//----- (004763E0) --------------------------------------------------------
void InitializeAwards()
{
	int i;
	char* test_string;
	unsigned char c;
	bool break_loop;
	unsigned int temp_str_len;
	char* tmp_pos;
	int decode_step;

	pAwardsTXT_Raw = pEvents_LOD->LoadCompressedTexture("awards.txt").string_view();
	strtok(pAwardsTXT_Raw.data(), "\r");

	for (i = 1; i < 105; ++i)
	{
		test_string = strtok(NULL, "\r") + 1;
		break_loop = false;
		decode_step = 0;
		do
		{
			c = *(unsigned char*)test_string;
			temp_str_len = 0;
			while ((c != '\t') && (c > 0))
			{
				++temp_str_len;
				c = test_string[temp_str_len];
			}
			tmp_pos = test_string + temp_str_len;
			if (*tmp_pos == 0) break_loop = true;
			*tmp_pos = 0;
			if (temp_str_len)
			{
				if (decode_step == 1)
					pAwards[i].pText = removeQuotes(test_string);
				else if (decode_step == 2)
					pAwards[i].uPriority = atoi(test_string);
			}
			else
			{
				break_loop = true;
			}
			++decode_step;
			test_string = tmp_pos + 1;
		} while ((decode_step < 3) && !break_loop);
	}
}
// 7241C8: using guessed type int dword_7241C8;

//----- (004764C2) --------------------------------------------------------
void InitializeScrolls()
{
	char* test_string;
	unsigned char c;
	bool break_loop;
	unsigned int temp_str_len;
	char* tmp_pos;
	int decode_step;

	pScrollsTXT_Raw = pEvents_LOD->LoadCompressedTexture("scroll.txt").string_view();
	strtok(pScrollsTXT_Raw.data(), "\r");
	for (ITEM_TYPE i : pScrolls.indices())
	{
		test_string = strtok(NULL, "\r") + 1;
		break_loop = false;
		decode_step = 0;
		do
		{
			c = *(unsigned char*)test_string;
			temp_str_len = 0;
			while ((c != '\t') && (c > 0))
			{
				++temp_str_len;
				c = test_string[temp_str_len];
			}
			tmp_pos = test_string + temp_str_len;
			if (*tmp_pos == 0) break_loop = true;
			*tmp_pos = 0;
			if (temp_str_len)
			{
				if (decode_step == 1) pScrolls[i] = removeQuotes(test_string);
			}
			else
			{
				break_loop = true;
			}
			++decode_step;
			test_string = tmp_pos + 1;
		} while ((decode_step < 2) && !break_loop);
	}
}

//----- (00476590) --------------------------------------------------------
void InitializeMerchants()
{
	char* test_string;
	unsigned char c;
	bool break_loop;
	unsigned int temp_str_len;
	char* tmp_pos;
	int decode_step;

	pMerchantsTXT_Raw = pEvents_LOD->LoadCompressedTexture("merchant.txt").string_view();
	strtok(pMerchantsTXT_Raw.data(), "\r");

	for (MERCHANT_PHRASE i : MerchantPhrases())
	{
		test_string = strtok(NULL, "\r") + 1;
		break_loop = false;
		decode_step = 0;
		do
		{
			c = *(unsigned char*)test_string;
			temp_str_len = 0;
			while ((c != '\t') && (c > 0))
			{
				++temp_str_len;
				c = test_string[temp_str_len];
			}
			tmp_pos = test_string + temp_str_len;
			if (*tmp_pos == 0) break_loop = true;
			*tmp_pos = 0;
			if (temp_str_len)
			{
				switch (decode_step)
				{
				case 1:
					pMerchantsBuyPhrases[i] = removeQuotes(test_string);
					break;
				case 2:
					pMerchantsSellPhrases[i] = removeQuotes(test_string);
					break;
				case 3:
					pMerchantsRepairPhrases[i] = removeQuotes(test_string);
					break;
				case 4:
					pMerchantsIdentifyPhrases[i] = removeQuotes(test_string);
					break;
				}
			}
			else
			{
				break_loop = true;
			}
			++decode_step;
			test_string = tmp_pos + 1;
		} while ((decode_step < 5) && !break_loop);
	}
}

//----- (00476682) --------------------------------------------------------
void InitializeTransitions()
{
	int i;
	char* test_string;
	unsigned char c;
	bool break_loop;
	unsigned int temp_str_len;
	char* tmp_pos;
	int decode_step;

	pTransitionsTXT_Raw = pEvents_LOD->LoadCompressedTexture("trans.txt").string_view();
	strtok(pTransitionsTXT_Raw.data(), "\r");

	for (i = 0; i < 464; ++i)
	{
		test_string = strtok(NULL, "\r") + 1;
		break_loop = false;
		decode_step = 0;
		do
		{
			c = *(unsigned char*)test_string;
			temp_str_len = 0;
			while ((c != '\t') && (c > 0))
			{
				++temp_str_len;
				c = test_string[temp_str_len];
			}
			tmp_pos = test_string + temp_str_len;
			if (*tmp_pos == 0) break_loop = true;
			*tmp_pos = 0;
			if (temp_str_len)
			{
				if (decode_step == 1)
					pTransitionStrings[i + 1] = removeQuotes(test_string);
			}
			else
			{
				break_loop = true;
			}
			++decode_step;
			test_string = tmp_pos + 1;
		} while ((decode_step < 2) && !break_loop);
	}
}

//----- (00476750) --------------------------------------------------------
void InitializeAutonotes()
{
	int i;
	char* test_string;
	unsigned char c;
	bool break_loop;
	unsigned int temp_str_len;
	char* tmp_pos;
	int decode_step;

	pAutonoteTXT_Raw = pEvents_LOD->LoadCompressedTexture("autonote.txt").string_view();
	strtok(pAutonoteTXT_Raw.data(), "\r");

	for (i = 0; i < 195; ++i)
	{
		test_string = strtok(NULL, "\r") + 1;
		break_loop = false;
		decode_step = 0;
		do
		{
			c = *(unsigned char*)test_string;
			temp_str_len = 0;
			while ((c != '\t') && (c > 0))
			{
				++temp_str_len;
				c = test_string[temp_str_len];
			}
			tmp_pos = test_string + temp_str_len;
			if (*tmp_pos == 0) break_loop = true;
			*tmp_pos = 0;
			if (temp_str_len)
			{
				switch (decode_step)
				{
				case 1:
					pAutonoteTxt[i + 1].pText = removeQuotes(test_string);
					break;
				case 2:
				{
					if (iequals(test_string, "potion"))
					{
						pAutonoteTxt[i + 1].eType = AUTONOTE_POTION_RECEPIE;
						break;
					}
					if (iequals(test_string, "stat"))
					{
						pAutonoteTxt[i + 1].eType = AUTONOTE_STAT_HINT;
						break;
					}
					if (iequals(test_string, "seer"))
					{
						pAutonoteTxt[i + 1].eType = AUTONOTE_SEER;
						break;
					}
					if (iequals(test_string, "obelisk"))
					{
						pAutonoteTxt[i + 1].eType = AUTONOTE_OBELISK;
						break;
					}
					if (iequals(test_string, "teacher"))
					{
						pAutonoteTxt[i + 1].eType = AUTONOTE_TEACHER;
						break;
					}
					pAutonoteTxt[i + 1].eType = AUTONOTE_MISC;
					break;
				}
				}
			}
			else
			{
				break_loop = true;
			}
			++decode_step;
			test_string = tmp_pos + 1;
		} while ((decode_step < 3) && !break_loop);
	}
}

//----- (004768A9) --------------------------------------------------------
void InitializeQuests()
{
	int i;
	char* test_string;
	unsigned char c;
	bool break_loop;
	unsigned int temp_str_len;
	char* tmp_pos;
	int decode_step;

	pQuestsTXT_Raw = pEvents_LOD->LoadCompressedTexture("quests.txt").string_view();
	strtok(pQuestsTXT_Raw.data(), "\r");
	memset(pQuestTable.data(), 0, sizeof(pQuestTable));
	for (i = 0; i < 512; ++i)
	{
		test_string = strtok(NULL, "\r") + 1;
		break_loop = false;
		decode_step = 0;
		do
		{
			c = *(unsigned char*)test_string;
			temp_str_len = 0;
			while ((c != '\t') && (c > 0))
			{
				++temp_str_len;
				c = test_string[temp_str_len];
			}
			tmp_pos = test_string + temp_str_len;
			if (*tmp_pos == 0) break_loop = true;
			*tmp_pos = 0;
			if (temp_str_len)
			{
				if (decode_step == 1)
					pQuestTable[i + 1] = removeQuotes(test_string);
			}
			else
			{
				break_loop = true;
			}
			++decode_step;
			test_string = tmp_pos + 1;
		} while ((decode_step < 2) && !break_loop);
	}
}

//----- (004B40E6) --------------------------------------------------------
void NPCHireableDialogPrepare()
{
	signed int v0;  // ebx@1
	NPCData* v1;    // edi@1

	v0 = 0;
	v1 = HouseNPCData[pDialogueNPCCount + -(dword_591080 != 0)];  //- 1
	pDialogueWindow->Release();
	pDialogueWindow = new GUIWindow(WINDOW_Dialogue, { 0, 0 }, { render->GetRenderDimensions().w, 350 }, 0);
	pBtn_ExitCancel = pDialogueWindow->CreateButton({ 471, 445 }, { 169, 35 }, 1, 0,
		UIMSG_Escape, 0, InputAction::Invalid, localization->GetString(LSTR_CANCEL), { ui_exit_cancel_button_background }
	);
	pDialogueWindow->CreateButton({ 0, 0 }, { 0, 0 }, 1, 0, UIMSG_BuyInShop_Identify_Repair, 0);
	if (!pNPCStats->pProfessions[v1->profession].pBenefits.empty())
	{
		pDialogueWindow->CreateButton({ 480, 160 }, { 140, 30 }, 1, 0,
			UIMSG_ClickNPCTopic, DIALOGUE_PROFESSION_DETAILS, InputAction::Invalid, localization->GetString(LSTR_MORE_INFORMATION)
		);
		v0 = 1;
	}
	pDialogueWindow->CreateButton({ 480, 30 * v0 + 160 }, { 140, 30 }, 1, 0,
		UIMSG_ClickNPCTopic, DIALOGUE_HIRE_FIRE, InputAction::Invalid, localization->GetString(LSTR_HIRE));
	pDialogueWindow->_41D08F_set_keyboard_control_group(v0 + 1, 1, 0, 2);
	dialog_menu_id = DIALOGUE_OTHER;
}

//----- (004B4224) --------------------------------------------------------
void _4B4224_UpdateNPCTopics(int _this)
{
	int num_menu_buttons;  // ebx@1
	int i;                 // ebp@5
	// signed int v4; // ebp@9
	NPCData* v17;          // [sp+10h] [bp-4h]@4

	num_menu_buttons = 0;
	pDialogueNPCCount = (_this + 1);
	Sizei renDims = render->GetRenderDimensions();
	if (_this + 1 == uNumDialogueNPCPortraits && uHouse_ExitPic)
	{
		pDialogueWindow->Release();
		pDialogueWindow = new GUIWindow(WINDOW_Dialogue, { 0, 0 }, renDims, 0);
		transition_button_label = localization->FormatString(LSTR_FMT_ENTER_S, pMapStats->pInfos[uHouse_ExitPic].pName.c_str()
		);
		pBtn_ExitCancel = pDialogueWindow->CreateButton({ 566, 445 }, { 75, 33 }, 1, 0,
			UIMSG_Escape, 0, InputAction::No, localization->GetString(LSTR_CANCEL), { ui_buttdesc2 });
		pBtn_YES = pDialogueWindow->CreateButton({ 486, 445 }, { 75, 33 }, 1, 0,
			UIMSG_BF, 1, InputAction::Yes, transition_button_label.c_str(), { ui_buttyes2 });
		pDialogueWindow->CreateButton({ pNPCPortraits_x[0][0], pNPCPortraits_y[0][0] }, { 63, 73 }, 1, 0,
			UIMSG_BF, 1, InputAction::EventTrigger, transition_button_label.c_str());
		pDialogueWindow->CreateButton({ 8, 8 }, { 460, 344 }, 1, 0,
			UIMSG_BF, 1, InputAction::Yes, transition_button_label.c_str()
		);
	}
	else
	{
		v17 = HouseNPCData[_this + 1 - ((dword_591080 != 0) ? 1 : 0)];  //+ 1
		if (dialog_menu_id == DIALOGUE_OTHER)
		{
			pDialogueWindow->Release();
		}
		else
		{
			for (i = 0; i < uNumDialogueNPCPortraits; ++i)
				HouseNPCPortraitsButtonsList[i]->Release();
		}
		pDialogueWindow = new GUIWindow(WINDOW_Dialogue, { 0, 0 }, { renDims.w, 345 }, 0);
		pBtn_ExitCancel = pDialogueWindow->CreateButton({ 471, 445 }, { 169, 35 }, 1, 0,
			UIMSG_Escape, 0, InputAction::Invalid, localization->GetString(LSTR_END_CONVERSATION), { ui_exit_cancel_button_background }
		);
		pDialogueWindow->CreateButton({ 8, 8 }, { 450, 320 }, 1, 0, UIMSG_BuyInShop_Identify_Repair, 0);
		if (pDialogueNPCCount == 1 && dword_591080)
		{
			InitializaDialogueOptions(in_current_building_type);
		}
		else
		{
			if (v17->is_joinable)
			{
				num_menu_buttons = 1;
				pDialogueWindow->CreateButton({ 480, 160 }, { 140, 30 }, 1, 0, UIMSG_ClickNPCTopic, DIALOGUE_13_hiring_related);
			}

#define AddScriptedDialogueLine(EVENT_ID, MSG_PARAM) \
                if (EVENT_ID) { \
                    if (num_menu_buttons < 4) { \
                        int res = NPCDialogueEventProcessor(EVENT_ID); \
                        if (res == 1 || res == 2) \
                            pDialogueWindow->CreateButton({480, 160 + 30 * num_menu_buttons++}, {140, 30}, 1, 0, UIMSG_ClickNPCTopic, MSG_PARAM); \
                    } \
                }

			AddScriptedDialogueLine(v17->dialogue_1_evt_id, DIALOGUE_SCRIPTED_LINE_1);
			AddScriptedDialogueLine(v17->dialogue_2_evt_id, DIALOGUE_SCRIPTED_LINE_2);
			AddScriptedDialogueLine(v17->dialogue_3_evt_id, DIALOGUE_SCRIPTED_LINE_3);
			AddScriptedDialogueLine(v17->dialogue_4_evt_id, DIALOGUE_SCRIPTED_LINE_4);
			AddScriptedDialogueLine(v17->dialogue_5_evt_id, DIALOGUE_SCRIPTED_LINE_5);
			AddScriptedDialogueLine(v17->dialogue_6_evt_id, DIALOGUE_SCRIPTED_LINE_6);

			pDialogueWindow->_41D08F_set_keyboard_control_group(num_menu_buttons, 1, 0, 2);
			dword_F8B1E0 = pDialogueWindow->pNumPresenceButton;
		}
		dialog_menu_id = DIALOGUE_MAIN;
	}
}

//----- (004466C4) --------------------------------------------------------
// Quest NPC dialogue processor:
//      Margareth (id=504)
//          line1=7  Greetings
//          line2=9  Contest
//          line3=43 Tour On / Tour Off
//          line4=line5=line6=0
//      Lord Markham/Emerald Island
//          line1=1
//          line2=2
//          line3=3
//          line4=34
//          line5=187
int NPCDialogueEventProcessor(int npc_event_id, int entry_line)
{
	if (!npc_event_id) return 0;

	int event_index = 0;
	int evt_seq_num = entry_line;
	pSomeOtherEVT = pGlobalEVT.data();
	uSomeOtherEVT_NumEvents = uGlobalEVT_NumEvents;
	pSomeOtherEVT_Events = pGlobalEVT_Index;

	if (uSomeOtherEVT_NumEvents <= 0)
	{
		return 2;
	}

	int npc_activity = 1;
	bool ready_to_exit = false;
	do
	{
		auto& evt = pSomeOtherEVT_Events[event_index];
		if (evt.event_id == npc_event_id && evt.event_step == evt_seq_num)
		{
			_evt_raw* _evt = (_evt_raw*)&pSomeOtherEVT[evt.uEventOffsetInEVT];
			switch (_evt->_e_type)
			{
			case EVENT_Exit:
				if (ready_to_exit)
					return npc_activity != 0;
				else
					return 2;

			case EVENT_OnCanShowDialogItemCmp:
				ready_to_exit = true;
				for (Player& player : pParty->pPlayers)
				{
					if (player.CompareVariable((enum VariableType)EVT_WORD(_evt->v5), EVT_DWORD(_evt->v7)))
					{
						event_index = -1;
						evt_seq_num = EVT_BYTE(_evt->v11) - 1;
						break;
					}
				}
				break;

			case EVENT_EndCanShowDialogItem:
				if (ready_to_exit)
					return npc_activity != 0;
				else
					return 2;

			case EVENT_SetCanShowDialogItem:
				ready_to_exit = true;
				npc_activity = EVT_BYTE(_evt->v5);
				break;

			case EVENT_IsActorAssasinated:
				if (IsActorAlive(
					EVT_BYTE(_evt->v5), EVT_DWORD(_evt->v6),
					EVT_BYTE(_evt->v10)))
				{  // drop linear sequence,
				  // going to new seq
					event_index = -1;
					evt_seq_num = EVT_BYTE(_evt->v11) - 1;
				}
				break;
			}
			++evt_seq_num;
		}
		++event_index;
	} while (event_index < uSomeOtherEVT_NumEvents);

	if (ready_to_exit)
		return npc_activity != 0;
	else
		return 2;
}
//----- (00445C8B) --------------------------------------------------------
int GetGreetType(signed int SpeakingNPC_ID)
{
	if (SpeakingNPC_ID >= 0)
	{
		if (SpeakingNPC_ID < 5000) return 1;  // QuestNPC_greet
		return 2;                             // HiredNPC_greet
	}

	if (SpeakingNPC_ID >= 5000) return 2;

	int v3 = abs((int)sDialogue_SpeakingActorNPC_ID) - 1;

	FlatHirelings buf;
	buf.Prepare();

	return buf.IsFollower(v3) ? 1 : 2;
}

//----- (00445308) --------------------------------------------------------
const char* GetProfessionActionText(NPCProf prof)
{
	switch (prof)
	{
	case Healer:
	case ExpertHealer:
	case MasterHealer:
	case Cook:
	case Chef:
	case WindMaster:
	case WaterMaster:
	case GateMaster:
	case Chaplain:
	case Piper:
	case FallenWizard:
		return pNPCStats->pProfessions[prof].pActionText.c_str();
	default:
		return pNPCTopics[407].pTopic.c_str();
	}
}

//----- (004BB756) --------------------------------------------------------
int UseNPCSkill(NPCProf profession, int id)
{
	switch (profession)
	{
	case Healer:
	{
		for (Player& player : pParty->pPlayers)
		{
			player.sHealth = player.GetMaxHealth();
		}
	} break;

	case ExpertHealer:
	{
		for (Player& player : pParty->pPlayers)
		{
			player.sHealth = player.GetMaxHealth();

			for (Condition condition : standardConditionsExcludeDead)
			{
				player.conditions.Reset(condition);
			}
		}
	} break;

	case MasterHealer:
	{
		for (Player& player : pParty->pPlayers)
		{
			player.sHealth = player.GetMaxHealth();

			for (Condition condition : standardConditionsIncludeDead)
			{
				// Master healer heals all except Eradicated and zombie
				if (condition != Condition_Eradicated)
				{
					player.conditions.Reset(condition);
				}
			}
		}
	} break;

	case Cook:
	{
		// Was 13
		if (pParty->GetFood() >= 14)
		{
			return 1;
		}

		pParty->GiveFood(1);
	} break;

	case Chef:
	{
		// Was 13
		if (pParty->GetFood() >= 14)
		{
			return 1;
		}

		if (pParty->GetFood() == 13)
		{
			pParty->GiveFood(1);
		}
		else
		{
			pParty->GiveFood(2);
		}
	} break;

	case WindMaster:
	{
		if (uCurrentlyLoadedLevelType == WorldType::Indoor)
		{
			GameUI_SetStatusBar(LSTR_CANT_FLY_INDOORS);
			pAudioPlayer->playUISound(SOUND_fizzle);
		}
		else
		{
			int v19 = pOtherOverlayList->_4418B1(10008, 203, 0, 65536);
			// Spell power was changed to 0 because it does not have meaning for this buff
			pParty->pPartyBuffs[PARTY_BUFF_FLY]
				.Apply(pParty->GetPlayingTime() + GameTime::FromHours(2), PLAYER_SKILL_MASTERY_MASTER, 0, v19, 0);
			// Mark buff as GM because NPC buff does not drain mana
			pParty->pPartyBuffs[PARTY_BUFF_FLY].isGMBuff = true;
			pAudioPlayer->playSpellSound(SPELL_AIR_FLY, 0, false);
		}
	} break;

	case WaterMaster:
	{
		int v20 = pOtherOverlayList->_4418B1(10005, 201, 0, 65536);
		pParty->pPartyBuffs[PARTY_BUFF_WATER_WALK]
			.Apply(pParty->GetPlayingTime() + GameTime::FromHours(3), PLAYER_SKILL_MASTERY_MASTER, 0, v20, 0);
		// Mark buff as GM because NPC buff does not drain mana
		pParty->pPartyBuffs[PARTY_BUFF_WATER_WALK].isGMBuff = true;
		pAudioPlayer->playSpellSound(SPELL_WATER_WATER_WALK, 0, false);
	} break;

	case GateMaster:
	{
		pCurrentFrameMessageQueue->AddGUIMessage(UIMSG_Escape, 0, 0);
		pNextFrameMessageQueue->AddGUIMessage(UIMSG_OnCastTownPortal, PID(OBJECT_Player, pParty->pPlayers.size() + id), 0);
	} break;

	case Chaplain:
		pushNPCSpell(SPELL_SPIRIT_BLESS);
		break;
	case Piper:
		pushNPCSpell(SPELL_SPIRIT_HEROISM);
		break;
	case FallenWizard:
		pushNPCSpell(SPELL_LIGHT_HOUR_OF_POWER);
		break;

	case Teacher:
	case Instructor:
	case Armsmaster:
	case Weaponsmaster:
	case Apprentice:
	case Mystic:
	case Spellmaster:
	case Trader:
	case Merchant:
	case Scout:
	case Herbalist:
	case Apothecary:
	case Tinker:
	case Locksmith:
	case Fool:
	case ChimneySweep:
	case Porter:
	case QuarterMaster:
	case Factor:
	case Banker:
	case Horseman:
	case Bard:
	case Enchanter:
	case Cartographer:
	case Explorer:
	case Pirate:
	case Squire:
	case Psychic:
	case Gypsy:
	case Diplomat:
	case Duper:
	case Burglar:
	case Acolyte:
	case Initiate:
	case Prelate:
	case Monk:
	case Sage:
	case Hunter:
		break;

	default:
		assert(false && "Invalid enum value");
	}
	return 0;
}

void FlatHirelings::Prepare()
{
	count = 0;

	for (size_t i = 0; i < 2; ++i)
		if (!pParty->pHirelings[i].pName.empty())
			ids[count++] = i;

	for (size_t i = 0; i < pNPCStats->uNumNewNPCs; ++i)
	{
		NPCData* npc = &pNPCStats->pNewNPCData[i];
		if (npc->Hired())
		{
			Assert(!npc->pName.empty()); // Important for the checks below.

			if (npc->pName != pParty->pHirelings[0].pName && npc->pName != pParty->pHirelings[1].pName)
			{
				Assert(i + 2 < 256); // Won't fit into uint8_t otherwise.
				ids[count++] = i + 2;
			}
		}
	}
}

bool FlatHirelings::IsFollower(size_t index) const
{
	Assert(index < count);

	return ids[index] >= 2;
}

NPCData* FlatHirelings::Get(size_t index) const
{
	Assert(index < count);

	uint8_t id = ids[index];

	if (id < 2)
		return &pParty->pHirelings[id];
	else
		return &pNPCStats->pNewNPCData[id - 2];
}
