#pragma once
#include "Component.h"

using namespace EntitySystem;

class GraphicsComponent : public Component
{
public:
	GraphicsComponent();

	virtual ~GraphicsComponent();

	static const ComponentType type() { return unique_type; }

private:
	static const ComponentType unique_type;
};

