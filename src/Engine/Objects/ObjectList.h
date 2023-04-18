#pragma once

#include "Utility/Flags.h"
#include "Utility/Memory/Blob.h"

enum class ObjectDescFlag : uint16_t
{
	NoSprite = 0x1,
	NoCollision = 0x2,
	Temporary = 0x4,
	LifetimeRelated = 0x8,
	NoPick = 0x10,
	NoGravity = 0x20,
	Interactable = 0x40,
	Bounce = 0x80,
	TrailParticle = 0x100,
	TrailFire = 0x200,
	TrailLine = 0x400,
};

MM_DECLARE_FLAGS(ObjectDescFlags, ObjectDescFlag)
MM_DECLARE_OPERATORS_FOR_FLAGS(ObjectDescFlags)

struct ObjectDesc
{
	inline bool NoSprite() const { return uFlags & ObjectDescFlag::NoSprite; }

	std::string field_0;
	int16_t uObjectID;
	int16_t uRadius;
	int16_t uHeight;
	ObjectDescFlags uFlags;
	uint16_t uSpriteID;
	int16_t uLifetime;
	uint32_t uParticleTrailColor;
	int16_t uSpeed;
	uint8_t uParticleTrailColorR;
	uint8_t uParticleTrailColorG;
	uint8_t uParticleTrailColorB;
	int8_t field_35_clr;
	int8_t field_36_clr;
	int8_t field_37_clr;
};

class ObjectList
{
public:
	void FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8);
	void InitializeSprites();
	void InitializeColors();
	unsigned int ObjectIDByItemID(unsigned int uItemID);

public:
	size_t uNumObjects = 0;
	std::unique_ptr<ObjectDesc[]> pObjects;
};

extern ObjectList* pObjectList;
