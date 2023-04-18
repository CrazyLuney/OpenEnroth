#pragma once

#include "Engine/Objects/Player.h"
#include "Engine/Serialization/LegacyImages.h"

#include "Utility/Memory/Blob.h"

using PlayerFrame = data::mm7::PlayerFrame;

/*   47 */
struct PlayerFrameTable
{
	unsigned int GetFrameIdByExpression(CHARACTER_EXPRESSION_ID expression);
	PlayerFrame* GetFrameBy_x(unsigned int uFramesetID, unsigned int uFrameID);
	PlayerFrame* GetFrameBy_y(int* a2, int* a3, int a4);
	void ToFile();
	void FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8);

	size_t uNumFrames = 0;
	std::unique_ptr<PlayerFrame[]> pFrames;
};

extern struct PlayerFrameTable* pPlayerFrameTable;  // idb
