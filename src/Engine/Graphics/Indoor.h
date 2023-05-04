#pragma once

#include "Engine/mm7_data.h"
#include "Engine/EngineIocContainer.h"
#include "Engine/SpawnPoint.h"

#include "Engine/Graphics/BSPModel.h"
#include "Engine/Graphics/IRender.h"

struct IndoorLocation;

/*  358 */
#pragma pack(push, 1)
struct LightsData
{
	int32_t field_0;
	Planei plane_4;
	Vec3i vec_14;
	Vec3i vec_20;
	uint32_t uCurrentAmbientLightLevel;  // 0 to 31
	int32_t field_30;
	int32_t field_34;
	int32_t field_38;
	int32_t pDeltaUV[2];
	int32_t field_44;
	int32_t field_48;
	char field_4C[8];
	Vec3i rotated_normal;
	Vec3i vec_60;
	int32_t field_6C;
	Vec3i vec_70;
	int32_t field_7C;
	Vec3i vec_80;
	Vec3i vec_8C;
	int32_t field_98;
	Vec3i vec_9C;
	int32_t field_A8;
	uint32_t uNumLightsApplied;
	int32_t _blv_lights_radii[20];
	int32_t _blv_lights_inv_radii[20];
	int32_t _blv_lights_xs[20];
	int32_t _blv_lights_ys[20];
	int32_t _blv_lights_light_dot_faces[20];
	int32_t field_240;
	int32_t field_244;
	int32_t field_248;
	int32_t field_24C;
	int32_t field_250;
	int32_t field_254;
	int32_t field_258;
	int32_t field_25C;
	int32_t field_260;
	int32_t field_264;
	int32_t field_268;
	int32_t field_26C;
	int32_t field_270;
	int32_t field_274;
	int32_t field_278;
	int32_t field_27C;
	int32_t field_280;
	int32_t field_284;
	int32_t field_288;
	int32_t field_28C;
	int32_t _blv_lights_zs[20];
	float _blv_lights_rs[20];
	float _blv_lights_gs[20];
	float _blv_lights_bs[20];
	char _blv_lights_types[20];
	int32_t field_3E4;
	int32_t field_3E8;
	int32_t field_3EC;
	int32_t field_3F0;
	int32_t field_3F4;
	uint32_t uDefaultAmbientLightLevel;
};
#pragma pack(pop)

extern LightsData Lights;  // idb

#pragma pack(push, 1)
struct DDM_DLV_Header
{
	int32_t uNumRespawns = 0;
	int32_t uLastRespawnDay = 0;
	int32_t uReputation = 0;
	int32_t field_C_alert = 0; // Actually bool
	uint32_t uNumFacesInBModels = 0;
	uint32_t uNumDecorations = 0;
	uint32_t uNumBModels = 0;
	int32_t field_1C = 0;
	int32_t field_20 = 0;
	int32_t field_24 = 0;
};
#pragma pack(pop)

/*  345 */
#pragma pack(push, 1)
struct stru315
{
	int32_t field_0;
	int32_t field_4;
	int32_t field_8;
	int32_t field_C;
	int32_t field_10;
	int32_t field_14;
	int32_t field_18;
	int32_t field_1C;
	int32_t field_20;
	int32_t field_24;
	int32_t field_28;
	int32_t field_2C;
	int32_t field_30;
	uint16_t* field_34_palette;
	uint16_t* pTextureLOD;
	uint16_t* pDepthBuffer;
	uint16_t* pColorBuffer;
};
#pragma pack(pop)

/*  346 */
#pragma pack(push, 1)
struct stru316
{
	int32_t field_0;
	int32_t field_4;
	int32_t field_8;
	int32_t field_C;
	int32_t field_10;
	int32_t field_14;
	int32_t field_18;
	int32_t field_1C;
	int32_t field_20;
	uint16_t* field_24_palette;
};
#pragma pack(pop)

/*  378 */
#pragma pack(push, 1)
struct stru337_stru0
{
	int32_t field_0;
	int32_t field_4;
	int32_t field_8;
	int32_t field_C;
	int32_t field_10;
};
#pragma pack(pop)

/*  147 */
#pragma pack(push, 1)

struct stru154
{
	//----- (0049B001) --------------------------------------------------------
	inline stru154() {}

	//----- (0049B027) --------------------------------------------------------
	inline ~stru154() {}

