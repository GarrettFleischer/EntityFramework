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


	char graphic() const { return m_graphic; }
	void graphic(char graphic) { m_graphic = graphic; }

	COLOR color() const { return m_color; }
	void color(COLOR color) { m_color = color; }

private:
	// Should be implemented in all derived Component classes
	static const ComponentType unique_type;

	char m_graphic;
	COLOR m_color;
};

