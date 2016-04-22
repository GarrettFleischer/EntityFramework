#pragma once
#include "Component.h"

using namespace EntitySystem;

class GraphicsComponent : public Component
{
public:
	typedef unsigned short COLOR;

	GraphicsComponent(char graphic = '@', COLOR color = 7);

	virtual ~GraphicsComponent();

	// Should be implemented in all derived Component classes
	static const ComponentType type() { return unique_type; }

	const char graphic() const { return m_graphic; }
	const COLOR color() const { return m_color; }

private:
	// Should be implemented in all derived Component classes
	static const ComponentType unique_type;

	char m_graphic;
	COLOR m_color;
};

