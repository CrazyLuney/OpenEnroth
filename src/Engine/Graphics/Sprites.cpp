#include "Engine/Graphics/Sprites.h"

#include "Engine/Engine.h"
#include "Engine/LOD.h"
#include "Engine/OurMath.h"

#include "Engine/Objects/Actor.h"

#include "Engine/Serialization/LegacyImages.h"

#include "Engine/Graphics/DecorationList.h"
#include "Engine/Graphics/PaletteManager.h"


struct SpriteFrameTable* pSpriteFrameTable;

//----- (0044D4F6) --------------------------------------------------------
void SpriteFrameTable::ResetLoadedFlags()
{
	for (size_t i = 0; i < uNumSpriteFrames; ++i)
	{
		pSpriteSFrames[i].uFlags &= ~0x80;
	}
}

//----- (0044D513) --------------------------------------------------------
void SpriteFrameTable::InitializeSprite(size_t uSpriteID)
{
	if (uSpriteID >= uNumSpriteFrames)
		return;

	std::string spriteName;

	uint iter_uSpriteID = uSpriteID;
	//if (iter_uSpriteID == 603) __debugbreak();

	int uFlags = pSpriteSFrames[iter_uSpriteID].uFlags;

	if (!(uFlags & 0x0080))
	{
		// not loaded
		pSpriteSFrames[iter_uSpriteID].uFlags |= 0x80;  // set loaded

		while (1)
		{
			pSpriteSFrames[iter_uSpriteID].ResetPaletteIndex(pPaletteManager->LoadPalette(pSpriteSFrames[iter_uSpriteID].uPaletteID));

			if (uFlags & 0x10)
			{
				// single frame per frame sequence
				auto v8 = pSprites_LOD->LoadSprite(pSpriteSFrames[iter_uSpriteID].texture_name.c_str(), pSpriteSFrames[iter_uSpriteID].uPaletteID);

				if (v8 == -1)
				{
					logger->warning("Sprite {} not loaded!", pSpriteSFrames[iter_uSpriteID].texture_name);
					for (uint i = 0; i < 8; ++i)
					{
						pSpriteSFrames[iter_uSpriteID].hw_sprites[i] = nullptr;
					}
				}
				else
				{
					for (uint i = 0; i < 8; ++i)
					{
						pSpriteSFrames[iter_uSpriteID].hw_sprites[i] = &pSprites_LOD->pHardwareSprites[v8];
					}
				}

			}
			else if (uFlags & 0x10000)
			{
				for (uint i = 0; i < 8; ++i)
				{
					switch (i)
					{
					case 3:
					case 4:
					case 5:
						spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "4";
						break;
					case 2:
					case 6:
						spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "2";
						break;
					case 0:
					case 1:
					case 7:
						spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "0";
						break;
					}
					auto v12 = pSprites_LOD->LoadSprite(spriteName.c_str(), pSpriteSFrames[iter_uSpriteID].uPaletteID);
					// pSpriteSFrames[iter_uSpriteID].pHwSpriteIDs[i]=v12;
					assert(v12 != -1);
					pSpriteSFrames[iter_uSpriteID].hw_sprites[i] = &pSprites_LOD->pHardwareSprites[v12];
				}

			}
			else if (uFlags & 0x40)
			{
				// part of monster fidgeting seq
				for (uint i = 0; i < 8; ++i)
				{
					switch (i)
					{
					case 0:
						spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "0";
						break;
					case 4:
						spriteName = pSpriteSFrames[iter_uSpriteID].texture_name;
						spriteName.erase(spriteName.size() - 3, 3);
						spriteName = spriteName + "stA4";
						break;
					case 3:
					case 5:
						spriteName = pSpriteSFrames[iter_uSpriteID].texture_name;
						spriteName.erase(spriteName.size() - 3, 3);
						spriteName = spriteName + "stA3";
						break;
					case 2:
					case 6:
						spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "2";
						break;
					case 1:
					case 7:
						spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "1";
						break;
					}
					auto v12 = pSprites_LOD->LoadSprite(spriteName.c_str(), pSpriteSFrames[iter_uSpriteID].uPaletteID);
					// pSpriteSFrames[iter_uSpriteID].pHwSpriteIDs[i]=v12;
					assert(v12 != -1);
					pSpriteSFrames[iter_uSpriteID].hw_sprites[i] = &pSprites_LOD->pHardwareSprites[v12];
				}
			}
			else
			{
				for (uint i = 0; i < 8; ++i)
				{
					if (((0x0100 << i) & pSpriteSFrames[iter_uSpriteID].uFlags))
					{
						// mirrors
						switch (i)
						{
						case 1:
							spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "7";
							break;
						case 2:
							spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "6";
							break;
						case 3:
							spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "5";
							break;
						case 4:
							spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "4";
							break;
						case 5:
							spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "3";
							break;
						case 6:
							spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "2";
							break;
						case 7:
							spriteName = pSpriteSFrames[iter_uSpriteID].texture_name + "1";
							break;
						}
					}
					else
					{
						// some names already passed through with codes attached
						if (strlen(pSpriteSFrames[iter_uSpriteID].texture_name.c_str()) < 7)
						{
							spriteName = fmt::format("{}{}", pSpriteSFrames[iter_uSpriteID].texture_name, i);
						}
						else
						{
							spriteName = pSpriteSFrames[iter_uSpriteID].texture_name;
							// __debugbreak();
						}
					}

					auto v12 = pSprites_LOD->LoadSprite(spriteName.c_str(), pSpriteSFrames[iter_uSpriteID].uPaletteID);
					// pSpriteSFrames[iter_uSpriteID].pHwSpriteIDs[i]=v12;
					assert(v12 != -1);
					pSpriteSFrames[iter_uSpriteID].hw_sprites[i] = &pSprites_LOD->pHardwareSprites[v12];
				}
			}

			if (!(pSpriteSFrames[iter_uSpriteID].uFlags & 1))
			{
				return;
			}
			++iter_uSpriteID;
		}
	}
}

