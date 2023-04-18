#include "Engine/Tables/IconFrameTable.h"

#include "Engine/Engine.h"
#include "Engine/Graphics/IRender.h"
#include "Engine/Serialization/LegacyImages.h"


#include "../LOD.h"


Texture* Icon::GetTexture()
{
	if (!this->img)
	{
		this->img = assets->GetImage_ColorKey(this->pTextureName);
	}

	return this->img;
}

Icon* IconFrameTable::GetIcon(unsigned int idx)
{
	if (idx < this->uNumIcons) return &this->pIcons[idx];
	return nullptr;
}

Icon* IconFrameTable::GetIcon(const char* pIconName)
{
	for (unsigned int i = 0; i < this->uNumIcons; i++)
	{
		if (iequals(pIconName, this->pIcons[i].GetAnimationName()))
			return &this->pIcons[i];
	}
	return nullptr;
}

//----- (00494F3A) --------------------------------------------------------
unsigned int IconFrameTable::FindIcon(const char* pIconName)
{
	for (uint i = 0; i < (signed int)this->uNumIcons; i++)
	{
		if (iequals(pIconName, this->pIcons[i].GetAnimationName()))
			return i;
	}
	return 0;
}

//----- (00494F70) --------------------------------------------------------
Icon* IconFrameTable::GetFrame(unsigned int uIconID, unsigned int frame_time)
{
	//    int v6; // edx@3
	uint i;

	if (this->pIcons[uIconID].uFlags & 1 &&
		this->pIcons[uIconID].GetAnimLength() != 0)
	{
		uint t = frame_time;

		t = (t /*/ 8*/) %
			(uint16_t)this->pIcons[uIconID].GetAnimLength();
		t /= 8;
		for (i = uIconID; t > this->pIcons[i].GetAnimTime(); i++)
			t -= this->pIcons[i].GetAnimTime();
		return &this->pIcons[i];
	}
	else
	{
		return &this->pIcons[uIconID];
	}
}

//----- (00494FBF) --------------------------------------------------------
void IconFrameTable::InitializeAnimation(unsigned int uIconID)
{
	if (uIconID && (signed int)uIconID <= (signed int)this->uNumIcons)
	{
		for (uint i = uIconID;; ++i)
		{
			if (!(this->pIcons[i].uFlags & 1))
			{
				break;
			}
		}
	}
}

//----- (0049500A) --------------------------------------------------------
void IconFrameTable::ToFile()
{
	FILE* v2 = fopen(MakeDataPath("data", "dift.bin").c_str(), "wb");
	if (!v2)
		Error("Unable to save dift.bin!");
	fwrite(&uNumIcons, sizeof(uNumIcons), 1, v2);
	fwrite(pIcons.get(), sizeof(Icon), uNumIcons, v2);
	fclose(v2);
}

//----- (00495056) --------------------------------------------------------
void IconFrameTable::FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8)
{
#pragma pack(push, 1)
	struct IconFrameTableHeader final
	{
		uint32_t num_frames;
	};
#pragma pack(pop)

	size_t mm6_num_frames = 0;
	if (data_mm6)
	{
		const auto& header = *data_mm6.data_view<IconFrameTableHeader>();

		mm6_num_frames = header.num_frames;
	}

	size_t mm7_num_frames = 0;
	if (data_mm7)
	{
		const auto& header = *data_mm7.data_view<IconFrameTableHeader>();

		mm7_num_frames = header.num_frames;
	}

	size_t mm8_num_frames = 0;
	if (data_mm8)
	{
		const auto& header = *data_mm8.data_view<IconFrameTableHeader>();

		mm8_num_frames = header.num_frames;
	}

	uNumIcons = mm7_num_frames;

	pIcons = std::make_unique<Icon[]>(uNumIcons);

	if (data_mm7)
	{
		auto mm7_frames_data = data_mm7.data_view<data::mm7::IconFrame>(sizeof(IconFrameTableHeader));
		for (size_t i = 0; i < mm7_num_frames; ++i)
		{
			Deserialize(mm7_frames_data[i], &pIcons[i]);

			pIcons[i].id = i;
		}
	}
}

/*
//----- (0042EB78) --------------------------------------------------------
int IconFrameTable::GetIconAnimLength(unsigned int uIconID)
{
  return 8 * this->pIcons[uIconID].uAnimLength;
}*/
