#pragma once

#include <vector>

namespace Kortez {
	class VertexBuffer {
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual const std::vector<float>& GetData() const = 0;
	};
}