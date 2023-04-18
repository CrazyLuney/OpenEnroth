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

	sNumTiles = mm7_num_tiles;

	pTiles = std::make_unique<TileDesc[]>(sNumTiles);

	if (data_mm7)
	{
		auto mm7_tiles_data = data_mm7.data_view<data::mm7::TileDesc>(sizeof(TileTableHeader));
		for (size_t i = 0; i < mm7_num_tiles; ++i)
		{
			Deserialize(mm7_tiles_data[i], &pTiles[i]);
		}
	}
}
