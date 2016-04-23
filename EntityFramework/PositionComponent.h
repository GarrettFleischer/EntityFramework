#pragma once

#include "Component.h"

using namespace EntitySystem;

class PositionComponent : public Component
{
public:
	PositionComponent(float x = 0, float y = 0);
	virtual ~PositionComponent();

	// Should be implemented in all derived Component classes
	static const ComponentType type() { return unique_type; }

	float x() const { return m_x; }
	void x(float x) { m_prev_x = m_x; m_x = x; }

	float y() const { return m_y; }
	void y(float y) { m_prev_y = m_y; m_y = y; }

	float prev_x() const { return m_prev_x; }
	float prev_y() const { return m_prev_y; }

private:
	// Should be implemented in all derived Component classes
	static const ComponentType unique_type;

	float m_x;
	float m_y;

	float m_prev_x;
	float m_prev_y;
};

