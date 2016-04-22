#pragma once
#include "Component.h"

using namespace EntitySystem;

class PlayerComponent : public Component
{
public:

	PlayerComponent();

	virtual ~PlayerComponent();

	// Should be implemented in all derived Component classes
	static const ComponentType type() { return unique_type; }

private:
	// Should be implemented in all derived Component classes
	static const ComponentType unique_type;
};

