#pragma once

#include "Geometry/Vec.h"

/**
 * Lookup table for trigonometric functions.
 */
class TrigTableLookup
{
public:
	static constexpr int Pi = 1024;
	static constexpr int HalfPi = 512;
	static constexpr int QuarterPi = 256;
	static constexpr int TwoPi = 2048;
	
	static constexpr int PiMask = 1023;
	static constexpr int HalfPiMask = 511;
	static constexpr int TwoPiMask = 2047;

	/**
	 * @offset 0x00452969
	 */
	TrigTableLookup();

	/**
	 * @offset 0x00402CAE
	 *
	 * @param angle                     Angle in 1/2048ths of a full circle.
	 * @return                          Cosine of the provided angle.
	 */
	float cos(int angle) const;

	/**
	 * @offset 0x0042EBDB
	 *
	 * @param angle                     Angle in 1/2048ths of a full circle.
	 * @return                          Sine of the provided angle.
	 */
	float sin(int angle) const;

	/**
	 * @offset 0x0045281E
	 *
	 * @return                          Angle in 1/2048ths of a full circle. Actual result is in range [0, 2047].
	 */
	int atan2(int x, int y) const;

	static void rotate(int depth, int yaw, int pitch, const Vec3i& v, Vec3i::value_type& outx, Vec3i::value_type& outy, Vec3i::value_type& outz)
	{
		const auto cosf_x = std::cos(M_PI * pitch / Pi);
		const auto sinf_x = std::sin(M_PI * pitch / Pi);
		const auto cosf_y = std::cos(M_PI * yaw / Pi);
		const auto sinf_y = std::sin(M_PI * yaw / Pi);

		outx = v.x + static_cast<Vec3i::value_type>(sinf_y * cosf_x * depth);
		outy = v.y + static_cast<Vec3i::value_type>(cosf_y * cosf_x * depth);
		outz = v.z + static_cast<Vec3i::value_type>(sinf_x * depth);
	}

	static void rotate(int depth, int yaw, int pitch, const Vec3i& v, Vec3i::value_type* outx, Vec3i::value_type* outy, Vec3i::value_type* outz)
	{
		assert(!!outx);
		assert(!!outy);
		assert(!!outz);

		rotate(depth, yaw, pitch, v, *outx, *outy, *outz);
	}

	static void rotate(int depth, int yaw, int pitch, const Vec3i& v, Vec3i& out)
	{
		rotate(depth, yaw, pitch, v, out.x, out.y, out.z);
	}

private:
	std::array<float, HalfPi + 1> _cosTable;
};

extern TrigTableLookup TrigLUT;
