#include "OpenGLVertexArray.h"

#include <glad/gl.h>

namespace Kortez {
    OpenGLVertexArray::OpenGLVertexArray() {
        glGenVertexArrays(1, &m_RendererID);
    }

    OpenGLVertexArray::~OpenGLVertexArray() {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void OpenGLVertexArray::Bind() const {
        glBindVertexArray(m_RendererID);
    }

    void OpenGLVertexArray::Unbind() const {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& VBO) {
        Bind();
        VBO->Bind();

        const auto& layout = VBO->GetLayout();
        uint32_t index = 0;

        for (const auto& element : layout.GetElements()) {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index++, element.GetComponentCount(), GL_FLOAT, element.Normalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)(uintptr_t)element.Offset);
        }

        m_VertexBuffers.push_back(VBO);
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& EBO) {
        Bind();
        EBO->Bind();
        m_IndexBuffer = EBO;
    }
}