	void GetFacePlaneAndClassify(ODMFace* a2, const std::vector<Vec3i>& a3);
	void ClassifyPolygon(Vec3f* pNormal, float dist);
	void GetFacePlane(ODMFace* pFace, const std::vector<Vec3i>& pVertices, Vec3f* pOutNormal, float* pOutDist);

	Planef face_plane{};
	PolygonType polygonType{};
	char field_15 = 0;
	char field_16 = 0;
	char field_17 = 0;
};
#pragma pack(pop)

/*  392 */
#pragma pack(push, 1)
struct stru352
{
	int32_t field_0;
	int32_t field_4;
	int32_t field_8;
	int32_t field_C;
	int32_t field_10;
	int32_t field_14;
	int32_t field_18;
	int32_t field_1C;
	int32_t field_20;
	int32_t field_24;
	int32_t field_28;
	int32_t field_2C;
	int32_t field_30;
	int32_t field_34;
};
#pragma pack(pop)
// extern std::array<stru352, 480> stru_F83B80;

#pragma pack(push, 1)
struct WorldTime
{
	GameTime last_visit{};
	char sky_texture_name[12]{};
	int32_t day_attrib = 0;
	int32_t day_fogrange_1 = 0;
	int32_t day_fogrange_2 = 0;
	char field_2F4[24]{};
};
#pragma pack(pop)

/*  319 */
enum class WorldType
{
	None = 0,
	Indoor = 1,
	Outdoor = 2,
};

extern WorldType uCurrentlyLoadedLevelType;

/*   90 */
#pragma pack(push, 1)
struct BLVHeader
{
	char field_0[104];
	uint32_t uFaces_fdata_Size;
	uint32_t uSector_rdata_Size;
	uint32_t uSector_lrdata_Size;
	uint32_t uDoors_ddata_Size;
	char field_78[16];
};
#pragma pack(pop)

/*   96 */
#pragma pack(push, 1)
struct BLVSectorMM8
{
	uint32_t dword_000074;
};
#pragma pack(pop)

/*   97 */
#pragma pack(push, 1)
struct BLVLightMM6
{
	Vec3s vPosition;
	int16_t uRadius;
	int16_t uAttributes;
	uint16_t uBrightness;
};
#pragma pack(pop)

/*   98 */
#pragma pack(push, 1)
struct BLVLightMM7
{  // 10h
	Vec3s vPosition;
	int16_t uRadius;
	char uRed;
	char uGreen;
	char uBlue;
	char uType;
	int16_t uAtributes;  // & 0x08    doesn't light faces
	int16_t uBrightness;
};
#pragma pack(pop)

/*   99 */
#pragma pack(push, 1)
struct BLVLightMM8
{
	int uID;
};
#pragma pack(pop)

/*  100 */
#pragma pack(push, 1)
struct BLVDoor
{  // 50h
	enum class State : uint16_t
	{
		Closed = 0,
		Opening = 1,
		Open = 2,
		Closing = 3
	};
	using enum State;

	DoorAttributes uAttributes;
	uint32_t uDoorID;
	uint32_t uTimeSinceTriggered;
	Vec3i vDirection;
	int32_t uMoveLength;
	int32_t uOpenSpeed;
	int32_t uCloseSpeed;
	uint16_t* pVertexIDs;
	uint16_t* pFaceIDs;
	uint16_t* pSectorIDs;
	int16_t* pDeltaUs;
	int16_t* pDeltaVs;
	int16_t* pXOffsets;
	int16_t* pYOffsets;
	int16_t* pZOffsets;
	uint16_t uNumVertices;
	uint16_t uNumFaces;
	uint16_t uNumSectors;
	uint16_t uNumOffsets;
	State uState;
	int16_t field_4E;
};
#pragma pack(pop)

/*  101 */
#pragma pack(push, 1)
struct BLVMapOutline
{  // 0C
	uint16_t uVertex1ID;
	uint16_t uVertex2ID;
	uint16_t uFace1ID;
	uint16_t uFace2ID;
	int16_t sZ;
	uint16_t uFlags;
};
#pragma pack(pop)

struct FlatFace
{
	std::array<int32_t, 104> u;
	std::array<int32_t, 104> v;
};

enum
{
	MODEL_INDOOR = -1
};

/*   93 */
#pragma pack(push, 1)
//----- (0046ED02) --------------------------------------------------------
struct BLVFace
{
	// 60h
	BLVFace()
	{
		uNumVertices = 0;
		uAttributes = 0;
		uFaceExtraID = 0;
		pVertexIDs = nullptr;
		pZInterceptDisplacements = nullptr;
		pYInterceptDisplacements = nullptr;
		pXInterceptDisplacements = nullptr;
	}

