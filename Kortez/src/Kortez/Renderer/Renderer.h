#pragma once

#include "Kortez/Renderer/RenderCommand.h"

namespace Kortez {
	class Renderer {
	public: 
		static void Init();
		static void Shutdown();

		static void BeginScene();
		static void EndScene();

		static void SubmitTriangle();
	};
}