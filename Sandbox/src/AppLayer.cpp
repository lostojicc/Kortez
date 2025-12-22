#include "AppLayer.h"

#include "Kortez/Renderer/Renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

AppLayer::AppLayer() : m_Camera(45.0f, 1280.0f / 720.0f, 0.1f, 1000.0f) {}

AppLayer::~AppLayer() {}

void AppLayer::OnRender() {
	Kortez::Renderer::BeginScene(m_Camera);

	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::rotate(transform, m_Rotation, glm::vec3(0.0f, 1.0f, 0.0f));

	Kortez::Renderer::SubmitCube(transform, m_Camera.GetPosition());
	Kortez::Renderer::EndScene();
}

void AppLayer::OnUpdate(float dt) {
	m_Rotation += dt;
}