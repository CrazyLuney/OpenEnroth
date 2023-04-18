#include "Engine/Tables/PlayerFrameTable.h"

#include "Engine/Engine.h"

#include "Library/Random/Random.h"


//----- (00494AED) --------------------------------------------------------
unsigned int PlayerFrameTable::GetFrameIdByExpression(CHARACTER_EXPRESSION_ID expression)
{
	for (uint i = 0; i < this->uNumFrames; i++)
	{
		if (this->pFrames[i].expression == expression) return i;
	}
	return 0;
}

//----- (00494B10) --------------------------------------------------------
PlayerFrame* PlayerFrameTable::GetFrameBy_x(unsigned int uFramesetID, unsigned int uFrameID)
{
	unsigned int v3;      // esi@1
	int16_t v6;           // dx@2
	int v7;               // edx@3
	char* i;              // eax@3
	int v9;               // ecx@5
	PlayerFrame* result;  // eax@6

	v3 = uFramesetID;
	if (this->pFrames[uFramesetID].uFlags & 1 &&
		(v6 = this->pFrames[uFramesetID].uAnimLength) != 0)
	{
		v7 = ((signed int)uFrameID >> 3) % (uint16_t)v6;
		for (i = (char*)&this->pFrames[uFramesetID].uAnimTime;; i += 10)
		{
			v9 = *(short*)i;
			if (v7 <= v9) break;
			v7 -= v9;
			++v3;
		}
		result = &this->pFrames[v3];
	}
	else
	{
		result = &this->pFrames[uFramesetID];
	}

	return result;
}

//----- (00494B5E) --------------------------------------------------------
PlayerFrame* PlayerFrameTable::GetFrameBy_y(int* pFramesetID, int* pAnimTime, int a4)
{
	int v5;  // esi@1
	int v6;  // eax@2

	v5 = a4 + *pAnimTime;
	if (v5 < 8 * this->pFrames[*pFramesetID].uAnimTime)
	{
		*pAnimTime = v5;
	}
	else
	{
		v6 = vrng->random(4) + 21;
		*pFramesetID = v6;
		*pAnimTime = 8 * v5 % this->pFrames[v6].uAnimTime;
	}
	return &this->pFrames[*pFramesetID];
}

//----- (00494BC3) --------------------------------------------------------
void PlayerFrameTable::ToFile()
{
	FILE* v2 = fopen(MakeDataPath("data", "dpft.bin").c_str(), "wb");
	if (!v2)
		Error("Unable to save dpft.bin");
	fwrite(&uNumFrames, sizeof(uNumFrames), 1, v2);
	fwrite(pFrames.get(), sizeof(PlayerFrame), uNumFrames, v2);
	fclose(v2);
}

//----- (00494C0F) --------------------------------------------------------
void PlayerFrameTable::FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8)
{
#pragma pack(push, 1)
	struct PlayerFrameTableHeader
	{
		uint32_t num_frames;
	};
#pragma pack(pop)

	size_t mm6_num_frames = 0;
	if (data_mm6)
	{
		const auto& header = *data_mm6.data_view<PlayerFrameTableHeader>();

		mm6_num_frames = header.num_frames;
	}

	size_t mm7_num_frames = 0;
	if (data_mm7)
	{
		const auto& header = *data_mm7.data_view<PlayerFrameTableHeader>();

		mm7_num_frames = header.num_frames;
	}

	size_t mm8_num_frames = 0;
	if (data_mm8)
	{
		const auto& header = *data_mm8.data_view<PlayerFrameTableHeader>();

		mm8_num_frames = header.num_frames;
	}

	uNumFrames = mm7_num_frames;

	pFrames = std::make_unique<PlayerFrame[]>(uNumFrames);

	if (data_mm7)
	{
		auto mm7_frames_data = data_mm7.data_view<PlayerFrame>(sizeof(PlayerFrameTableHeader));
		std::copy_n(mm7_frames_data, mm7_num_frames, pFrames.get());
	}
}
