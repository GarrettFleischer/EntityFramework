#pragma once

#include "Component.h"

using namespace EntitySystem;

class PositionComponent : public Component
{
public:
	PositionComponent(short x = 0, short y = 0);
	virtual ~PositionComponent();

	// Should be implemented in all derived Component classes
	static const ComponentType type() { return unique_type; }

	const short x() const { return m_x; }
	const short y() const { return m_y; }

private:
	// Should be implemented in all derived Component classes
	static const ComponentType unique_type;

	short m_x;
	short m_y;
};

