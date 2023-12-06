#pragma once
#include <glm/glm.hpp>


	template <typename T>
	inline T lerp(const T& a, const T& b, float t)
	{
		return (a * (1 - t)) + (t * b);
	}

	inline glm::vec3 cross(const glm::vec3& v1, const glm::vec3& v2)
	{
		return glm::vec3{ v1.y * v2.z - v1.z * v1.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
	}

	inline float dot(const glm::vec3& v1, const glm::vec3& v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	}

	inline glm::vec3 normalize(const glm::vec3 v)
	{
		auto mag = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));

		glm::vec3 normal = glm::vec3{ v.x / mag, v.y / mag, v.z / mag };
		return normal;
	}

	inline glm::vec3 reflect(const glm::vec3& v, const glm::vec3& n)
	{
		//return glm::reflect(v, n);
		return v - 2.0f * dot(normalize(n), v) * normalize(n);
	}

	inline bool refract(const glm::vec3& v, const glm::vec3& n, float index, glm::vec3& refracted)
	{
		// normalize the incoming vector (v)
		glm::vec3 nv = normalize(v);

		float dt = dot(nv, n);
		float discriminant = 1 - (index * index) * (1 - dt * dt);
		if (discriminant > 0)
		{
			refracted = index * (nv - (n * dt)) - (n * std::sqrt(discriminant));
			return true;
		}

		return false;
	}

	inline float schlick(float cosine, float index)
	{
		// calculate specular reflection coefficient, or probability of reflection
		float r0 = (1.0f - index) / (1 + index);
		r0 = r0 * r0;
		return r0 + (1.0f - r0) * (float)std::pow((1.0f - cosine), 5);
	}

	inline bool approximately(float value1, float value2)
	{
		// check if the difference between the values is less than epsilon
		return (abs(value2 - value1) < FLT_EPSILON);
	}