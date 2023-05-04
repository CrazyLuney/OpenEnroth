#pragma once

#include "Utility/Flags.h"
#include "Utility/Geometry/Plane.h"
#include "Utility/Geometry/BBox.h"

class Deserializer;

enum class FaceAttribute : uint32_t
{
	Portal = 0x00000001,
	Secret = 0x00000002,
	FlowDown = 0x00000004,
	TexAlignDown = 0x00000008,
	Fluid = 0x00000010,
	FlowUp = 0x00000020,
	FlowLeft = 0x00000040,
	SeenByParty = 0x00000080,
	XYPlane = 0x00000100,
	XZPlane = 0x00000200,
	YZPlane = 0x00000400,
	FlowRight = 0x00000800,
	TexAlignLeft = 0x00001000,
	Invisible = 0x00002000,
	TextureFrameTable = 0x00004000,  // Texture ID is a frameset from TextureFrameTable, otherwise BitmapID
	TexAlignRight = 0x00008000,
	Outlined = 0x00010000,  // outline face debug
	TexAlignBottom = 0x00020000,
	TexMoveByDoor = 0x00040000,
	Unknown10 = 0x00080000,  // MMExt: TriggerByTouch, doesn't work anymore
	Event = 0x00100000,  // MMExt: IsEventJustHint, [MM7+]
	IndoorCarpet = 0x00200000,  // MMExt: AlternativeSound
	IndoorSky = 0x00400000,  // MMExt: outdoor in software mode: horizontal flow
	FlipNormalU = 0x00800000,
	FlipNormalV = 0x01000000,
	Clickable = 0x02000000,  // Event can be triggered by clicking on the facet.
	PressurePlate = 0x04000000,  // Event can be triggered by stepping on the facet.
	Indicate = 0x06000000,  // face has status bar string on hover
	TriggerByMonster = 0x08000000,
	TriggerByObject = 0x10000000,
	Ethereal = 0x20000000,  // Untouchable. You can pass through it.
	// MMExt: great for vertical facets of stairs.
	// [MM7+] Shouldn't be used for sloped floor, like it's used in MM6.
	Lava = 0x40000000,
	Picked = 0x80000000,  // mouse is hovering
	// TODO: MMExt: HasData, are we talking about BLVFaceExtra?
};

MM_DECLARE_FLAGS(FaceAttributes, FaceAttribute)
MM_DECLARE_OPERATORS_FOR_FLAGS(FaceAttributes)

// door attr
enum class DoorAttribute : uint32_t
{
	DOOR_TRIGGERED = 0x00000001,
	DOOR_SETTING_UP = 0x00000002,
	DOOR_NOSOUND = 0x00000004,
};
using enum DoorAttribute;
MM_DECLARE_FLAGS(DoorAttributes, DoorAttribute)
MM_DECLARE_OPERATORS_FOR_FLAGS(DoorAttributes)

/*  291 */
enum class PolygonType : uint8_t
{
	None = 0,
	VerticalWall = 1,
	Unknown2 = 2,
	Floor = 3,
	InBetweenFloorAndWall = 4,
	Ceiling = 5,
	InBetweenCeilingAndWall = 6,
};

#pragma pack(push, 1)
struct BSPNode
{
	int16_t uFront;
	int16_t uBack;
	int16_t uBSPFaceIDOffset;
	int16_t uNumBSPFaces;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct BSPModelData
{
	std::array<char, 32> pModelName;
	std::array<char, 32> pModelName2;
	int32_t field_40 = 0;
	uint32_t uNumVertices = 0;
	uint32_t ppVertices = 0;
	uint32_t uNumFaces = 0;
	uint32_t uNumConvexFaces = 0;
	uint32_t ppFaces = 0;
	uint32_t ppFacesOrdering = 0;
	uint32_t uNumNodes = 0;
	uint32_t ppNodes = 0;
	uint32_t uNumDecorations = 0;
	Vec2i vCenter;
	Vec3i vPosition;
	Vec3i vMin;
	Vec3i vMax;
	Vec3i vOtherMin;
	Vec3i vOtherMax;
	Vec3i vBoundingCenter{};
	int32_t sBoundingRadius = 0;
};
#pragma pack(pop)

class Texture;

struct ODMFace
{
	bool HasEventHint();

