#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>

namespace Kortez {
	struct WindowSpecification {
		std::string Title;
		uint32_t Width = 1280;
		uint32_t Height = 720;
		bool isResizable = true;
		bool VSync = true;
	};

	class Window {
	private:
		WindowSpecification m_Specification;
		GLFWwindow* m_Handle = nullptr;

	public:
		Window(const WindowSpecification& specification = WindowSpecification());
		~Window();

		void Create();
		void Destroy();
		void Update();

		glm::vec2 GetFramebufferSize();

		bool ShouldClose() const;
	};
}