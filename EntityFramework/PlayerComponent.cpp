#include "PlayerComponent.h"

// Should be implemented in all derived Component classes
const ComponentType PlayerComponent::unique_type = Component::getUniqueType();


PlayerComponent::PlayerComponent()
	: Component(unique_type)
{}

PlayerComponent::~PlayerComponent()
{}

