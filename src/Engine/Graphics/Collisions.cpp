#include "Collisions.h"

#include "Engine/Graphics/DecorationList.h"
#include "Engine/Graphics/Level/Decoration.h"
#include "Engine/Graphics/Outdoor.h"
#include "Engine/MM7.h"
#include "Engine/Objects/Actor.h"
#include "Engine/Objects/ObjectList.h"
#include "Engine/Objects/SpriteObject.h"
#include "Engine/TurnEngine/TurnEngine.h"

#include "Utility/Math/Float.h"
#include "Utility/Math/TrigLut.h"

CollisionState collision_state;

//
// Helper functions.
//

/**
 * @offset 0x0047531C, 0x004754BF.
 *
 * @param face                          Polygon to check collision against.
 * @param pos                           Actor position to check.
 * @param radius                        Actor radius.
 * @param dir                           Movement direction as a unit vector in fixpoint format.
 * @param[out] out_move_distance        Move distance along the `dir` axis required to touch the provided polygon.
 *                                      Always non-negative. This parameter is not set if the function returns false.
 *                                      Note that "touching" in this context means that the distance from the actor's
 *                                      center to the polygon equals actor's radius.
 * @param ignore_ethereal               Whether ethereal faces should be ignored by this function.
 * @param model_idx                     Model index, or `MODEL_INDOOR`.
 * @return                              Whether the actor, basically modeled as a sphere, can actually collide with the
 *                                      polygon if moving along the `dir` axis.
 */
static bool CollideSphereWithFace(BLVFace* face, const Vec3f& pos, float radius, const Vec3f& dir,
	float* out_move_distance, bool ignore_ethereal, int model_idx)
{
	if (ignore_ethereal && face->IsEthereal())
		return false;

	// dot_product(dir, normal) is a cosine of an angle between them.
	float cos_dir_normal = dot(dir, face->pFacePlane.vNormal);

	float pos_face_distance = face->pFacePlane.signedDistanceTo(pos);

	// How deep into the model that the face belongs to we already are,
	// positive value => actor's sphere already intersects the model.
	float overshoot = -pos_face_distance + radius;
	float move_distance = 0;
	if (abs(overshoot) < radius)
	{
		// We got here => we're not that deep into the model. Can just push us back a little.
		move_distance = 0;
	}
	else
	{
		// We got here => we're already inside the model. Or way outside.
		// We just say we overshot by radius. No idea why.
		overshoot = radius;

		// Then this is a correction needed to bring us to the point where actor's sphere is just touching the face.
		move_distance = overshoot / cos_dir_normal;
	}

	Vec3f new_pos =
		pos + move_distance * dir - overshoot * face->pFacePlane.vNormal;

	if (!face->Contains(new_pos, model_idx))
		return false; // We've just managed to slide past the face, so pretend no collision happened.

	if (move_distance < 0)
	{
		*out_move_distance = 0;
	}
	else
	{
		*out_move_distance = move_distance;
	}

	return true;
}

/**
 * @offset 0x00475D85, 0x00475F30.
 *
 * @param face                          Polygon to check collision against.
 * @param pos                           Actor position to check.
 * @param dir                           Movement direction as a unit vector in fixpoint format.
 * @param[in,out] out_move_distance     Current movement distance along the `dir` axis. This parameter is not touched
 *                                      when the function returns false. If the function returns true, then the
 *                                      distance required to hit the polygon is stored here. Note that this effectively
 *                                      means that this function can only decrease `move_distance`, but never increase
 *                                      it.
 * @param model_idx                     Model index, or `MODEL_INDOOR`.
 * @return                              Whether the actor, modeled as a point, hits the provided polygon if moving from
 *                                      `pos` along the `dir` axis by at most `move_distance`.
 */
static bool CollidePointWithFace(BLVFace* face, const Vec3f& pos, const Vec3f& dir, float* out_move_distance,
	int model_idx)
{
	// _fp suffix => that's a fixpoint number

	// dot_product(dir, normal) is a cosine of an angle between them.
	float cos_dir_normal = dot(dir, face->pFacePlane.vNormal);

	if (fuzzyIsNull(cos_dir_normal))
		return false; // dir is perpendicular to face normal.

	if (face->uAttributes & FaceAttribute::Ethereal)
		return false;

	if (cos_dir_normal > 0 && !face->IsPortal())
		return false; // We're facing away && face is not a portal.

	float pos_face_distance = face->pFacePlane.signedDistanceTo(pos);

	if (cos_dir_normal < 0 && pos_face_distance < 0)
		return false; // Facing towards the face but already inside the model.

	if (cos_dir_normal > 0 && pos_face_distance > 0)
		return false; // Facing away from the face and outside the model.

	// How far we need to move along the `dir` axis to hit face.
	float move_distance = -pos_face_distance / cos_dir_normal;

	Vec3f new_pos = pos + move_distance * dir;

	if (move_distance > *out_move_distance)
		return false; // No correction needed.

	if (!face->Contains(new_pos, model_idx))
		return false;

	*out_move_distance = move_distance;
	return true;
}

