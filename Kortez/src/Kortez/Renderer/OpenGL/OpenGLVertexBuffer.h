#pragma once

#include "Kortez/Renderer/VertexBuffer.h"

#include <glad/gl.h>

namespace Kortez {
	class OpenGLVertexBuffer : public VertexBuffer {
	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;

	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer();

		void Bind() const override;
		void Unbind() const override;

		void SetLayout(const BufferLayout& layout) override {
			m_Layout = layout;
		}

		const BufferLayout& GetLayout() const override {
			return m_Layout;
		}
	};
}