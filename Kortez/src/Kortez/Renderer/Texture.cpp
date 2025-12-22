#include "Texture.h"
#include "OpenGL/OpenGLTexture2D.h"

namespace Kortez {
	std::shared_ptr<Texture> Texture::Create(const std::string& path) {
		return std::make_shared<OpenGLTexture2D>(path);
	}
}