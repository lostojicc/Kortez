#pragma once
#include <string>

namespace Kortez {
	class FileSystem {
	public:
		static std::string ReadFile(const std::string& relativePath);
		static std::string GetRootPath();
	};
}