	void _get_normals(Vec3i* a2, Vec3i* a3);
	void FromODM(struct ODMFace* face);

	void SetTexture(const std::string& filename);
	Texture* GetTexture();

	bool IsInvisible() const { return uAttributes & FaceAttribute::Invisible; }
	bool IsVisible() const { return !IsInvisible(); }
	bool IsPortal() const { return uAttributes & FaceAttribute::Portal; }
	bool IsFluid() const { return uAttributes & FaceAttribute::Fluid; }
	bool IsIndoorSky() const { return uAttributes & FaceAttribute::IndoorSky; }
	bool IsClickable() const { return uAttributes & FaceAttribute::Clickable; }
	bool IsPressurePlate() const { return uAttributes & FaceAttribute::PressurePlate; }
	bool IsEthereal() const { return uAttributes & FaceAttribute::Ethereal; }
	bool IsTextureFrameTable() const { return uAttributes & FaceAttribute::TextureFrameTable; }

	void ToggleTextureFrameTable()
	{
		if (uAttributes & FaceAttribute::TextureFrameTable)
			uAttributes &= ~FaceAttribute::TextureFrameTable;
		else
			uAttributes |= FaceAttribute::TextureFrameTable;
	}

	/**
	 * @param[out] points               Coordinate storage. The storage is populated by the coordinates of this
	 *                                  face's vertices projected onto this face's primary plane.
	 * @param model_idx                 Model that this face belongs to, or `MODEL_INDOOR` for faces in indoor
	 *                                  locations.
	 * @param override_plane            Plane override.
	 * @see BLVFace::Contains
	 */
	void Flatten(FlatFace* points, int model_idx, FaceAttributes override_plane = 0) const;

	/**
	 * @param pos                       Point to check.
	 * @param model_idx                 Model that this face belongs to, or `MODEL_INDOOR` for faces in indoor
	 *                                  locations.
	 * @param slack                     If a point is at most `slack` units away from the edge, it'll still be
	 *                                  considered to be lying on the edge.
	 * @param override_plane            Plane override. By default the check is performed in the face's primary plane
	 *                                  that is set in attributes, but this behavior can be overridden by e.g. passing
	 *                                  `FACE_XY_PLANE`.
	 * @return                          Whether the point lies inside this polygon, if projected on the face's
	 *                                  primary plane.
	 */
	bool Contains(const Vec3i& pos, int model_idx, int slack = 0, FaceAttributes override_plane = 0) const;

	struct Planef pFacePlane;
	struct Planei pFacePlane_old;
	PlaneZCalcll zCalc;
	FaceAttributes uAttributes;
	uint16_t* pVertexIDs = nullptr;
	int16_t* pXInterceptDisplacements;
	int16_t* pYInterceptDisplacements;
	int16_t* pZInterceptDisplacements;
	int16_t* pVertexUIDs = nullptr;
	int16_t* pVertexVIDs = nullptr;
	uint16_t uFaceExtraID;
	void* resource{ nullptr };  // uint16_t  uBitmapID;
	int texunit = -1;
	int texlayer = -1;

	uint16_t uSectorID{};
	int16_t uBackSectorID{};
	// TODO(pskelton): Geometry should be float
	BBoxs pBounding;
	PolygonType uPolygonType = PolygonType::None;
	uint8_t uNumVertices;
	char field_5E = 0;
	char field_5F = 0;
};
#pragma pack(pop)

/*   94 */
#pragma pack(push, 1)
struct BLVFaceExtra
{  // 24h
	bool HasEventHint();

	int16_t field_0;
	int16_t field_2;
	int16_t field_4;
	int16_t field_6;
	int16_t field_8;
	int16_t field_A;
	int16_t face_id;
	uint16_t uAdditionalBitmapID;
	int16_t field_10;
	int16_t field_12;
	int16_t sTextureDeltaU;
	int16_t sTextureDeltaV;
	int16_t sCogNumber;
	uint16_t uEventID;
	int16_t field_1C;
	int16_t field_1E;
	int16_t field_20;
	int16_t field_22;
};
#pragma pack(pop)

