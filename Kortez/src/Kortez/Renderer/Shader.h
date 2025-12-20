#pragma once

#include <string>
#include <memory>

namespace Kortez {
	class Shader {
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static std::shared_ptr<Shader> Create(const std::string& vertexPath, const std::string& fragmentPath);
	};
}