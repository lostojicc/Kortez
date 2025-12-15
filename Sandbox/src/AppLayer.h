#pragma once

#include "Kortez/Layer.h"

class AppLayer : public Kortez::Layer {
public: 
	AppLayer();
	virtual ~AppLayer();

	virtual void OnUpdate(float dt) override;
	virtual void OnRender() override;
};