/*   95 */
#pragma pack(push, 1)
struct BLVSector
{  // 0x74
	int32_t field_0;  // flags?? &8 is for check floor level against portals &10 is for adding additonal node faces
	uint16_t uNumFloors;
	int16_t field_6;
	uint16_t* pFloors;
	uint16_t uNumWalls;
	int16_t field_E;
	uint16_t* pWalls;
	uint16_t uNumCeilings;
	int16_t field_16;
	uint16_t* pCeilings;
	uint16_t uNumFluids;
	int16_t field_1E;
	uint16_t* pFluids;
	int16_t uNumPortals;
	int16_t field_26;
	uint16_t* pPortals;
	uint16_t uNumFaces;
	uint16_t uNumNonBSPFaces;
	uint16_t* pFaceIDs;
	uint16_t uNumCylinderFaces;
	int16_t field_36;
	int32_t pCylinderFaces;
	uint16_t uNumCogs;
	int16_t field_3E;
	uint16_t* pCogs;
	uint16_t uNumDecorations;
	int16_t field_46;
	uint16_t* pDecorationIDs;
	uint16_t uNumMarkers;
	int16_t field_4E;
	uint16_t* pMarkers;
	uint16_t uNumLights;
	int16_t field_56;
	uint16_t* pLights;
	int16_t uWaterLevel;
	int16_t uMistLevel;
	int16_t uLightDistanceMultiplier;
	int16_t uMinAmbientLightLevel;  // might be supposed to be max ambient dim actually
	int16_t uFirstBSPNode;
	int16_t exit_tag;
	BBoxs pBounding;
};
#pragma pack(pop)

/*   89 */
#pragma pack(push, 1)
struct IndoorLocation
{
	//----- (00462592) --------------------------------------------------------
	inline IndoorLocation()
	{
		log = EngineIocContainer::ResolveLogger();
		decal_builder = EngineIocContainer::ResolveDecalBuilder();
		spell_fx_renderer = EngineIocContainer::ResolveSpellFxRenderer();
		particle_engine = EngineIocContainer::ResolveParticleEngine();
	}

	/**
	 * @param sX                        X coordinate.
	 * @param sY                        Y coordinate.
	 * @param sZ                        Z coordinate.
	 * @return                          Sector id at (X,Y,Z), or zero if (X,Y,Z) is outside the level bounds.
	 */
	int GetSector(int sX, int sY, int sZ);

	int GetSector(const Vec3i& pos)
	{
		return GetSector(pos.x, pos.y, pos.z);
	}

	int GetSector(const Vec3s& pos)
	{
		return GetSector(pos.x, pos.y, pos.z);
	}

	void Release();
	bool Load(const std::string& filename, int num_days_played,
		int respawn_interval_days, char* pDest);
	void Draw();
	void ToggleLight(signed int uLightID, unsigned int bToggle);

	static unsigned int GetLocationIndex(const char* Str1);
	void DrawIndoorFaces(bool bD3D);
	void PrepareActorRenderList_BLV();
	void PrepareDecorationsRenderList_BLV(unsigned int uDecorationID, unsigned int uSectorID);
	void PrepareItemsRenderList_BLV();

	std::string filename;
	char field_20[48];
	unsigned int bLoaded = 0;
	char field_54[404];
	BLVHeader blv;
	std::vector<Vec3s> pVertices;
	std::vector<BLVFace> pFaces;
	std::vector<BLVFaceExtra> pFaceExtras;
	std::vector<BLVSector> pSectors;
	std::vector<BLVLightMM7> pLights;
	std::vector<BLVDoor> pDoors;
	std::vector<BSPNode> pNodes;
	std::vector<BLVMapOutline> pMapOutlines;
	std::vector<uint16_t> pLFaces;
	std::vector<uint16_t> ptr_0002B0_sector_rdata;
	std::vector<uint16_t> ptr_0002B4_doors_ddata;
	std::vector<uint16_t> ptr_0002B8_sector_lrdata;
	std::vector<SpawnPoint> pSpawnPoints;
	DDM_DLV_Header dlv;
	WorldTime world_time;
	std::array<char, 875> _visible_outlines;
	char padding;

	Logger* log = nullptr;
	DecalBuilder* decal_builder = nullptr;
	SpellFxRenderer* spell_fx_renderer = nullptr;
	std::shared_ptr<ParticleEngine> particle_engine = nullptr;
};
#pragma pack(pop)

extern IndoorLocation* pIndoor;

