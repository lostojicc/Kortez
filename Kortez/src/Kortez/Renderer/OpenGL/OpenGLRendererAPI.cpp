#include "Kortez/Renderer/OpenGL/OpenGLRendererAPI.h"

#include <glad/gl.h>

namespace Kortez {
	void OpenGLRendererAPI::Init() {
		glEnable(GL_DEPTH_TEST);
	}

	void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
		glViewport(x, y, width, height);
	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color) {
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRendererAPI::Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawArrays(uint32_t count) {
		glDrawArrays(GL_TRIANGLES, 0, count);
	}

	void OpenGLRendererAPI::DrawIndexed(uint32_t indexCount) {
		glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
	}
}