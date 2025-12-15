#pragma once

#include "Kortez/Renderer/VertexBuffer.h"
#include "Kortez/Renderer/IndexBuffer.h"

#include <memory>

namespace Kortez {
	class VertexArray {
	public:
		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& VBO) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& EBO) = 0;
	};
}