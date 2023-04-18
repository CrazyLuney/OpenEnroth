#pragma once

#include "Utility/Strings.h"
#include "Utility/Flags.h"
#include "Utility/Memory/Blob.h"

/*  321 */
enum class DecorationDescFlag : uint16_t
{
	MoveThrough = 0x0001,
	DontDraw = 0x0002,
	FlickerSlow = 0x0004,
	FlickerAverage = 0x0008,
	FlickerFast = 0x0010,
	Marker = 0x0020,
	SlowLoop = 0x0040,
	EmitsFire = 0x0080,
	SoundOnDawn = 0x0100,
	SoundOnDusk = 0x0200,
	EmitsSmoke = 0x0400,
};

MM_DECLARE_FLAGS(DecorationDescFlags, DecorationDescFlag)
MM_DECLARE_OPERATORS_FOR_FLAGS(DecorationDescFlags)

struct DecorationDesc
{
	inline bool CanMoveThrough() const
	{
		return uFlags & DecorationDescFlag::MoveThrough;
	}
	inline bool DontDraw() const
	{
		return uFlags & DecorationDescFlag::DontDraw;
	}
	inline bool SoundOnDawn() const
	{
		return uFlags & DecorationDescFlag::SoundOnDawn;
	}
	inline bool SoundOnDusk() const
	{
		return uFlags & DecorationDescFlag::SoundOnDusk;
	}

	std::string pName;
	std::string field_20;
	int16_t uType;
	uint16_t uDecorationHeight;
	int16_t uRadius;
	int16_t uLightRadius;
	uint16_t uSpriteID;
	DecorationDescFlags uFlags;
	int16_t uSoundID;
	uint8_t uColoredLightRed;
	uint8_t uColoredLightGreen;
	uint8_t uColoredLightBlue;
};

class DecorationList
{
public:
	inline DecorationList() {}

	void ToFile();
	void FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8);
	void InitializeDecorationSprite(unsigned int uDecID);
	uint16_t GetDecorIdByName(std::string_view pName);

	const DecorationDesc* GetDecoration(size_t index) const
	{
		assert(index < uNumDecorations);
		return &pDecorations[index];
	}

protected:
	size_t uNumDecorations = 0;
	std::unique_ptr<DecorationDesc[]> pDecorations;
};

extern class DecorationList* pDecorationList;

void RespawnGlobalDecorations();
