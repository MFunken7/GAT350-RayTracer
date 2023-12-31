#pragma once
#include <glm/glm.hpp>

static struct ray_t
{
	ray_t() = default;
	ray_t(const glm::vec3& origin, const glm::vec3& direction) :
		m_origin{origin.x,origin.y, origin.z},
		m_direction{direction.x, direction.y, direction.z}
	{}

	glm::vec3 GetPoint(float distance) const { return m_origin + (m_direction * distance); }
	glm::vec3 operator * (const float distance) const { return m_origin + (m_direction * distance); }

	glm::vec3 m_origin;
	glm::vec3 m_direction;
};

struct raycastHit_t
{
	// distance along the ray direction, from the origin to the hit point
	float distance = 0;

	// world point of raycast hit
	glm::vec3 point{ 0 };
	// surface normal of raycast hit
	glm::vec3 normal{ 0 };

	// material attached to hit object
	class Material* material{ nullptr };
};