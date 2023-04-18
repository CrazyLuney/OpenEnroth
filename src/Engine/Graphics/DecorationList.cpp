#include "Engine/Graphics/DecorationList.h"
#include "Engine/stru123.h"
#include "Engine/Engine.h"
#include "Level/Decoration.h"
#include "Sprites.h"

DecorationList* pDecorationList;

//----- (0045864C) --------------------------------------------------------
void DecorationList::FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8)
{
	size_t num_mm6_decs = data_mm6 ? *(uint32_t*)data_mm6.data() : 0;
	size_t num_mm7_decs = data_mm7 ? *(uint32_t*)data_mm7.data() : 0;
	size_t num_mm8_decs = data_mm8 ? *(uint32_t*)data_mm8.data() : 0;

	size_t uNumDecorations = num_mm6_decs + num_mm7_decs + num_mm8_decs;
	Assert(uNumDecorations);
	Assert(!num_mm8_decs);

	if (data_mm6)
	{
		auto mm6_decors = data_mm6.data_view<data::mm6::DecorationDesc>(4);
		for (size_t i = 0; i < num_mm6_decs; ++i)
		{
			data::mm7::DecorationDesc decor{ mm6_decors[i] };
			decor.uColoredLightRed = 255;
			decor.uColoredLightGreen = 255;
			decor.uColoredLightBlue = 255;
			decor.__padding = 255;
			pDecorations.emplace_back(decor);
		}
	}

	if (data_mm7)
	{
		auto mm7_decors = data_mm7.data_view<data::mm7::DecorationDesc>(4);
		for (size_t i = 0; i < num_mm7_decs; i++)
		{
			pDecorations.push_back(mm7_decors[i]);
		}
	}

	if (data_mm8)
	{
		auto mm8_decors = data_mm8.data_view<data::mm8::DecorationDesc>(4);
		for (size_t i = 0; i < num_mm8_decs; i++)
		{
			pDecorations.push_back(mm8_decors[i]);
		}
	}
}

void DecorationList::InitializeDecorationSprite(unsigned int uDecID)
{
	pSpriteFrameTable->InitializeSprite(this->pDecorations[uDecID].uSpriteID);
}

void DecorationList::ToFile()
{
	FILE* file = fopen(MakeDataPath("data", "ddeclist.bin").c_str(), "wb");
	if (file == nullptr)
	{
		Error("Unable to save ddeclist.bin!", 0);
	}

	uint32_t size = this->pDecorations.size();
	fwrite(&size, 4, 1, file);
	fwrite(&pDecorations[0], sizeof(DecorationDesc), pDecorations.size(), file);
	fclose(file);
}

uint16_t DecorationList::GetDecorIdByName(std::string_view pName)
{
	if (pName.empty())
		return 0;

	if (pDecorations.size() > 1)
	{
		for (uint uID = 1; uID < pDecorations.size(); ++uID)
		{
			if (iequals(pName, pDecorations[uID].pName))
				return uID;
		}
	}

	return 0;
}

void RespawnGlobalDecorations()
{
	memset(stru_5E4C90_MapPersistVars._decor_events.data(), 0, 125);

	uint decorEventIdx = 0;
	for (uint i = 0; i < pLevelDecorations.size(); ++i)
	{
		LevelDecoration* decor = &pLevelDecorations[i];

		if (!decor->uEventID)
		{
			if (decor->IsInteractive())
			{
				if (decorEventIdx < 124)
				{
					decor->_idx_in_stru123 = decorEventIdx + 75;
					stru_5E4C90_MapPersistVars._decor_events[decorEventIdx++] =
						decor->GetGlobalEvent();
				}
			}
		}
	}
}
