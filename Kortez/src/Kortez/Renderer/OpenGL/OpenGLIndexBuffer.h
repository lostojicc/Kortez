#pragma once

#include "Kortez/Renderer/IndexBuffer.h"

namespace Kortez {
	class OpenGLIndexBuffer : public IndexBuffer {
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;

	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer() override;

		void Bind() const override;
		void Unbind() const override;

		uint32_t GetCount() const override {
			return m_Count;
		}
	};
}