#include "Engine/Engine.h"

#include "Engine/Serialization/LegacyImages.h"

#include "Library/Random/Random.h"

#include "FrameTableInc.h"
#include "TileTable.h"


//----- (00487E3B) --------------------------------------------------------
TileDesc* TileTable::GetTileById(unsigned int uTileID)
{
	Assert(uTileID < sNumTiles);
	return &pTiles[uTileID];
}

//----- (00487E58) --------------------------------------------------------
void TileTable::InitializeTileset(Tileset tileset)
{
	for (int i = 0; i < sNumTiles; ++i)
	{
		if (pTiles[i].tileset == tileset && !pTiles[i].name.empty())
		{
			// pTiles[i].uBitmapID =
			// pBitmaps_LOD->LoadTexture(pTiles[i].pTileName); if
			// (pTiles[i].uBitmapID != -1)
			//    pBitmaps_LOD->pTextures[pTiles[i].uBitmapID].palette_id2 =
			//    pPaletteManager->LoadPalette(pBitmaps_LOD->pTextures[pTiles[i].uBitmapID].palette_id1);
		}
	}
}

//----- (00487ED6) --------------------------------------------------------
int TileTable::GetTileForTerrainType(signed int terrain_type, bool not_random)
{
	int v5;  // edx@3
	int v6;  // edx@11

	if (not_random || terrain_type > 8)
	{
		return GetTileId(terrain_type, 0);
	}
	v5 = vrng->random(50);
	if (v5 < 20)
	{
		return GetTileId(terrain_type, 0);
	}
	else if (v5 < 30)
	{
		return GetTileId(terrain_type, 1);
	}
	else if (v5 < 40)
	{
		return GetTileId(terrain_type, 2);
	}
	else if (v5 < 48)
	{
		return GetTileId(terrain_type, 3);
	}
	v6 = vrng->random(8);
	return GetTileId(terrain_type, v6 + 4);
}

//----- (00487F84) --------------------------------------------------------
unsigned int TileTable::GetTileId(unsigned int uTerrainType,
	unsigned int uSection)
{
	for (int i = 0; i < sNumTiles; ++i)
	{
		if ((pTiles[i].tileset == uTerrainType) &&
			(pTiles[i].uSection == uSection))
			return i;
	}
	return 0;
}

//----- (00487FB4) --------------------------------------------------------
void TileTable::ToFile()
{
	FILE* fp = fopen(MakeDataPath("data", "dtile.bin").c_str(), "wb");
	if (!fp)
		Error("Unable to save dtile.bin!");
	fwrite(&sNumTiles, sizeof(sNumTiles), 1u, fp);
	fwrite(pTiles.get(), sizeof(TileDesc), sNumTiles, fp);
	fclose(fp);
}

//----- (00488000) --------------------------------------------------------
void TileTable::FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8)
{
#pragma pack(push, 1)
	struct TileTableHeader final
	{
		uint32_t num_tiles;
	};
#pragma pack(pop)

	size_t mm6_num_tiles = 0;
	if (data_mm6)
	{
		const auto& header = *data_mm6.data_view<TileTableHeader>();

		mm6_num_tiles = header.num_tiles;
	}

	size_t mm7_num_tiles = 0;
	if (data_mm7)
	{
		const auto& header = *data_mm7.data_view<TileTableHeader>();

		mm7_num_tiles = header.num_tiles;
	}

	size_t mm8_num_tiles = 0;
	if (data_mm8)
	{
		const auto& header = *data_mm8.data_view<TileTableHeader>();

		mm8_num_tiles = header.num_tiles;
	}

	sNumTiles = mm7_num_tiles /*+ num_mm6_tiles + num_mm8_tiles*/;

	pTiles = std::make_unique<TileDesc[]>(sNumTiles);

	auto mm7_tiles_data = data_mm7.data_view<data::mm7::TileDesc>(sizeof(TileTableHeader));
	for (size_t i = 0; i < mm7_num_tiles; ++i)
	{
		Deserialize(mm7_tiles_data[i], &pTiles[i]);
	}

	// pTiles = (TileDesc *)malloc(sNumTiles * sizeof(TileDesc));
	// memcpy(pTiles, (char *)data_mm7 + 4, num_mm7_tiles * sizeof(TileDesc));
	// memcpy(pTiles + num_mm7_tiles, (char *)data_mm6 + 4, num_mm6_tiles *
	// sizeof(TileDesc)); memcpy(pTiles + num_mm6_tiles + num_mm7_tiles, (char
	// *)data_mm8 + 4, num_mm8_tiles * sizeof(TileDesc));
}

