#pragma once

#include "System.h"

using namespace EntitySystem;

class RenderSystem : public System
{
public:
	RenderSystem(EntityManager *manager);
	virtual ~RenderSystem();

	virtual void Update() override;

};

