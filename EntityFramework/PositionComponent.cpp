#include "PositionComponent.h"

// Should be implemented in all derived Component classes
const ComponentType PositionComponent::unique_type = Component::getUniqueType();


PositionComponent::PositionComponent(short x, short y)
	: Component(unique_type), m_x(x), m_y(y)
{}


PositionComponent::~PositionComponent()
{}
