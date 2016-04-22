#include "PlayerComponent.h"

const ComponentType PlayerComponent::unique_type = Component::getUniqueType();

PlayerComponent::PlayerComponent()
	: Component(unique_type)
{}

PlayerComponent::~PlayerComponent()
{}

