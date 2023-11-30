#pragma once
#include <glm/glm.hpp>

using color3_t = glm::vec3;
using color4_t = glm::vec4;
using rgba_t = uint32_t;



	inline color4_t RGBAToColor(const rgba_t& rgba) {
		color4_t color{ 0 };

		color.r = (rgba & ((1 << 8) - 1) << 24) / 255.0f;
		color.g = (rgba & ((1 << 8) - 1) << 16) / 255.0f;
		color.b = (rgba & ((1 << 8) - 1) << 8) / 255.0f;
		color.a = (rgba & ((1 << 8) - 1) << 0) / 255.0f;

		return color;
	}

	inline rgba_t ColorToRGBA(const color4_t& color) {
		rgba_t rgba = 0;
		rgba |= uint8_t(glm::clamp(color.r, 0.0f, 1.0f) * 255) << 24;
		rgba |= uint8_t(glm::clamp(color.g, 0.0f, 1.0f) * 255) << 16;
		rgba |= uint8_t(glm::clamp(color.b, 0.0f, 1.0f) * 255) << 8;
		rgba |= uint8_t(glm::clamp(color.a, 0.0f, 1.0f) * 255) << 0;

		return rgba;
	}