//----- (00488047) --------------------------------------------------------
int TileTable::FromFileTxt(const char* pFilename)
{
	FILE* v3;               // eax@1
	unsigned int v4;        // ebx@3
	uint16_t v6;    // ax@14
	const char* v7;         // ST14_4@14
	uint16_t v8;    // ax@14
	const char* v9;         // esi@14
	const char* v35;        // esi@67
	int j;                  // edi@152
	const char* v72;        // esi@153
	FILE* i;                // [sp-10h] [bp-304h]@3
	FILE* File;             // [sp+4h] [bp-2F0h]@1
	FrameTableTxtLine v84;  // [sp+8h] [bp-2ECh]@4
	FrameTableTxtLine v85;  // [sp+84h] [bp-270h]@4
	char Buf[490];          // [sp+100h] [bp-1F4h]@4

	sNumTiles = 0;
	pTiles.reset();

	v3 = fopen(pFilename, "r");
	File = v3;
	if (!v3) Error("TileTable::load - Unable to open file: %s.");
	v4 = 0;
	for (i = v3; fgets(Buf, sizeof(Buf), i); i = File)
	{
		*strchr(Buf, 10) = 0;
		memcpy(&v84, txt_file_frametable_parser(Buf, &v85), sizeof(v84));
		if (v84.uPropCount && *v84.pProperties[0] != 47) ++v4;
	}
	pTiles = std::make_unique<TileDesc[]>(v4);
	if (!pTiles) Error("TileTable::Load - Out of Memory!");
	memset(pTiles.get(), 0, sizeof(TileDesc) * v4);
	fseek(File, 0, 0);

	while (fgets(Buf, sizeof(Buf), File))
	{
		*strchr(Buf, 10) = 0;
		memcpy(&v84, txt_file_frametable_parser(Buf, &v85), sizeof(v84));
		if (v84.uPropCount)
		{
			if (*v84.pProperties[0] != 47)
			{
				// strcpy(pTiles[sNumTiles].pTileName, v84.pProperties[0]);
				v6 = atoi(v84.pProperties[1]);
				v7 = v84.pProperties[2];
				pTiles[sNumTiles].uTileID = v6;
				v8 = atoi(v7);
				v9 = v84.pProperties[3];
				// pTiles[sNumTiles].uBitmapID = v8;

				if (iequals(v9, "TTtype_NULL"))
				{
					pTiles[sNumTiles].tileset = Tileset_NULL;
				}
				else if (iequals(v9, "TTtype_Start"))
				{
					pTiles[sNumTiles].tileset = Tileset_Start;
				}
				else if (iequals(v9, "TTtype_Grass"))
				{
					pTiles[sNumTiles].tileset = Tileset_Grass;
				}
				else if (iequals(v9, "TTtype_Snow"))
				{
					pTiles[sNumTiles].tileset = Tileset_Snow;
				}
				else if (iequals(v9, "TTtype_Sand"))
				{
					pTiles[sNumTiles].tileset = Tileset_Desert;
				}
				else if (iequals(v9, "TTtype_Volcano"))
				{
					pTiles[sNumTiles].tileset = Tileset_CooledLava;
				}
				else if (iequals(v9, "TTtype_Dirt"))
				{
					pTiles[sNumTiles].tileset = Tileset_Dirt;
				}
				else if (iequals(v9, "TTtype_Water"))
				{
					pTiles[sNumTiles].tileset = Tileset_Water;
				}
				else if (iequals(v9, "TTtype_Cracked"))
				{
					pTiles[sNumTiles].tileset = Tileset_Badlands;
				}
				else if (iequals(v9, "TTtype_Swamp"))
				{
					pTiles[sNumTiles].tileset = Tileset_Swamp;
				}
				else if (iequals(v9, "TTtype_Tropical"))
				{
					pTiles[sNumTiles].tileset = Tileset_Tropical;
				}
				else if (iequals(v9, "TTtype_City"))
				{
					pTiles[sNumTiles].tileset = Tileset_City;
				}
				else if (iequals(v9, "TTtype_RoadGrassCobble"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadGrassCobble;
				}
				else if (iequals(v9, "TTtype_RoadGrassDirt"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadGrassDirt;
				}
				else if (iequals(v9, "TTtype_RoadSnowCobble"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadSnowCobble;
				}
				else if (iequals(v9, "TTtype_RoadSnowDirt"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadSnowDirt;
				}
				else if (iequals(v9, "TTtype_RoadSandCobble"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadSandCobble;
				}
				else if (iequals(v9, "TTtype_RoadSandDirt"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadSandDirt;
				}
				else if (iequals(v9, "TTtype_RoadVolcanoCobble"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadVolcanoCobble;
				}
				else if (iequals(v9, "TTtype_RoadVolcanoDirt"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadVolcanoDirt;
				}
				else if (iequals(v9, "TTtype_RoadCrackedCobble"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadCrackedCobble;
				}
				else if (iequals(v9, "TTtype_RoadCrackedDirt"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadCrackedDirt;
				}
				else if (iequals(v9, "TTtype_RoadSwampCobble"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadSwampCobble;
				}
				else if (iequals(v9, "TTtype_RoadSwampDirt"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadSwampDir;
				}
				else if (iequals(v9, "TTtype_RoadTropicalCobble"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadTropicalCobble;
				}
				else if (iequals(v9, "TTtype_RoadTropicalDirt"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadTropicalDirt;
				}
				else if (iequals(v9, "TTtype_RoadCityStone"))
				{
					pTiles[sNumTiles].tileset = Tileset_RoadCityStone;
				}
				else
				{
					logger->warning("Unknown tile type {}", v9);
				}

				v35 = v84.pProperties[4];

				// Default
				pTiles[sNumTiles].uSection = 0;
				pTiles[sNumTiles].uAttributes = 0;

				if (iequals(v35, "TTsect_NULL"))
				{
					pTiles[sNumTiles].uSection |= TILE_SECT_NULL;
				}
				else if (iequals(v35, "TTsect_Start"))
				{
					pTiles[sNumTiles].uSection |= TILE_SECT_Start;
				}
				else if (iequals(v35, "TTsect_Base1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Base1;
				}
				else if (iequals(v35, "TTsect_Base2"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Base2_NS;
				}
				else if (iequals(v35, "TTsect_Base3"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Base3_EW;
				}
				else if (iequals(v35, "TTsect_Base4"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Base4_N_E;
				}
				else if (iequals(v35, "TTsect_Special1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special1_N_W;
				}
				else if (iequals(v35, "TTsect_Special2"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special2_S_E;
				}
				else if (iequals(v35, "TTsect_Special3"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special3_S_W;
				}
				else if (iequals(v35, "TTsect_Special4"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special4_NS_E;
				}
				else if (iequals(v35, "TTsect_Special5"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special5_NS_W;
				}
				else if (iequals(v35, "TTsect_Special6"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special6_EW_N;
				}
				else if (iequals(v35, "TTsect_Special7"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special7_EW_S;
				}
				else if (iequals(v35, "TTsect_Special8"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special8_NCAP;
				}
				else if (iequals(v35, "TTsect_NE1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_NE1_SE1_ECAP;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_NW1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_NW1_SW1_WCAP;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_SE1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_NE1_SE1_ECAP;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_SW1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_NW1_SW1_WCAP;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_E1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_E1_DS;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_W1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_W1_DW;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_N1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_N1_DE;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_S1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_S1_DSW;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_XNE1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_XNE1_XSE1_DNE;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_XNW1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_XNW1_XSW1_DNW;
					pTiles[sNumTiles].uAttributes = TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_XSE1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_XNE1_XSE1_DNE;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_XSW1"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_XNW1_XSW1_DNW;
					pTiles[sNumTiles].uAttributes = TILE_DESC_TRANSITION;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_CROS"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Base1;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_NS"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Base2_NS;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_EW"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Base3_EW;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_N_E"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Base4_N_E;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_N_W"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special1_N_W;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_S_E"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special2_S_E;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_S_W"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special3_S_W;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_NS_E"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special4_NS_E;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_NS_W"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special5_NS_W;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_EW_N"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special6_EW_N;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_EW_S"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special7_EW_S;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_NCAP"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_Special8_NCAP;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_ECAP"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_NE1_SE1_ECAP;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_SCAP"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_SCAP;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_WCAP"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_NW1_SW1_WCAP;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_DN"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_DN;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_DS"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_E1_DS;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_DW"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_W1_DW;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_DE"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_N1_DE;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_DSW"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_S1_DSW;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_DNE"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_XNE1_XSE1_DNE;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_DSE"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_DSE;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}
				else if (iequals(v35, "TTsect_DNW"))
				{
					pTiles[sNumTiles].uSection = TILE_SECT_XNW1_XSW1_DNW;
					pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
				}

				for (j = 5; j < v84.uPropCount; ++j)
				{
					v72 = v84.pProperties[j];
					if (iequals(v84.pProperties[j], "TTattr_Burn"))
					{
						pTiles[sNumTiles].uAttributes |= TILE_DESC_BURN;
					}
					else if (iequals(v72, "TTattr_Water"))
					{
						pTiles[sNumTiles].uAttributes |= TILE_DESC_WATER;
					}
					else if (iequals(v72, "TTattr_Water2"))
					{
						pTiles[sNumTiles].uAttributes |= TILE_DESC_WATER_2;
					}
					else if (iequals(v72, "TTattr_Block"))
					{
						pTiles[sNumTiles].uAttributes |= TILE_DESC_BLOCK;
					}
					else if (iequals(v72, "TTattr_Repulse"))
					{
						pTiles[sNumTiles].uAttributes |= TILE_DESC_REPULSE;
					}
					else if (iequals(v72, "TTattr_Flat"))
					{
						pTiles[sNumTiles].uAttributes |= TILE_DESC_FLAT;
					}
					else if (iequals(v72, "TTattr_Wave"))
					{
						pTiles[sNumTiles].uAttributes |= TILE_DESC_WAVY;
					}
					else if (iequals(v72, "TTattr_NoDraw"))
					{
						pTiles[sNumTiles].uAttributes |= TILE_DESC_DONT_DRAW;
					}
					else if (iequals(v72, "TTattr_Transition"))
					{
						pTiles[sNumTiles].uAttributes |= TILE_DESC_TRANSITION;
					}
					else
					{
						logger->warning("Unknown tile attribute {}", v72);
					}
				}
				++sNumTiles;
			}
		}
	}

	fclose(File);
	return 1;
}
