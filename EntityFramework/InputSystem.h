#pragma once

#include "System.h"

using namespace EntitySystem;

class InputSystem : public System
{
public:
	InputSystem(bool & running);
	virtual ~InputSystem();

	virtual void Update() override;

private:
	bool & m_running;
};

