#pragma once

#include "Layer.h"
#include "Window.h"

#include <string>
#include <memory>
#include <vector>

namespace Kortez {
	struct ApplicationSpecification {
		std::string Name = "Sandbox";
		WindowSpecification WindowSpec;
	};

	class Application {
	private:
		ApplicationSpecification m_Specification;
		std::shared_ptr<Window> m_Window;
		bool m_Running = false;

		std::vector<std::unique_ptr<Layer>> m_LayerStack;
	public:
		Application(const ApplicationSpecification& specification = ApplicationSpecification());
		~Application();

		void Run();
		void Stop();

		template<typename TLayer>
		requires(std::is_base_of_v<Layer, TLayer>)
		void PushLayer() {
			m_LayerStack.push_back(std::make_unique<TLayer>());
		}

		glm::vec2 GetFramebufferSize() const;

		static Application& Get();
		static float GetTime();
	};
}