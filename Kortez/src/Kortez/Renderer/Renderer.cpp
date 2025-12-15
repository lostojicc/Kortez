#include "Kortez/Renderer/Renderer.h"

#include <glad/gl.h>

namespace Kortez {

    static unsigned int s_VAO = 0;
    static unsigned int s_VBO = 0;
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

        glGenVertexArrays(1, &s_VAO);
        glGenBuffers(1, &s_VBO);

        glBindVertexArray(s_VAO);
        glBindBuffer(GL_ARRAY_BUFFER, s_VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void Renderer::Shutdown() {
        glDeleteVertexArrays(1, &s_VAO);
        glDeleteBuffers(1, &s_VBO);
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
        glBindVertexArray(s_VAO);
        RenderCommand::DrawArrays(3);
    }

}
