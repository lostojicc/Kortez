#include "AppLayer.h"

#include "Kortez/Renderer/Renderer.h"

AppLayer::AppLayer() {}

AppLayer::~AppLayer() {}

void AppLayer::OnRender() {
	Kortez::Renderer::BeginScene();
	Kortez::Renderer::SubmitTriangle();
	Kortez::Renderer::EndScene();
}

void AppLayer::OnUpdate(float dt) {}