/**
 * Helper function that performs several collision checks between both the "feet" and the "head" spheres of the
 * collision state, and the provided face.
 *
 * @param face                          Face to check.
 * @param face_pid                      Pid of the provided face.
 * @param ignore_ethereal               Whether ethereal faces should be ignored by this function.
 * @param model_idx                     Model index, or `MODEL_INDOOR`.
*/
static void CollideBodyWithFace(BLVFace* face, int face_pid, bool ignore_ethereal, int model_idx)
{
	auto collide_once = [&](const Vec3f& old_pos, const Vec3f& new_pos, const Vec3f& dir, int radius)
	{
		float distance_old = face->pFacePlane.signedDistanceTo(old_pos);
		float distance_new = face->pFacePlane.signedDistanceTo(new_pos);
		if (distance_old > 0 && (distance_old <= radius || distance_new <= radius) && distance_new <= distance_old)
		{
			bool have_collision = false;
			float move_distance = collision_state.move_distance;
			if (CollideSphereWithFace(face, old_pos, radius, dir, &move_distance, ignore_ethereal, model_idx))
			{
				have_collision = true;
			}
			else
			{
				move_distance = collision_state.move_distance + radius;
				if (CollidePointWithFace(face, old_pos, dir, &move_distance, model_idx))
				{
					have_collision = true;
					move_distance -= radius;
				}
			}

			if (have_collision && move_distance < collision_state.adjusted_move_distance)
			{
				collision_state.adjusted_move_distance = move_distance;
				collision_state.pid = face_pid;
			}
		}
	};

	collide_once(
		collision_state.position_lo,
		collision_state.new_position_lo,
		collision_state.direction,
		collision_state.radius_lo);

	if (collision_state.check_hi)
		collide_once(
			collision_state.position_hi,
			collision_state.new_position_hi,
			collision_state.direction,
			collision_state.radius_hi);
}

/**
 * Performs a collision check with a cylinder.
 *
 * @param center_lo                     Center of the cylinder's base.
 * @param radius                        Cylinder radius.
 * @param height                        Cylinder height.
 * @param pid                           Pid of the object represented by the cylinder.
 * @param jagged_top                    See `CollideWithParty`.
 * @return                              Whether there is a collision.
 */
static bool CollideWithCylinder(const Vec3f& center_lo, float radius, float height, int pid, bool jagged_top)
{
	BBoxf bbox;
	bbox.x1 = center_lo.x - radius;
	bbox.x2 = center_lo.x + radius;
	bbox.y1 = center_lo.y - radius;
	bbox.y2 = center_lo.y + radius;
	bbox.z1 = center_lo.z;
	bbox.z2 = center_lo.z + height;
	if (!collision_state.bbox.intersects(bbox))
		return false;

	// dist vector points from position center into cylinder center.
	float dist_x = center_lo.x - collision_state.position_lo.x;
	float dist_y = center_lo.y - collision_state.position_lo.y;
	float sum_radius = collision_state.radius_lo + radius;

	// Area of the parallelogram formed by dist and collision_state.direction. Direction is a unit vector,
	// thus this actually is length(dist) * sin(dist, collision_state.direction).
	// This in turn is the distance from cylinder center to the line of actor's movement.
	Vec3f dir = collision_state.direction;
	float closest_dist = dist_x * dir.y - dist_y * dir.x;
	if (abs(closest_dist) > sum_radius)
		return false; // No chance to collide.

	// Length of dist vector projected onto collision_state.direction.
	float dist_dot_dir = dist_x * dir.x + dist_y * dir.y;
	if (dist_dot_dir <= 0)
		return false; // We're moving away from the cylinder.

	// Z-coordinate of the actor at the point closest to the cylinder in XY plane.
	float closest_z = collision_state.position_lo.z + dir.z * dist_dot_dir;
	if (closest_z < bbox.z1 || (closest_z > bbox.z2 && !jagged_top))
		return false;

	// That's how far can we go along the collision_state.direction axis until the actor touches the cylinder,
	// i.e. distance between them goes below sum_radius.
	float move_distance = dist_dot_dir - std::sqrt(sum_radius * sum_radius - closest_dist * closest_dist);
	if (move_distance < 0)
		move_distance = 0;

	if (move_distance < collision_state.adjusted_move_distance)
	{
		collision_state.adjusted_move_distance = move_distance;
		collision_state.pid = pid;
	}
	return true;
}

