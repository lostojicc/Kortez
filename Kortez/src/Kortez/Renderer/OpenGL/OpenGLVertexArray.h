#pragma once

#include "Kortez/Renderer/VertexArray.h"

namespace Kortez {
	class OpenGLVertexArray : public VertexArray {
	private:
		uint32_t m_RendererID;
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;

	public:
		OpenGLVertexArray();
		~OpenGLVertexArray() override;

		void Bind() const override;
		void Unbind() const override;

		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& VBO) override;
		void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& EBO) override;
	};
}