//----- (0044D813) --------------------------------------------------------
int SpriteFrameTable::FastFindSprite(std::string_view pSpriteName)
{
	signed int result;  // eax@2

	int searchResult = BinarySearch(pSpriteName);
	if (searchResult < 0)
		result = 0;
	else
		result = this->pSpriteEFrames[searchResult];
	return result;
}

//----- (0044D83A) --------------------------------------------------------
int SpriteFrameTable::BinarySearch(std::string_view pSpriteName)
{
	SpriteFrame** result = std::lower_bound(pSpritePFrames.get(), pSpritePFrames.get() + uNumEFrames, pSpriteName,
		[](SpriteFrame* l, std::string_view r)
		{
			return iless(l->icon_name, r);
		}
	);

	if (iequals((*result)->icon_name, pSpriteName))
	{
		return std::distance(this->pSpritePFrames.get(), result);
	}
	else
	{
		return -1;
	}
}

//----- (0044D8D0) --------------------------------------------------------
SpriteFrame* SpriteFrameTable::GetFrame(unsigned int uSpriteID, unsigned int uTime)
{
	SpriteFrame* v4 = &pSpriteSFrames[uSpriteID];
	if (~v4->uFlags & 1 || !v4->uAnimLength)
		return v4;

	// uAnimLength / uAnimTime = actual number of frames in sprite
	for (uint t = (uTime / 8) % v4->uAnimLength; t > v4->uAnimTime; ++v4)
		t -= v4->uAnimTime;

	// TODO(pskelton): investigate and fix properly - dragon breath is missing last two frames??
	// quick fix so it doesnt return empty sprite
	while (v4->hw_sprites[0] == NULL)
	{
		//__debugbreak();
		--v4;
	}

	return v4;

	/*for (v4; v4->uAnimTime <= t; ++v4)

	  v6 = (uTime / 8) % v4->uAnimLength;
	  //v7 = uSpriteID;
	  for ( i = (char *)&v4->uAnimTime; ; i += 60 )
	  {
		v9 = *(short *)i;
		if ( v6 <= v9 )
		  break;
		v6 -= v9;
		++v7;
	  }
	  return &pSpriteSFrames[v7];*/
}

//----- (0044D91F) --------------------------------------------------------
SpriteFrame* SpriteFrameTable::GetFrameBy_x(unsigned int uSpriteID, signed int a3)
{
	SpriteFrame* v4;      // esi@1
	int16_t v5;           // ax@2
	int v6;               // ecx@3
	int v7;               // edx@3
	unsigned int v8;      // eax@3
	int v9;               // ecx@3
	char* i;              // edx@3
	int v11;              // esi@5
	SpriteFrame* result;  // eax@6

	v4 = &pSpriteSFrames[uSpriteID];
	if (v4->uFlags & 1 && (v5 = v4->uAnimLength) != 0)
	{
		v6 = v5;
		v7 = a3 % v5;
		v8 = uSpriteID;
		v9 = v6 - v7;
		for (i = (char*)&v4->uAnimTime;; i += 60)
		{
			v11 = *(short*)i;
			if (v9 <= v11) break;
			v9 -= v11;
			++v8;
		}
		result = &pSpriteSFrames[v8];
	}
	else
	{
		result = &pSpriteSFrames[uSpriteID];
	}
	return result;
}

// new
void SpriteFrameTable::ResetPaletteIndexes()
{
	for (size_t i = 0; i < uNumSpriteFrames; i++)
	{
		pSpriteSFrames[i].ResetPaletteIndex();
	}
}

void SpriteFrameTable::ToFile()
{
	FILE* file = fopen(MakeDataPath("data", "dsft.bin").c_str(), "wb");
	if (file == nullptr)
	{
		Error("Unable to save dsft.bin!");
	}
	fwrite(&uNumSpriteFrames, 4, 1, file);
	fwrite(&uNumEFrames, 4, 1, file);
	fwrite(pSpriteSFrames.get(), sizeof(SpriteFrame), uNumSpriteFrames, file);
	fwrite(pSpriteEFrames.get(), sizeof(uint16_t), uNumEFrames, file);
	fclose(file);
}

