#pragma once

#include "Kortez/Renderer/RendererAPI.h"

namespace Kortez {
	class OpenGLRendererAPI : public RendererAPI {
	public:
		OpenGLRendererAPI() = default;
		~OpenGLRendererAPI() override = default;

		void Init() override;

		void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
		void SetClearColor(const glm::vec4& color) override;
		void Clear() override;

		void DrawArrays(uint32_t count) override;
		void DrawIndexed(uint32_t indexCount) override;
	};
}