#include "Kortez/Renderer/Shader.h"

namespace Kortez {
	class OpenGLShader : public Shader {
	private:
		uint32_t m_RendererID;
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader() override;

		void Bind() const override;
		void Unbind() const override;

		void SetVec3(const std::string& name, const glm::vec3& value) override;
		void SetMat4(const std::string& name, const glm::mat4& value) override;
	};
}