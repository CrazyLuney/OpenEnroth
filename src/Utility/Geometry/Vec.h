#pragma once

#include "Math/glm.hpp"

template<typename T, glm::qualifier Q = glm::defaultp>
using Vec2 = glm::vec<2, T, Q>;

using Vec2i = glm::i32vec2;
using Vec2f = glm::vec2;

static_assert(sizeof(Vec2i) == 8);
static_assert(sizeof(Vec2f) == 8);

template<typename T, glm::qualifier Q = glm::defaultp>
using Vec3 = glm::vec<3, T, Q>;

using Vec3s = glm::i16vec3;
using Vec3i = glm::i32vec3;
using Vec3f = glm::vec3;

static_assert(sizeof(Vec3s) == 6);
static_assert(sizeof(Vec3i) == 12);
static_assert(sizeof(Vec3f) == 12);

namespace Vec
{
	template <typename T>
	[[nodiscard]] inline Vec3<int> toFixpoint(const Vec3<T>& v) requires std::is_floating_point_v<T>
	{
		return { glm::round(v.x * 65536.0), glm::round(v.y * 65536.0), glm::round(v.z * 65536.0) };
	}

	template <typename T>
	[[nodiscard]] inline T length2_xy(const Vec3<T>& v) requires std::is_floating_point_v<T>
	{
		return glm::length2(v.xy());
	}

	template <typename T>
	[[nodiscard]] inline T length2_xy(const Vec3<T>& v) requires std::is_integral_v<T>
	{
		return glm::length2(Vec2f{ v.xy() });
	}
}
