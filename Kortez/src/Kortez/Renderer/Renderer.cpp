#include "Kortez/Renderer/Renderer.h"
#include "VertexArray.h"
#include "Kortez/Renderer/OpenGL/OpenGLVertexArray.h"
#include "Kortez/Renderer/OpenGL/OpenGLVertexBuffer.h"
#include "Kortez/Renderer/OpenGL/OpenGLIndexBuffer.h"
#include "Kortez/Renderer/Shader.h"

namespace Kortez {
    static std::shared_ptr<VertexArray> s_CubeVAO;
    static std::shared_ptr<Shader> s_Shader;
    static glm::mat4 s_ViewProjection;

    void Renderer::Init() {
        RenderCommand::Init();

        s_Shader = Shader::Create("assets/shaders/simple.vert", "assets/shaders/simple.frag");

        float vertices[] = {
        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f
        };

        uint32_t indices[] = {
            0, 1, 2, 2, 3, 0,
            1, 5, 6, 6, 2, 1,
            5, 4, 7, 7, 6, 5,
            4, 0, 3, 3, 7, 4,
            3, 2, 6, 6, 7, 3,
            4, 5, 1, 1, 0, 4
        };

        s_CubeVAO = std::make_shared<OpenGLVertexArray>();

        auto vbo = std::make_shared<OpenGLVertexBuffer>(
            vertices,
            sizeof(vertices)
        );

        auto ibo = std::make_shared<OpenGLIndexBuffer>(
            indices,
            sizeof(indices) / sizeof(uint32_t)
        );

        s_CubeVAO->AddVertexBuffer(vbo);
        s_CubeVAO->SetIndexBuffer(ibo);
    }

    void Renderer::Shutdown() {

    }

    void Renderer::BeginScene(const Camera& camera) {
        RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
        RenderCommand::Clear();
        s_ViewProjection = camera.GetViewProjectionMatrix();
    }

    void Renderer::EndScene() {
    }

    void Renderer::SubmitCube(const glm::mat4& transform) {
        s_Shader->Bind();

        s_Shader->SetMat4("u_ViewProjection", s_ViewProjection);
        s_Shader->SetMat4("u_Model", transform);

        s_CubeVAO->Bind();
        RenderCommand::DrawIndexed(36);
    }
}
