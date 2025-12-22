#
# Kortez
#

set(SOURCES
    vendor/stb/stb_image.h
    vendor/stb/stb_image.cpp
    src/Kortez/Application.h
    src/Kortez/Application.cpp
    src/Kortez/Window.h
    src/Kortez/Window.cpp
    src/Kortez/Layer.h
    src/Kortez/FileSystem.h
    src/Kortez/FileSystem.cpp
    src/Kortez/Renderer/Renderer.h
    src/Kortez/Renderer/Renderer.cpp
    src/Kortez/Renderer/RenderCommand.h
    src/Kortez/Renderer/RenderCommand.cpp
    src/Kortez/Renderer/RendererAPI.h
    src/Kortez/Renderer/VertexArray.h
    src/Kortez/Renderer/VertexBuffer.h
    src/Kortez/Renderer/IndexBuffer.h
    src/Kortez/Renderer/Shader.h
    src/Kortez/Renderer/Shader.cpp
    src/Kortez/Renderer/Camera.h
    src/Kortez/Renderer/Camera.cpp
    src/Kortez/Renderer/ShaderDataType.h
    src/Kortez/Renderer/Buffer.h
    src/Kortez/Renderer/Texture.h
    src/Kortez/Renderer/Texture.cpp
    src/Kortez/Renderer/OpenGL/OpenGLRendererAPI.h
    src/Kortez/Renderer/OpenGL/OpenGLRendererAPI.cpp
    src/Kortez/Renderer/OpenGL/OpenGLVertexArray.h
    src/Kortez/Renderer/OpenGL/OpenGLVertexArray.cpp
    src/Kortez/Renderer/OpenGL/OpenGLVertexBuffer.h
    src/Kortez/Renderer/OpenGL/OpenGLVertexBuffer.cpp
    src/Kortez/Renderer/OpenGL/OpenGLIndexBuffer.h
    src/Kortez/Renderer/OpenGL/OpenGLIndexBuffer.cpp
    src/Kortez/Renderer/OpenGL/OpenGLShader.h
    src/Kortez/Renderer/OpenGL/OpenGLShader.cpp
    src/Kortez/Renderer/OpenGL/OpenGLTexture2D.h
    src/Kortez/Renderer/OpenGL/OpenGLTexture2D.cpp
)

add_library(Kortez STATIC)

target_sources(Kortez PRIVATE ${SOURCES})

# Match VS filters to directory structure on disk
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

target_link_libraries(Kortez glfw)
target_link_libraries(Kortez glad)
target_link_libraries(Kortez glm)

target_include_directories(Kortez PUBLIC "src" "vendor/stb")