static void CollideWithDecoration(int id)
{
	LevelDecoration* decor = &pLevelDecorations[id];
	if (decor->uFlags & LEVEL_DECORATION_INVISIBLE)
		return;

	const DecorationDesc* desc = pDecorationList->GetDecoration(decor->uDecorationDescID);
	if (desc->CanMoveThrough())
		return;

	CollideWithCylinder(Vec3f(decor->vPosition), desc->uRadius, desc->uDecorationHeight, PID(OBJECT_Decoration, id), false);
}


//
// Public API.
//

bool CollisionState::PrepareAndCheckIfStationary(int dt_fp)
{
	if (!dt_fp)
		dt_fp = pEventTimer->dt_fixpoint;
	float dt = fixpoint_to_float(dt_fp);

	speed = glm::length(velocity);

	if (!fuzzyIsNull(speed))
	{
		direction = velocity / speed;
	}
	else
	{
		direction = Vec3f(0, 0, 1.0f);
	}

	move_distance = dt * speed - total_move_distance;
	if (move_distance <= 0)
		return true;

	new_position_hi = position_hi + move_distance * direction;
	new_position_lo = position_lo + move_distance * direction;

	bbox =
		BBoxf::fromPoint(position_lo, radius_lo) |
		BBoxf::fromPoint(new_position_lo, radius_lo) |
		BBoxf::fromPoint(position_hi, radius_hi) |
		BBoxf::fromPoint(new_position_hi, radius_hi);

	pid = 0;
	adjusted_move_distance = move_distance;

	return false;
}

void CollideIndoorWithGeometry(bool ignore_ethereal)
{
	std::array<int, 10> pSectorsArray;
	pSectorsArray[0] = collision_state.uSectorID;
	int totalSectors = 1;

	// See if we're intersection portals. If we do, we need to add corresponding sectors to the sectors array.
	BLVSector* pSector = &pIndoor->pSectors[collision_state.uSectorID];
	for (int j = 0; j < pSector->uNumPortals; ++j)
	{
		BLVFace* pFace = &pIndoor->pFaces[pSector->pPortals[j]];
		if (!collision_state.bbox.intersects(pFace->pBounding))
			continue;

		float distance = abs(pFace->pFacePlane.signedDistanceTo(collision_state.position_lo));
		if (distance > collision_state.move_distance + 16)
			continue;

		pSectorsArray[totalSectors++] =
			pFace->uSectorID == collision_state.uSectorID ? pFace->uBackSectorID : pFace->uSectorID;
		break;
	}

	for (int i = 0; i < totalSectors; i++)
	{
		pSector = &pIndoor->pSectors[pSectorsArray[i]];

		int totalFaces = pSector->uNumFloors + pSector->uNumWalls + pSector->uNumCeilings;
		for (int j = 0; j < totalFaces; j++)
		{
			BLVFace* face = &pIndoor->pFaces[pSector->pFloors[j]];
			if (face->IsPortal() || !collision_state.bbox.intersects(face->pBounding))
				continue;

			int face_id = pSector->pFloors[j];
			if (face_id == collision_state.ignored_face_id)
				continue;

			CollideBodyWithFace(face, PID(OBJECT_Face, face_id), ignore_ethereal, MODEL_INDOOR);
		}
	}
}

void CollideOutdoorWithModels(bool ignore_ethereal)
{
	for (BSPModel& model : pOutdoor->pBModels)
	{
		if (!collision_state.bbox.intersects(model.pBoundingBox))
			continue;

		for (ODMFace& mface : model.pFaces)
		{
			if (!collision_state.bbox.intersects(mface.pBoundingBox))
				continue;

			// TODO: we should really either merge two face classes, or template the functions down the chain call here.
			BLVFace face;
			face.pFacePlane_old = mface.pFacePlaneOLD;
			face.pFacePlane = mface.pFacePlane;
			face.uAttributes = mface.uAttributes;
			face.pBounding = mface.pBoundingBox;
			face.zCalc = mface.zCalc;
			face.uPolygonType = mface.uPolygonType;
			face.uNumVertices = mface.uNumVertices;
			face.resource = mface.resource;
			face.pVertexIDs = mface.pVertexIDs.data();

			if (face.IsEthereal() || face.IsPortal()) // TODO: this doesn't respect ignore_ethereal parameter
				continue;

			int pid = PID(OBJECT_Face, (mface.index | (model.index << 6)));
			CollideBodyWithFace(&face, pid, ignore_ethereal, model.index);
		}
	}
}

