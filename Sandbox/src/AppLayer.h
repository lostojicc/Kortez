#pragma once

#include "Kortez/Layer.h"
#include "Kortez/Renderer/Camera.h"

class AppLayer : public Kortez::Layer {
public: 
	AppLayer();
	virtual ~AppLayer();

	virtual void OnUpdate(float dt) override;
	virtual void OnRender() override;
private:
	Kortez::Camera m_Camera;
	float m_Rotation = 0.0f;
};