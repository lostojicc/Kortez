#include "Kortez/Renderer/Renderer.h"
#include "VertexArray.h"
#include "Kortez/Renderer/OpenGL/OpenGLVertexArray.h"
#include "Kortez/Renderer/OpenGL/OpenGLVertexBuffer.h"
#include "Kortez/Renderer/OpenGL/OpenGLIndexBuffer.h"
#include "Kortez/Renderer/Shader.h"

#include <glad/gl.h>

namespace Kortez {
    static std::shared_ptr<VertexArray> s_TriangleVAO;
    static std::shared_ptr<Shader> s_Shader;

    void Renderer::Init() {
        RenderCommand::Init();

        s_Shader = Shader::Create("assets/shaders/simple.vert", "assets/shaders/simple.frag");

        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };

        s_TriangleVAO = std::make_shared<OpenGLVertexArray>();
        auto VBO = std::make_shared<OpenGLVertexBuffer>(vertices, sizeof(vertices));
        s_TriangleVAO->AddVertexBuffer(VBO);
    }

    void Renderer::Shutdown() {

    }

    void Renderer::BeginScene() {
        RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
        RenderCommand::Clear();
    }

    void Renderer::EndScene() {
    }

    void Renderer::SubmitTriangle() {
        s_Shader->Bind();
        s_TriangleVAO->Bind();
        RenderCommand::DrawArrays(3);
    }

}
