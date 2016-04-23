#include "PhysicsComponent.h"

#include <math.h>

// Should be implemented in all derived Component classes
const ComponentType PhysicsComponent::unique_type = Component::getUniqueType();


PhysicsComponent::PhysicsComponent(Boundary bounds, bool solid, float speed, int direction)
	: Component(unique_type), m_speed(speed), m_direction((float)direction),
		m_hspeed(0.0f), m_vspeed(0.0f), m_bounds(bounds), m_solid(solid)
{}


PhysicsComponent::~PhysicsComponent()
{}

void PhysicsComponent::speed(float speed)
{
	m_speed = speed;

	m_hspeed = cos(m_direction) * m_speed;
	m_vspeed = sin(m_direction) * m_speed;
}

void PhysicsComponent::direction(int direction)
{
	// convert to radians
	m_direction = (float)((float)direction * PI / 180.0f);

	speed(m_speed);
}
