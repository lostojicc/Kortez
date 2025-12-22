#pragma once

#include "ShaderDataType.h"

#include <vector>

namespace Kortez {
	struct BufferElement {
		ShaderDataType Type;
		uint32_t Offset;
		bool Normalized;

		BufferElement(ShaderDataType type, bool normalized = false) : Type(type), Offset(0), Normalized(normalized) {}

		uint32_t GetComponentCount() const {
			switch (Type) {
				case Kortez::ShaderDataType::Float:
					return 1;
				case Kortez::ShaderDataType::Float2:
					return 2;
				case Kortez::ShaderDataType::Float3:
					return 3;
				case Kortez::ShaderDataType::Float4:
					return 4;
			}

			return 0;
		}
	};

	class BufferLayout {
	private:
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride = 0;

		void CalculateOffsetAndStride() {
			uint32_t offset = 0;
			m_Stride = 0;

			for (auto& element : m_Elements) {
				element.Offset = offset;
				offset += ShaderDataTypeSize(element.Type);
				m_Stride += ShaderDataTypeSize(element.Type);
			}
		}
	public:
		BufferLayout() = default;

		BufferLayout(std::initializer_list<BufferElement> elements) : m_Elements(elements) {
			CalculateOffsetAndStride();
		}

		uint32_t GetStride() const {
			return m_Stride;
		}

		const std::vector<BufferElement>& GetElements() const {
			return m_Elements;
		}
	};
}