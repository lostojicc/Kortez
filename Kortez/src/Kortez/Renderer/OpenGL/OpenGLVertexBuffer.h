#pragma once

#include "Kortez/Renderer/VertexBuffer.h"

#include <glad/gl.h>

namespace Kortez {
	class OpenGLVertexBuffer : public VertexBuffer {
	private:
		uint32_t m_RendererID;
		std::vector<float> m_Data;

	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer();

		void Bind() const override;
		void Unbind() const override;

		const std::vector<float>& GetData() const override {
			return m_Data;
		}
	};
}