void CollideIndoorWithDecorations()
{
	BLVSector* sector = &pIndoor->pSectors[collision_state.uSectorID];
	for (unsigned int i = 0; i < sector->uNumDecorations; ++i)
		CollideWithDecoration(sector->pDecorationIDs[i]);
}

void CollideOutdoorWithDecorations(int grid_x, int grid_y)
{
	if (grid_x < 0 || grid_x > 127 || grid_y < 0 || grid_y > 127)
		return;

	int grid_index = grid_x + (grid_y << 7);
	int list_index = pOutdoor->pOMAP[grid_index];

	for (int i = list_index; i < pOutdoor->pFaceIDLIST.size(); i++)
	{
		uint16_t pid = pOutdoor->pFaceIDLIST[i];
		if (!pid)
			break;

		if (PID_TYPE(pid) != OBJECT_Decoration)
			continue;

		CollideWithDecoration(PID_ID(pid));
	}
}

bool CollideIndoorWithPortals()
{
	int portal_id = 0;            // [sp+10h] [bp-4h]@15
	float min_move_distance = std::numeric_limits<float>::max();
	for (unsigned int i = 0; i < pIndoor->pSectors[collision_state.uSectorID].uNumPortals; ++i)
	{
		BLVFace* face = &pIndoor->pFaces[pIndoor->pSectors[collision_state.uSectorID].pPortals[i]];
		if (!collision_state.bbox.intersects(face->pBounding))
			continue;

		float distance_lo_old = face->pFacePlane.signedDistanceTo(collision_state.position_lo);
		float distance_lo_new = face->pFacePlane.signedDistanceTo(collision_state.new_position_lo);
		float move_distance = collision_state.move_distance;
		if ((distance_lo_old < collision_state.radius_lo || distance_lo_new < collision_state.radius_lo) &&
			(distance_lo_old > -collision_state.radius_lo || distance_lo_new > -collision_state.radius_lo) &&
			CollidePointWithFace(face, collision_state.position_lo,
				collision_state.direction, &move_distance, MODEL_INDOOR) &&
			move_distance < min_move_distance)
		{
			min_move_distance = move_distance;
			portal_id = pIndoor->pSectors[collision_state.uSectorID].pPortals[i];
		}
	}

	if (collision_state.adjusted_move_distance >= min_move_distance && min_move_distance <= collision_state.move_distance)
	{
		if (pIndoor->pFaces[portal_id].uSectorID == collision_state.uSectorID)
		{
			collision_state.uSectorID = pIndoor->pFaces[portal_id].uBackSectorID;
		}
		else
		{
			collision_state.uSectorID = pIndoor->pFaces[portal_id].uSectorID;
		}
		collision_state.adjusted_move_distance = collision_state.move_distance;
		return false;
	}

	return true;
}

bool CollideWithActor(int actor_idx, int override_radius)
{
	Actor* actor = &pActors[actor_idx];
	if (actor->uAIState == Removed || actor->uAIState == Dying || actor->uAIState == Disabled ||
		actor->uAIState == Dead || actor->uAIState == Summoned)
		return false;

	float radius = actor->uActorRadius;
	if (override_radius != 0)
		radius = override_radius;

	return CollideWithCylinder(actor->vPosition, radius, actor->uActorHeight, PID(OBJECT_Actor, actor_idx), true);
}

void _46ED8A_collide_against_sprite_objects(unsigned int pid)
{
	for (uint i = 0; i < pSpriteObjects.size(); ++i)
	{
		if (pSpriteObjects[i].uObjectDescID == 0)
			continue;

		ObjectDesc* object = &pObjectList->pObjects[pSpriteObjects[i].uObjectDescID];
		if (object->uFlags & ObjectDescFlag::NoCollision)
			continue;

		// This code is very close to what we have in CollideWithCylinder, but factoring out common parts just
		// seemed not worth it.

		BBoxf bbox;
		bbox.x1 = pSpriteObjects[i].vPosition.x - object->uRadius;
		bbox.x2 = pSpriteObjects[i].vPosition.x + object->uRadius;
		bbox.y1 = pSpriteObjects[i].vPosition.y - object->uRadius;
		bbox.y2 = pSpriteObjects[i].vPosition.y + object->uRadius;
		bbox.z1 = pSpriteObjects[i].vPosition.z;
		bbox.z2 = pSpriteObjects[i].vPosition.z + object->uHeight;
		if (!collision_state.bbox.intersects(bbox))
			continue;

		float dist_x = pSpriteObjects[i].vPosition.x - collision_state.position_lo.x;
		float dist_y = pSpriteObjects[i].vPosition.y - collision_state.position_lo.y;
		float sum_radius = object->uHeight + collision_state.radius_lo;

		Vec3f dir = collision_state.direction;
		float closest_dist = dist_x * dir.y - dist_y * dir.x;
		if (abs(closest_dist) > sum_radius)
			continue;

		float dist_dot_dir = dist_x * dir.x + dist_y * dir.y;
		if (dist_dot_dir <= 0)
			continue;

		float closest_z = collision_state.position_lo.z + dir.z * dist_dot_dir;
		if (closest_z < bbox.z1 - collision_state.radius_lo || closest_z > bbox.z2 + collision_state.radius_lo)
			continue;

		if (dist_dot_dir < collision_state.adjusted_move_distance)
			collideWithActor(i, pid);
	}
}

