#pragma once

#include "System.h"

using namespace EntitySystem;


class ControlSystem : public System
{
public:
	ControlSystem(EntityManager *manager);
	virtual ~ControlSystem();

	virtual void Update() override;

};

