#include "Engine/Objects/ObjectList.h"
#include "Engine/Graphics/Sprites.h"
#include "Engine/Serialization/Deserializer.h"
#include "Engine/Serialization/Serializer.h"
#include "Engine/Serialization/LegacyImages.h"


struct ObjectList* pObjectList;

unsigned int ObjectList::ObjectIDByItemID(unsigned int uItemID)
{
	auto it = std::find_if(std::begin(pObjects), std::end(pObjects), [&](const ObjectDesc& object_desc) -> bool
		{
			return object_desc.uObjectID == uItemID;
		});
	if (it == std::end(pObjects))
		return 0;
	return std::distance(std::begin(pObjects), it);
}

void ObjectList::InitializeSprites()
{
	for (const auto& object_desc : pObjects)
	{
		pSpriteFrameTable->InitializeSprite(object_desc.uSpriteID);
	}
}

void ObjectList::InitializeColors()
{
	for (auto& object_desc : pObjects)
	{
		object_desc.uParticleTrailColor =
			(static_cast<uint32_t>(object_desc.uParticleTrailColorR)) |
			(static_cast<uint32_t>(object_desc.uParticleTrailColorG) << 8) |
			(static_cast<uint32_t>(object_desc.uParticleTrailColorB) << 16);
	}
}

void ObjectList::FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8)
{
	Assert(!data_mm6);
	Assert(!data_mm8);

	pObjects.clear();

	if (data_mm6)
	{
		BlobDeserializer stream(data_mm6);
		stream.ReadLegacyVector<data::mm6::ObjectDesc>(&pObjects, Deserializer::Append);
	}

	if (data_mm7)
	{
		BlobDeserializer stream(data_mm7);
		stream.ReadLegacyVector<data::mm7::ObjectDesc>(&pObjects, Deserializer::Append);
	}

	if (data_mm8)
	{
		BlobDeserializer stream(data_mm8);
		stream.ReadLegacyVector<data::mm8::ObjectDesc>(&pObjects, Deserializer::Append);
	}

	Assert(!pObjects.empty());
}
