#include "Engine/Objects/ObjectList.h"
#include "Engine/Graphics/Sprites.h"
#include "Engine/Serialization/LegacyImages.h"

struct ObjectList* pObjectList;

unsigned int ObjectList::ObjectIDByItemID(unsigned int uItemID)
{
	for (size_t i = 0; i < uNumObjects; ++i)
	{
		const auto& object = pObjects[i];

		if (object.uObjectID == uItemID)
			return i;
	}

	return 0;
}

void ObjectList::InitializeSprites()
{
	for (size_t i = 0; i < uNumObjects; ++i)
	{
		const auto& object = pObjects[i];

		pSpriteFrameTable->InitializeSprite(object.uSpriteID);
	}
}

void ObjectList::InitializeColors()
{
	for (size_t i = 0; i < uNumObjects; ++i)
	{
		auto& object = pObjects[i];

		object.uParticleTrailColor =
			(static_cast<uint32_t>(object.uParticleTrailColorR)) |
			(static_cast<uint32_t>(object.uParticleTrailColorG) << 8) |
			(static_cast<uint32_t>(object.uParticleTrailColorB) << 16);
	}
}

void ObjectList::FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8)
{
#pragma pack(push, 1)
	struct ObjectListHeader final
	{
		uint32_t num_objects;
	};
#pragma pack(pop)

	size_t mm6_num_objects = 0;
	if (data_mm6)
	{
		const auto& header = *data_mm6.data_view<ObjectListHeader>();

		mm6_num_objects = header.num_objects;
	}

	size_t mm7_num_objects = 0;
	if (data_mm7)
	{
		const auto& header = *data_mm7.data_view<ObjectListHeader>();

		mm7_num_objects = header.num_objects;
	}

	size_t mm8_num_objects = 0;
	if (data_mm8)
	{
		const auto& header = *data_mm8.data_view<ObjectListHeader>();

		mm8_num_objects = header.num_objects;
	}

	uNumObjects = mm6_num_objects + mm7_num_objects + mm8_num_objects;

	pObjects = std::make_unique<ObjectDesc[]>(uNumObjects);

	auto objects = pObjects.get();

	if (data_mm6)
	{
		auto mm6_objects_data = data_mm6.data_view<data::mm6::ObjectDesc>(sizeof(ObjectListHeader));
		for (size_t i = 0; i < mm6_num_objects; ++i)
		{
			Deserialize(mm6_objects_data[i], &objects[i]);
		}

		objects += mm6_num_objects;
	}

	if (data_mm7)
	{
		auto mm7_objects_data = data_mm7.data_view<data::mm7::ObjectDesc>(sizeof(ObjectListHeader));
		for (size_t i = 0; i < mm7_num_objects; ++i)
		{
			Deserialize(mm7_objects_data[i], &objects[i]);
		}

		objects += mm7_num_objects;
	}

	if (data_mm8)
	{
		auto mm8_objects_data = data_mm8.data_view<data::mm8::ObjectDesc>(sizeof(ObjectListHeader));
		for (size_t i = 0; i < mm8_num_objects; ++i)
		{
			Deserialize(mm8_objects_data[i], &objects[i]);
		}

		objects += mm8_num_objects;
	}
}
