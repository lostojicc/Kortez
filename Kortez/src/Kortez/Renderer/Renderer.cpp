#include "Kortez/Renderer/Renderer.h"
#include "VertexArray.h"
#include "Kortez/Renderer/OpenGL/OpenGLVertexArray.h"
#include "Kortez/Renderer/OpenGL/OpenGLVertexBuffer.h"
#include "Kortez/Renderer/OpenGL/OpenGLIndexBuffer.h"
#include "Kortez/Renderer/Shader.h"
#include "Kortez/Renderer/Texture.h"

namespace Kortez {
    static std::shared_ptr<VertexArray> s_CubeVAO;
    static std::shared_ptr<Shader> s_Shader;
    static std::shared_ptr<Texture> s_Texture;
    static glm::mat4 s_ViewProjection;

    void Renderer::Init() {
        RenderCommand::Init();

        s_Shader = Shader::Create("assets/shaders/simple.vert", "assets/shaders/simple.frag");
        s_Texture = Texture::Create("assets/textures/container.png");

        float vertices[] = {
            // Front face (+Z)
            -0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f,   0.0f, 0.0f,
             0.5f, -0.5f,  0.5f,   0.0f,  0.0f,  1.0f,   1.0f, 0.0f,
             0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f,   1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,   0.0f,  0.0f,  1.0f,   0.0f, 1.0f,

            // Back face (-Z)
             0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,   0.0f,  0.0f, -1.0f,   1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
             0.5f,  0.5f, -0.5f,   0.0f,  0.0f, -1.0f,   0.0f, 1.0f,

             // Left (-X)
             -0.5f, -0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
             -0.5f, -0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,   1.0f, 0.0f,
             -0.5f,  0.5f,  0.5f,  -1.0f,  0.0f,  0.0f,   1.0f, 1.0f,
             -0.5f,  0.5f, -0.5f,  -1.0f,  0.0f,  0.0f,   0.0f, 1.0f,

             // Right (+X)
              0.5f, -0.5f,  0.5f,   1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
              0.5f, -0.5f, -0.5f,   1.0f,  0.0f,  0.0f,   1.0f, 0.0f,
              0.5f,  0.5f, -0.5f,   1.0f,  0.0f,  0.0f,   1.0f, 1.0f,
              0.5f,  0.5f,  0.5f,   1.0f,  0.0f,  0.0f,   0.0f, 1.0f,

              // Top (+Y)
              -0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f,   0.0f, 0.0f,
               0.5f,  0.5f,  0.5f,   0.0f,  1.0f,  0.0f,   1.0f, 0.0f,
               0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f,   1.0f, 1.0f,
              -0.5f,  0.5f, -0.5f,   0.0f,  1.0f,  0.0f,   0.0f, 1.0f,

              // Bottom (-Y)
              -0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,   0.0f, 0.0f,
               0.5f, -0.5f, -0.5f,   0.0f, -1.0f,  0.0f,   1.0f, 0.0f,
               0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,   1.0f, 1.0f,
              -0.5f, -0.5f,  0.5f,   0.0f, -1.0f,  0.0f,   0.0f, 1.0f
        };


        uint32_t indices[] = {
             0,  1,  2,  2,  3,  0, 
             4,  5,  6,  6,  7,  4,   
             8,  9, 10, 10, 11,  8,   
            12, 13, 14, 14, 15, 12,   
            16, 17, 18, 18, 19, 16,   
            20, 21, 22, 22, 23, 20    
        };

        BufferLayout layout = {
            { ShaderDataType::Float3 },
            { ShaderDataType::Float3 },
            { ShaderDataType::Float2 }
        };

        s_CubeVAO = std::make_shared<OpenGLVertexArray>();

        auto vbo = std::make_shared<OpenGLVertexBuffer>(
            vertices,
            sizeof(vertices)
        );
        vbo->SetLayout(layout);

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

    void Renderer::SubmitCube(const glm::mat4& transform, const glm::vec3& cameraPos) {
        s_Shader->Bind();

        s_Shader->SetMat4("u_ViewProjection", s_ViewProjection);
        s_Shader->SetMat4("u_Model", transform);
        s_Shader->SetVec3("viewPos", cameraPos);
        s_Shader->SetInt("diffuseMap", 0);
        
        s_Texture->Bind(static_cast<uint32_t>(0));

        s_CubeVAO->Bind();
        RenderCommand::DrawIndexed(36);
    }
}