/*  162 */
#pragma pack(push, 1)
struct BLVRenderParams
{
	inline BLVRenderParams()
	{
		uViewportX = 0;
		uViewportY = 0;
		uViewportZ = 0;
		uViewportW = 0;
	}

	void Reset();

	int field_0_timer_ = 0;
	int uPartySectorID = 0;
	int uPartyEyeSectorID = 0;

	unsigned int uTargetWidth = 0;
	unsigned int uTargetHeight = 0;
	unsigned int uViewportX;
	unsigned int uViewportY;
	unsigned int uViewportZ;
	unsigned int uViewportW;
	int* pTargetZBuffer = nullptr;
	int uViewportHeight = 0;
	int uViewportWidth = 0;
	int uViewportCenterX = 0;
	int uViewportCenterY = 0;
	unsigned int uNumFacesRenderedThisFrame = 0;
};
#pragma pack(pop)
extern BLVRenderParams* pBLVRenderParams;

char DoInteractionWithTopmostZObject(int pid);
// int sub_4AAEA6_transform(struct RenderVertexSoft *a1);
unsigned int FaceFlowTextureOffset(unsigned int uFaceID);  // idb
void BLV_UpdateUserInputAndOther();

/**
 * @param pos                           Actor's position.
 * @param uSectorID                     Actor's sector id.
 * @param[out] pFaceID                  Id of the closest floor/ceiling face for the provided position, or `-1`
 *                                      if wrong sector is supplied or actor is out of bounds.
 * @return                              Fixpoint Z coordinate of the floor/ceiling face for the given position.
 *                                      If wrong sector is supplied or actor is out of bounds, `-30000` is
 *                                      returned.
 */
int BLV_GetFloorLevel(const Vec3i& pos, unsigned int uSectorID, unsigned int* pFaceID);
void BLV_UpdateDoors();
void UpdateActors_BLV();
void BLV_ProcessPartyActions();
void Door_switch_animation(unsigned int uDoorID, int a2);  // idb: sub_449A49
int CalcDistPointToLine(int a1, int a2, int a3, int a4, int a5, int a6);
void PrepareDrawLists_BLV();
void PrepareToLoadBLV(bool bLoading);
bool GetAlertStatus();
int SpawnEncounterMonsters(struct MapInfo* a1, int a2);
int DropTreasureAt(ITEM_TREASURE_LEVEL trs_level, signed int trs_type, int x, int y, int z, uint16_t facing);

void FindBillboardsLightLevels_BLV();

/**
 * @todo looks like this also works for ceilings, reflect in docs?
 *
 * @param pos                           Actor's position.
 * @param[in,out] pSectorID             Actor's cached sector id. If the cached sector id is no longer valid (e.g. an
 *                                      actor has already moved to another sector), then the new sector id is returned
 *                                      in this output parameter. If the actor moves out of level bounds (this happens),
 *                                      then this parameter is set to 0.
 * @param[out] pFaceID                  Id of the floor face on which the actor is standing, or `-1` if actor is outside
 *                                      the level boundaries.
 * @return                              Z coordinate for the floor at (X, Y), or `-30000` if actor is outside the
 *                                      level boundaries.
 */
int GetIndoorFloorZ(const Vec3i& pos, unsigned int* pSectorID, unsigned int* pFaceID);

/**
 * @offset 0x0047272C.
 *
 * Same as `GetIndoorFloorZ`, but also tries jiggling the party around a bit if the collision point couldn't be
 * found.
 *
 * @see GetIndoorFloorZ
 */
int GetApproximateIndoorFloorZ(const Vec3i& pos, unsigned int* pSectorID, unsigned int* pFaceID);

/**
 * @param target                         Vec3i of position to check line of sight to
 * @param from                           Vec3i of position to check line of sight from
 *
 * @return                              True if line of sight clear to target
 */
bool Check_LineOfSight(const Vec3i& target, const Vec3i& from);


/**
 * @param target                         Vec3i of position to check line of sight to
 * @param from                           Vec3i of position to check line of sight from
 *
 * @return                              True if line of sight obscurred by level geometery
 */
bool Check_LOS_Obscurred_Indoors(const Vec3i& target, const Vec3i& from);

/**
 * @param target                         Vec3i of position to check line of sight to
 * @param from                           Vec3i of position to check line of sight from
 *
 * @return                              True if line of sight obscurred by outdoor models
 */
bool Check_LOS_Obscurred_Outdoors_Bmodels(const Vec3i& target, const Vec3i& from);

extern struct BspRenderer* pBspRenderer;