//----- (0044D9D7) --------------------------------------------------------
void SpriteFrameTable::FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8)
{
#pragma pack(push, 1)
	struct SpriteFrameTableHeader final
	{
		uint32_t num_frames;
		uint32_t num_eframes;
	};
#pragma pack(pop)

	size_t mm6_num_frames = 0;
	size_t mm6_num_eframes = 0;
	if (data_mm6)
	{
		const auto& header = *data_mm6.data_view<SpriteFrameTableHeader>(0);

		mm6_num_frames = header.num_frames;
		mm6_num_eframes = header.num_eframes;
	}

	size_t mm7_num_frames = 0;
	size_t mm7_num_eframes = 0;
	if (data_mm7)
	{
		const auto& header = *data_mm7.data_view<SpriteFrameTableHeader>(0);

		mm7_num_frames = header.num_frames;
		mm7_num_eframes = header.num_eframes;
	}

	size_t mm8_num_frames = 0;
	size_t mm8_num_eframes = 0;
	if (data_mm8)
	{
		const auto& header = *data_mm8.data_view<SpriteFrameTableHeader>(0);

		mm8_num_frames = header.num_frames;
		mm8_num_eframes = header.num_eframes;
	}

	uNumSpriteFrames = mm7_num_frames;
	uNumEFrames = mm7_num_eframes;

	pSpriteSFrames = std::make_unique<SpriteFrame[]>(uNumSpriteFrames);
	pSpritePFrames = std::make_unique<SpriteFrame*[]>(uNumEFrames);
	pSpriteEFrames = std::make_unique<uint16_t[]>(uNumEFrames);

	if (data_mm7)
	{
		auto mm7_sprites_data = data_mm7.data_view<data::mm7::SpriteFrame>(sizeof(SpriteFrameTableHeader));
		for (size_t i = 0; i < mm7_num_frames; ++i)
		{
			Deserialize(mm7_sprites_data[i], &pSpriteSFrames[i]);
		}

		auto mm7_eframes_data = data_mm7.data_view<uint16_t>(sizeof(SpriteFrameTableHeader) + mm7_num_frames * sizeof(data::mm7::SpriteFrame));
		std::copy_n(mm7_eframes_data, mm7_num_eframes, pSpriteEFrames.get());

		for (size_t i = 0; i < mm7_num_eframes; ++i)
		{
			pSpritePFrames[i] = &pSpriteSFrames[pSpriteEFrames[i]];
		}
	}
}

SpriteFrame* LevelDecorationChangeSeason(const DecorationDesc* desc, int t, int month)
{
	switch (month/*pParty->uCurrentMonth*/)
	{
		// case 531 (tree60), 536 (tree65), 537 (tree66) have no autumn/winter
		// sprites
	case 11:
	case 0:
	case 1:  // winter
	{
		switch (desc->uSpriteID)
		{
			// case 468:           //bush02    grows on swamps, which are
			// evergreeen actually
		case 548:  // flower10
		case 547:  // flower09
		case 541:  // flower03
		case 539:  // flower01
			return nullptr;

		case 483:  // tree01
		case 486:  // tree04
		case 492:  // tree10
		{
			pSpriteFrameTable->InitializeSprite(desc->uSpriteID + 2);
			return pSpriteFrameTable->GetFrame(desc->uSpriteID + 2, t);
		}

		default:
			return pSpriteFrameTable->GetFrame(desc->uSpriteID, t);
		}
	}

	case 2:
	case 3:
	case 4:  // spring
	{
		// switch (desc->uSpriteID) {}
		return pSpriteFrameTable->GetFrame(desc->uSpriteID, t);
	}

	case 8:
	case 9:
	case 10:  // autumn
	{
		switch (desc->uSpriteID)
		{
			// case 468: //bush02    grows on swamps, which are evergreeen
			// actually
		case 548:  // flower10
		case 547:  // flower09
		case 541:  // flower03
		case 539:  // flower01
			return nullptr;

		case 483:  // tree01
		case 486:  // tree04
		case 492:  // tree10
		{
			pSpriteFrameTable->InitializeSprite(desc->uSpriteID + 1);
			return pSpriteFrameTable->GetFrame(desc->uSpriteID + 1, t);
		}

		default:
			return pSpriteFrameTable->GetFrame(desc->uSpriteID, t);
		}
	} break;

	case 5:
	case 6:
	case 7:  // summer
		// all green by default
	{
		return pSpriteFrameTable->GetFrame(desc->uSpriteID, t);
	}

	default:
		assert(/*pParty->uCurrentMonth*/month >= 0 && /*pParty->uCurrentMonth*/month < 12);
	}
	logger->warning("No sprite returned - LevelDecorationChangeSeason!");
	return nullptr;
}

int SpriteFrame::GetPaletteIndex()
{
	if (!engine->config->graphics.HWLSprites.value())
	{
		if (uPaletteIndex == 0)
			uPaletteIndex = pPaletteManager->LoadPalette(uPaletteID);
		return uPaletteIndex;
	}
	return 0;
}

void SpriteFrame::ResetPaletteIndex(int index)
{
	this->uPaletteIndex = index;
}
