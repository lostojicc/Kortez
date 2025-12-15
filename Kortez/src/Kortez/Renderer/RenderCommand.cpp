#include "Kortez/Renderer/RenderCommand.h"
#include "Kortez/Renderer/OpenGL/OpenGLRendererAPI.h"

namespace Kortez {
	std::unique_ptr<RendererAPI> RenderCommand::s_RendererAPI = std::make_unique<OpenGLRendererAPI>();
}