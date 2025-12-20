#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Kortez {
	Camera::Camera(float fov, float aspectRatio, float nearClip, float farClip) {
        m_Projection = glm::perspective(
            glm::radians(fov),
            aspectRatio,
            nearClip,
            farClip
        );

        RecalculateView();
	}

    void Camera::SetPosition(const glm::vec3& position) {
        m_Position = position;
        RecalculateView();
    }

    void Camera::LookAt(const glm::vec3& target) {
        m_Target = target;
        RecalculateView();
    }

    void Camera::RecalculateView() {
        m_View = glm::lookAt(
            m_Position,
            m_Target,
            { 0.0f, 1.0f, 0.0f }
        );

        m_ViewProjection = m_Projection * m_View;
    }
}