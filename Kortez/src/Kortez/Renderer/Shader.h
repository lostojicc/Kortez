#pragma once

#include <string>
#include <memory>

#include <glm/glm.hpp>

namespace Kortez {
	class Shader {
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetVec3(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;

		static std::shared_ptr<Shader> Create(const std::string& vertexPath, const std::string& fragmentPath);
	};
}