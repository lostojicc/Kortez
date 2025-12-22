#include "AppLayer.h"

#include "Kortez/Renderer/Renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

AppLayer::AppLayer() : m_Camera(45.0f, 1280.0f / 720.0f, 0.1f, 1000.0f) {}

AppLayer::~AppLayer() {}

void AppLayer::OnRender() {
	Kortez::Renderer::BeginScene(m_Camera);

    glm::mat4 transform1 = glm::mat4(1.0f);
    transform1 = glm::translate(transform1, glm::vec3(0.0f, 0.0f, 0.0f));
    transform1 = glm::rotate(transform1, m_Rotation, glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 transform2 = glm::mat4(1.0f);
    transform2 = glm::translate(transform2, glm::vec3(1.5f, 0.0f, 0.0f));
    transform2 = glm::rotate(transform2, m_Rotation * 1.5f, glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 transform3 = glm::mat4(1.0f);
    transform3 = glm::translate(transform3, glm::vec3(-2.0f, 0.8f, -0.5f));
    transform3 = glm::rotate(transform3, m_Rotation * 0.7f, glm::vec3(0.0f, 0.0f, 1.0f));

    Kortez::Renderer::SubmitCube(transform1, m_Camera.GetPosition());
    Kortez::Renderer::SubmitCube(transform2, m_Camera.GetPosition());
    Kortez::Renderer::SubmitCube(transform3, m_Camera.GetPosition());

	Kortez::Renderer::EndScene();
}

void AppLayer::OnUpdate(float dt) {
	m_Rotation += dt;
}