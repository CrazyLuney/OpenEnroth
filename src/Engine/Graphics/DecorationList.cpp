#include "Engine/Graphics/DecorationList.h"
#include "Engine/stru123.h"
#include "Engine/Engine.h"
#include "Engine/Serialization/Deserializer.h"
#include "Engine/Serialization/LegacyImages.h"
#include "Level/Decoration.h"
#include "Sprites.h"

DecorationList* pDecorationList;

//----- (0045864C) --------------------------------------------------------
void DecorationList::FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8)
{
#pragma pack(push, 1)
	struct DecorationsListHeader
	{
		uint32_t num_decorations;
	};
#pragma pack(pop)

	size_t mm6_num_decorations = 0;
	if (data_mm6)
	{
		const auto& header = *data_mm6.data_view<DecorationsListHeader>();

		mm6_num_decorations = header.num_decorations;
	}

	size_t mm7_num_decorations = 0;
	if (data_mm7)
	{
		const auto& header = *data_mm7.data_view<DecorationsListHeader>();

		mm7_num_decorations = header.num_decorations;
	}

	size_t mm8_num_decorations = 0;
	if (data_mm8)
	{
		const auto& header = *data_mm8.data_view<DecorationsListHeader>();

		mm8_num_decorations = header.num_decorations;
	}

	uNumDecorations = mm6_num_decorations + mm7_num_decorations + mm8_num_decorations;

	pDecorations = std::make_unique<DecorationDesc[]>(uNumDecorations);

	auto decorations = pDecorations.get();

	if (data_mm6)
	{
		auto mm6_decorations_data = data_mm6.data_view<data::mm6::DecorationDesc>(sizeof(DecorationsListHeader));
		for (size_t i = 0; i < mm6_num_decorations; ++i)
		{
			Deserialize(mm6_decorations_data[i], &decorations[i]);
		}

		decorations += mm6_num_decorations;
	}

	if (data_mm7)
	{
		auto mm7_decorations_data = data_mm7.data_view<data::mm7::DecorationDesc>(sizeof(DecorationsListHeader));
		for (size_t i = 0; i < mm7_num_decorations; ++i)
		{
			Deserialize(mm7_decorations_data[i], &decorations[i]);
		}

		decorations += mm7_num_decorations;
	}

	if (data_mm8)
	{
		auto mm8_decorations_data = data_mm8.data_view<data::mm8::DecorationDesc>(sizeof(DecorationsListHeader));
		for (size_t i = 0; i < mm8_num_decorations; ++i)
		{
			Deserialize(mm8_decorations_data[i], &decorations[i]);
		}

		decorations += mm8_num_decorations;
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

	fwrite(&uNumDecorations, sizeof(uNumDecorations), 1, file);
	fwrite(pDecorations.get(), sizeof(DecorationDesc), uNumDecorations, file);
	fclose(file);
}

uint16_t DecorationList::GetDecorIdByName(std::string_view pName)
{
	if (pName.empty())
		return 0;

	if (uNumDecorations > 1)
	{
		for (size_t uID = 1; uID < uNumDecorations; ++uID)
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
					stru_5E4C90_MapPersistVars._decor_events[decorEventIdx++] = decor->GetGlobalEvent();
				}
			}
		}
	}
}