void CollideWithParty(bool jagged_top)
{
	CollideWithCylinder(pParty->vPosition, 2 * pParty->radius, pParty->uPartyHeight, 4, jagged_top);
}

void ProcessActorCollisionsBLV(Actor& actor, bool isAboveGround, bool isFlying)
{
	collision_state.ignored_face_id = -1;
	collision_state.total_move_distance = 0;
	collision_state.check_hi = true;
	collision_state.radius_hi = actor.uActorRadius;
	collision_state.radius_lo = actor.uActorRadius;

	for (int attempt = 0; attempt < 100; attempt++)
	{
		collision_state.position_lo = Vec3f(actor.vPosition) + Vec3f(0, 0, actor.uActorRadius + 1);
		collision_state.position_hi = Vec3f(actor.vPosition) + Vec3f(0, 0, actor.uActorHeight - actor.uActorRadius - 1);
		collision_state.position_hi.z = std::max(collision_state.position_hi.z, collision_state.position_lo.z);
		collision_state.velocity = actor.vVelocity;
		collision_state.uSectorID = actor.uSectorID;
		if (collision_state.PrepareAndCheckIfStationary(0))
			break;

		int actorCollisions = 0;
		for (int i = 0; i < 100; ++i)
		{
			CollideIndoorWithGeometry(true);
			CollideIndoorWithDecorations();
			CollideWithParty(false);
			_46ED8A_collide_against_sprite_objects(PID(OBJECT_Actor, actor.id));
			for (int j = 0; j < ai_arrays_size; j++)
				if (ai_near_actors_ids[j] != actor.id && CollideWithActor(ai_near_actors_ids[j], 40))
					actorCollisions++;
			if (CollideIndoorWithPortals())
				break;
		}
		bool isInCrowd = actorCollisions > 1;

		Vec3f newPos = Vec3f(actor.vPosition) + collision_state.adjusted_move_distance * collision_state.direction;
		unsigned int newFaceID;
		int newFloorZ = GetIndoorFloorZ(newPos, &collision_state.uSectorID, &newFaceID);
		if (newFloorZ == -30000)
			break; // New pos is out of bounds, running more iterations won't help.

		if (pIndoor->pFaces[newFaceID].uAttributes & FaceAttribute::IndoorSky)
		{
			if (actor.uAIState == Dead)
			{
				actor.uAIState = Removed;
				break; // Actor removed, no point in running more iterations.
			}

			if (!isAboveGround && !isFlying)
			{
				if (actor.pMonsterInfo.uHostilityType == MONSTER_HOSTILITY_RADIUS_FRIENDLY || isInCrowd)
					Actor::AI_StandOrBored(actor.id, PID(OBJECT_Player, 0), 0, nullptr);

				break; // Trying to walk into indoor sky, bad idea!
			}
		}

		// Prevent actors from falling off ledges.
		if (actor.uCurrentActionAnimation == ANIM_Walking && newFloorZ < actor.vPosition.z - 100 && !isAboveGround && !isFlying)
		{
			if (actor.vPosition.x & 1)
			{
				actor.uYawAngle += 100;
			}
			else
			{
				actor.uYawAngle -= 100;
			}
			break; // We'll try again in the next frame.
		}

		actor.vPosition = newPos;
		actor.uSectorID = collision_state.uSectorID;
		if (fuzzyEquals(collision_state.adjusted_move_distance, collision_state.move_distance))
			break; // No collisions happened.

		collision_state.total_move_distance += collision_state.adjusted_move_distance;
		int id = PID_ID(collision_state.pid);
		ObjectType type = PID_TYPE(collision_state.pid);

		if (type == OBJECT_Actor)
		{
			if (pParty->bTurnBasedModeOn &&
				(pTurnEngine->turn_stage == TE_ATTACK || pTurnEngine->turn_stage == TE_MOVEMENT))
			{
				actor.vVelocity.x = fixpoint_mul(58500, actor.vVelocity.x);
				actor.vVelocity.y = fixpoint_mul(58500, actor.vVelocity.y);
				actor.vVelocity.z = fixpoint_mul(58500, actor.vVelocity.z);
				continue;
			}
			if (actor.pMonsterInfo.uHostilityType != MONSTER_HOSTILITY_RADIUS_FRIENDLY)
			{
				if (!isInCrowd)
				{
					Actor::AI_Flee(actor.id, collision_state.pid, 0, nullptr);
					actor.vVelocity.x = fixpoint_mul(58500, actor.vVelocity.x);
					actor.vVelocity.y = fixpoint_mul(58500, actor.vVelocity.y);
					actor.vVelocity.z = fixpoint_mul(58500, actor.vVelocity.z);
					continue;
				}
			}
			else
			{
				if (!isInCrowd)
				{
					if (pActors[id].pMonsterInfo.uHostilityType == MONSTER_HOSTILITY_RADIUS_FRIENDLY)
					{
						Actor::AI_FaceObject(actor.id, collision_state.pid, 0, nullptr);
						actor.vVelocity.x = fixpoint_mul(58500, actor.vVelocity.x);
						actor.vVelocity.y = fixpoint_mul(58500, actor.vVelocity.y);
						actor.vVelocity.z = fixpoint_mul(58500, actor.vVelocity.z);
						continue;
					}
					else
					{
						Actor::AI_Flee(actor.id, collision_state.pid, 0, nullptr);
						actor.vVelocity.x = fixpoint_mul(58500, actor.vVelocity.x);
						actor.vVelocity.y = fixpoint_mul(58500, actor.vVelocity.y);
						actor.vVelocity.z = fixpoint_mul(58500, actor.vVelocity.z);
						continue;
					}
				}
			}
			Actor::AI_StandOrBored(actor.id, PID(OBJECT_Player, 0), 0, nullptr);
			actor.vVelocity.x = fixpoint_mul(58500, actor.vVelocity.x);
			actor.vVelocity.y = fixpoint_mul(58500, actor.vVelocity.y);
			actor.vVelocity.z = fixpoint_mul(58500, actor.vVelocity.z);
			continue;
		}

		if (type == OBJECT_Player)
		{
			if (actor.GetActorsRelation(0))
			{
				// v51 =
				// __OFSUB__(HIDWORD(pParty->pPartyBuffs[PARTY_BUFF_INVISIBILITY].uExpireTime),
				// v22); v49 =
				// HIDWORD(pParty->pPartyBuffs[PARTY_BUFF_INVISIBILITY].uExpireTime)
				// == v22; v50 =
				// HIDWORD(pParty->pPartyBuffs[PARTY_BUFF_INVISIBILITY].uExpireTime)
				// - v22 < 0;
				actor.vVelocity.y = 0;
				actor.vVelocity.x = 0;
				if (pParty->pPartyBuffs[PARTY_BUFF_INVISIBILITY].Active())
				{
					pParty->pPartyBuffs[PARTY_BUFF_INVISIBILITY].Reset();
				}

				actor.vVelocity.x = fixpoint_mul(58500, actor.vVelocity.x);
				actor.vVelocity.y = fixpoint_mul(58500, actor.vVelocity.y);
				actor.vVelocity.z = fixpoint_mul(58500, actor.vVelocity.z);
			}
			else
			{
				Actor::AI_FaceObject(actor.id, collision_state.pid, 0, nullptr);
				actor.vVelocity.x = fixpoint_mul(58500, actor.vVelocity.x);
				actor.vVelocity.y = fixpoint_mul(58500, actor.vVelocity.y);
				actor.vVelocity.z = fixpoint_mul(58500, actor.vVelocity.z);
			}
			continue;
		}

		if (type == OBJECT_Decoration)
		{
			unsigned int speed = integer_sqrt(
				actor.vVelocity.x * actor.vVelocity.x +
				actor.vVelocity.y * actor.vVelocity.y);
			int angle = TrigLUT.atan2(actor.vPosition.x - pLevelDecorations[id].vPosition.x, actor.vPosition.y - pLevelDecorations[id].vPosition.y); // Face away from the decoration.
			actor.vVelocity.x = TrigLUT.cos(angle) * speed;
			actor.vVelocity.y = TrigLUT.sin(angle) * speed;
			actor.vVelocity.x = fixpoint_mul(58500, actor.vVelocity.x);
			actor.vVelocity.y = fixpoint_mul(58500, actor.vVelocity.y);
			actor.vVelocity.z = fixpoint_mul(58500, actor.vVelocity.z);
			continue;
		}

		if (type == OBJECT_Face)
		{
			BLVFace* face = &pIndoor->pFaces[id];

			collision_state.ignored_face_id = PID_ID(collision_state.pid);
			if (pIndoor->pFaces[id].uPolygonType == PolygonType::Floor)
			{
				actor.vVelocity.z = 0;
				actor.vPosition.z = pIndoor->pVertices[face->pVertexIDs[0]].z + 1;
				if (glm::length2(Vec3f(actor.vVelocity)) < 400)
				{
					actor.vVelocity.x = 0;
					actor.vVelocity.y = 0;
					continue;
				}
			}
			else
			{
				float velocityDotNormal = glm::dot(face->pFacePlane.vNormal, Vec3f(actor.vVelocity));
				velocityDotNormal = std::max(std::abs(velocityDotNormal), collision_state.speed / 8);
				actor.vVelocity += velocityDotNormal * face->pFacePlane.vNormal;
				if (face->uPolygonType != PolygonType::InBetweenFloorAndWall && face->uPolygonType != PolygonType::Floor)
				{
					float overshoot =
						collision_state.radius_lo - face->pFacePlane.signedDistanceTo(actor.vPosition);
					if (overshoot > 0)
						actor.vPosition += overshoot * pIndoor->pFaces[id].pFacePlane.vNormal;
					actor.uYawAngle = TrigLUT.atan2(actor.vVelocity.x, actor.vVelocity.y);
				}
			}
			if (pIndoor->pFaces[id].uAttributes & FaceAttribute::TriggerByMonster)
				EventProcessor(pIndoor->pFaceExtras[pIndoor->pFaces[id].uFaceExtraID].uEventID, 0, 1);
		}

		actor.vVelocity.x = fixpoint_mul(58500, actor.vVelocity.x);
		actor.vVelocity.y = fixpoint_mul(58500, actor.vVelocity.y);
		actor.vVelocity.z = fixpoint_mul(58500, actor.vVelocity.z);
	}
}

