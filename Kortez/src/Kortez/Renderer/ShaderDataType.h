#pragma once

#include <cstdint>

namespace Kortez {
	enum class ShaderDataType {
		None = 0, Float, Float2, Float3, Float4
	};

	static uint32_t ShaderDataTypeSize(ShaderDataType type) {
		switch (type) {
			case Kortez::ShaderDataType::Float:
				return 4;
			case Kortez::ShaderDataType::Float2:
				return 8;
			case Kortez::ShaderDataType::Float3:
				return 12;
			case Kortez::ShaderDataType::Float4:
				return 16;
		}

		return 0;
	}
}