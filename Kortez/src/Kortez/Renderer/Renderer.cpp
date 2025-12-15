#include "Kortez/Renderer/Renderer.h"
#include "VertexArray.h"
#include "Kortez/Renderer/OpenGL/OpenGLVertexArray.h"
#include "Kortez/Renderer/OpenGL/OpenGLVertexBuffer.h"
#include "Kortez/Renderer/OpenGL/OpenGLIndexBuffer.h"

#include <glad/gl.h>

namespace Kortez {
    static std::shared_ptr<VertexArray> s_TriangleVAO;
    static unsigned int s_ShaderProgram = 0;

    void Renderer::Init() {
        RenderCommand::Init();

        // --- setup simple shader ---
        const char* vertexShaderSource = R"(#version 330 core
            layout(location = 0) in vec3 aPos;
            void main()
            {
                gl_Position = vec4(aPos, 1.0);
            }
        )";

        const char* fragmentShaderSource = R"(#version 330 core
            out vec4 FragColor;
            void main()
            {
                FragColor = vec4(1.0, 0.5, 0.2, 1.0);
            }
        )";

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);

        s_ShaderProgram = glCreateProgram();
        glAttachShader(s_ShaderProgram, vertexShader);
        glAttachShader(s_ShaderProgram, fragmentShader);
        glLinkProgram(s_ShaderProgram);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

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
        glDeleteProgram(s_ShaderProgram);
    }

    void Renderer::BeginScene() {
        RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
        RenderCommand::Clear();
    }

    void Renderer::EndScene() {
    }

    void Renderer::SubmitTriangle() {
        glUseProgram(s_ShaderProgram);
        s_TriangleVAO->Bind();
        RenderCommand::DrawArrays(3);
    }

}
