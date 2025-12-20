#include "FileSystem.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace Kortez {
	std::string FileSystem::GetRootPath() {
		return std::string(KORTEZ_ROOT_DIR);
	}

	std::string FileSystem::ReadFile(const std::string& relativePath) {
		std::string fullPath = GetRootPath() + "/" + relativePath;

		std::ifstream file(fullPath, std::ios::in | std::ios::binary);
		if (!file)
			throw std::runtime_error("Failed to open file: " + fullPath);

		std::stringstream buffer;
		buffer << file.rdbuf();
		return buffer.str();
	}
}