	bool IsInvisible() const { return uAttributes & FaceAttribute::Invisible; }
	bool IsVisible() const { return !IsInvisible(); }
	bool IsPortal() const { return uAttributes & FaceAttribute::Portal; }
	bool IsFluid() const { return uAttributes & FaceAttribute::Fluid; }
	bool IsIndoorSky() const { return uAttributes & FaceAttribute::IndoorSky; }
	bool IsClickable() const { return uAttributes & FaceAttribute::Clickable; }
	bool IsPressurePlate() const { return uAttributes & FaceAttribute::PressurePlate; }
	bool IsEthereal() const { return uAttributes & FaceAttribute::Ethereal; }
	bool IsTextureFrameTable() { return uAttributes & FaceAttribute::TextureFrameTable; }

	void ToggleTextureFrameTable()
	{
		if (uAttributes & FaceAttribute::TextureFrameTable)
			uAttributes &= ~FaceAttribute::TextureFrameTable;
		else
			uAttributes |= FaceAttribute::TextureFrameTable;
	}

	void SetTexture(const std::string& filename);
	Texture* GetTexture();

	// TODO: does this really have to be two separate functions?
	/**
	 * @see BLVFace::Contains
	 */
	bool Contains(const Vec3i& pos, int model_idx, int slack = 0, FaceAttributes override_plane = 0) const;

	unsigned int index = 0;
	Planef pFacePlane;
	Planei pFacePlaneOLD;
	PlaneZCalcll zCalc;
	FaceAttributes uAttributes = 0;
	std::array<uint16_t, 20> pVertexIDs = { {} };
	std::array<int16_t, 20> pTextureUIDs = { {} };
	std::array<int16_t, 20> pTextureVIDs = { {} };
	std::array<int16_t, 20> pXInterceptDisplacements = { {} };
	std::array<int16_t, 20> pYInterceptDisplacements = { {} };
	std::array<int16_t, 20> pZInterceptDisplacements = { {} };

	// details store for array texture
	void* resource = nullptr;  // int16_t uTextureID;;
	int texunit = -1;
	int texlayer = -1;

	int16_t sTextureDeltaU = 0;
	int16_t sTextureDeltaV = 0;
	// TODO(pskelton): Geometry should be float
	BBoxs pBoundingBox;
	int16_t sCogNumber = 0;
	int16_t sCogTriggeredID = 0;
	int16_t sCogTriggerType = 0;
	char field_128 = 0;
	char field_129 = 0;
	uint8_t uGradientVertex1 = 0;
	uint8_t uGradientVertex2 = 0;
	uint8_t uGradientVertex3 = 0;
	uint8_t uGradientVertex4 = 0;
	uint8_t uNumVertices = 0;
	PolygonType uPolygonType = PolygonType::None;
	uint8_t uShadeType = 0;  // could be minimum shade
	uint8_t bVisible = 0;
	char field_132 = 0;
	char field_133 = 0;
};

class BSPModel
{
public:
	unsigned int index = 0;
	std::string pModelName;
	std::string pModelName2;
	int32_t field_40 = 0; // visibility flag TODO(pskelton): use for map tooltip checking or remove
	Vec2i vCenter {};
	Vec3i vPosition {};
	BBoxi pBoundingBox;
	Vec3i vOtherMin {};
	Vec3i vOtherMax {};
	Vec3i vBoundingCenter{};
	int32_t sBoundingRadius = 0;

	std::vector<Vec3i> pVertices;
	std::vector<ODMFace> pFaces;
	std::vector<uint16_t> pFacesOrdering;
	std::vector<BSPNode> pNodes;
};

class BSPModelList : public std::vector<BSPModel>
{
public:
	void Load(Deserializer* stream);
};
