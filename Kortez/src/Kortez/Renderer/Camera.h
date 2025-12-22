#pragma once

#include <glm/glm.hpp>

namespace Kortez {
	class Camera {
	private:
		glm::mat4 m_View{ 1.0f };
		glm::mat4 m_Projection{ 1.0f };
		glm::mat4 m_ViewProjection{ 1.0f };

		glm::vec3 m_Position{ 5.0f, 5.0f, 5.0f };
		glm::vec3 m_Target{ 0.0f };

		void RecalculateView();
	public:
		Camera(float fov, float aspectRatio, float nearClip, float farClip);

		const glm::mat4& GetViewMatrix() const {
			return m_View;
		}

		const glm::mat4& GetProjectionMatrix() const {
			return m_Projection;
		}

		const glm::mat4& GetViewProjectionMatrix() const {
			return m_ViewProjection;
		}

		void SetPosition(const glm::vec3& position);
		const glm::vec3& GetPosition() const {
			return m_Position;
		}
		void LookAt(const glm::vec3& target);
	};
}