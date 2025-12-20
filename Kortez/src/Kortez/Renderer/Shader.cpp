#include "Shader.h"
#include "Kortez/FileSystem.h"
#include "OpenGL/OpenGLShader.h"

namespace Kortez {
	std::shared_ptr<Shader> Shader::Create(const std::string& vertexPath, const std::string& fragmentPath) {
		std::string vertexSrc = FileSystem::ReadFile(vertexPath);
		std::string fragmentSrc = FileSystem::ReadFile(fragmentPath);

		return std::make_shared<OpenGLShader>(vertexSrc, fragmentSrc);
	}
}