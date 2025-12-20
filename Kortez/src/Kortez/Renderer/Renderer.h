#pragma once

#include "Kortez/Renderer/RenderCommand.h"
#include "Camera.h"

#include <glm/glm.hpp>

namespace Kortez {
	class Renderer {
	public: 
		static void Init();
		static void Shutdown();

		static void BeginScene(const Camera& camera);
		static void EndScene();

		static void SubmitTriangle();
		static void SubmitCube(const glm::mat4& transform);
	};
}