#pragma once
#include "Component.h"

using namespace EntitySystem;

class PlayerComponent : public Component
{
public:

	PlayerComponent();

	virtual ~PlayerComponent();

	static const ComponentType type() { return unique_type; }

private:
	static const ComponentType unique_type;
};

