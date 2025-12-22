#pragma once

#include "Kortez/Renderer/Texture.h"

namespace Kortez {
	class OpenGLTexture2D : public Texture {
	private:
		std::string m_Path;
		uint32_t m_Width = 0, m_Height = 0;
		uint32_t m_RendererID = 0;
	public:
		OpenGLTexture2D(const std::string& path);
		~OpenGLTexture2D();

		uint32_t GetWidth() const override {
			return m_Width;
		}
		uint32_t GetHeight() const override {
			return m_Height;
		}

		void Bind(uint32_t slot = 0) const override;
	};
}