void ProcessActorCollisionsODM(Actor& actor, bool isFlying)
{
	int actorRadius = !isFlying ? 40 : actor.uActorRadius;

	collision_state.ignored_face_id = -1;
	collision_state.total_move_distance = 0;
	collision_state.check_hi = true;
	collision_state.radius_hi = actorRadius;
	collision_state.radius_lo = actorRadius;

	for (int attempt = 0; attempt < 100; ++attempt)
	{
		collision_state.position_lo = Vec3f(actor.vPosition) + Vec3f(0, 0, actorRadius + 1);
		collision_state.position_hi = Vec3f(actor.vPosition) + Vec3f(0, 0, actor.uActorHeight - actorRadius - 1);
		collision_state.position_hi.z = std::max(collision_state.position_hi.z, collision_state.position_lo.z);
		collision_state.velocity = actor.vVelocity;
		collision_state.uSectorID = 0;
		if (collision_state.PrepareAndCheckIfStationary(0))
			break;

		CollideOutdoorWithModels(true);
		CollideOutdoorWithDecorations(WorldPosToGridCellX(actor.vPosition.x), WorldPosToGridCellY(actor.vPosition.y));
		CollideWithParty(false);
		_46ED8A_collide_against_sprite_objects(PID(OBJECT_Actor, actor.id));

		int actorCollisions = 0;
		for (int i = 0; i < ai_arrays_size; i++)
			if (ai_near_actors_ids[i] != actor.id && CollideWithActor(ai_near_actors_ids[i], 40))
				actorCollisions++;
		int isInCrowd = actorCollisions > 1;

		//if (collision_state.adjusted_move_distance < collision_state.move_distance)
		//    Slope_High = collision_state.adjusted_move_distance * collision_state.direction.z;

		bool isOnWater = false;
		int modelPid = 0;
		int floorZ = ODM_GetFloorLevel(Vec3i(collision_state.new_position_lo) - Vec3i(0, 0, collision_state.radius_lo + 1),
			actor.uActorHeight, &isOnWater, &modelPid, 0);
		if (isOnWater)
		{
			if (actor.vPosition.z < floorZ + 60)
			{
				if (actor.uAIState == Dead || actor.uAIState == Dying ||
					actor.uAIState == Removed || actor.uAIState == Disabled)
				{
					SpriteObject::createSplashObject(Vec3i(actor.vPosition.x, actor.vPosition.y, modelPid ? floorZ + 30 : floorZ + 60));
					actor.uAIState = Removed;
					break;
				}
			}
		}

		if (collision_state.adjusted_move_distance >= collision_state.move_distance)
		{
			actor.vPosition = collision_state.new_position_lo - Vec3f(0, 0, collision_state.radius_lo + 1);
			break;
		}

		actor.vPosition += collision_state.adjusted_move_distance * collision_state.direction;
		collision_state.total_move_distance += collision_state.adjusted_move_distance;

		unsigned int v39 = PID_ID(collision_state.pid);
		int Angle_To_Decor;
		signed int Coll_Speed;
		switch (PID_TYPE(collision_state.pid))
		{
		case OBJECT_Actor:
			if (pTurnEngine->turn_stage != TE_ATTACK && pTurnEngine->turn_stage != TE_MOVEMENT || !pParty->bTurnBasedModeOn)
			{
				// if(pParty->bTurnBasedModeOn)
				// v34 = 0;
				if (actor.pMonsterInfo.uHostilityType)
				{
					if (isInCrowd == 0)
						Actor::AI_Flee(actor.id, collision_state.pid, 0, nullptr);
					else
						Actor::AI_StandOrBored(actor.id, 4, 0, nullptr);
				}
				else if (isInCrowd)
				{
					Actor::AI_StandOrBored(actor.id, 4, 0, nullptr);
				}
				else if (pActors[v39].pMonsterInfo.uHostilityType == MONSTER_HOSTILITY_RADIUS_FRIENDLY)
				{
					Actor::AI_Flee(actor.id, collision_state.pid, 0, nullptr);
				}
				else
				{
					Actor::AI_FaceObject(actor.id, collision_state.pid, 0, nullptr);
				}
			}
			break;
		case OBJECT_Player:
			if (!actor.GetActorsRelation(0))
			{
				Actor::AI_FaceObject(actor.id, collision_state.pid, 0, nullptr);
				break;
			}

			actor.vVelocity.y = 0;
			actor.vVelocity.x = 0;

			if (pParty->pPartyBuffs[PARTY_BUFF_INVISIBILITY].Active())
			{
				pParty->pPartyBuffs[PARTY_BUFF_INVISIBILITY].Reset();
			}
			break;
		case OBJECT_Decoration:
			Coll_Speed = integer_sqrt(actor.vVelocity.x * actor.vVelocity.x +
				actor.vVelocity.y * actor.vVelocity.y);
			Angle_To_Decor = TrigLUT.atan2(actor.vPosition.x - pLevelDecorations[v39].vPosition.x,
				actor.vPosition.y - pLevelDecorations[v39].vPosition.y);

			actor.vVelocity.x = TrigLUT.cos(Angle_To_Decor) * Coll_Speed;
			actor.vVelocity.y = TrigLUT.sin(Angle_To_Decor) * Coll_Speed;
			break;
		case OBJECT_Face:
		{
			ODMFace* face = &pOutdoor->pBModels[collision_state.pid >> 9].pFaces[v39 & 0x3F];
			if (!face->IsEthereal())
			{
				if (face->uPolygonType == PolygonType::Floor)
				{
					actor.vVelocity.z = 0;
					actor.vPosition.z = pOutdoor->pBModels[collision_state.pid >> 9].pVertices[face->pVertexIDs[0]].z + 1;
					if (actor.vVelocity.x * actor.vVelocity.x +
						actor.vVelocity.y * actor.vVelocity.y < 400)
					{
						actor.vVelocity.y = 0;
						actor.vVelocity.x = 0;
					}
				}
				else
				{
					float v72b = glm::dot(face->pFacePlane.vNormal, Vec3f(actor.vVelocity));
					if ((collision_state.speed / 8) > v72b)
						v72b = collision_state.speed / 8;

					actor.vVelocity += v72b * face->pFacePlane.vNormal;
					if (face->uPolygonType != PolygonType::InBetweenFloorAndWall)
					{
						float v46 = collision_state.radius_lo - face->pFacePlane.signedDistanceTo(actor.vPosition);
						if (v46 > 0)
							actor.vPosition += v46 * face->pFacePlane.vNormal;
						actor.uYawAngle = TrigLUT.atan2(actor.vVelocity.x, actor.vVelocity.y);
					}
				}
			}
		}
		break;
		default:
			break;
		}

		actor.vVelocity.x = fixpoint_mul(58500, actor.vVelocity.x);
		actor.vVelocity.y = fixpoint_mul(58500, actor.vVelocity.y);
		actor.vVelocity.z = fixpoint_mul(58500, actor.vVelocity.z);

		actorRadius = collision_state.radius_lo;
	}
}
