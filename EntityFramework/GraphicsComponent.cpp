#include "GraphicsComponent.h"

const ComponentType GraphicsComponent::unique_type = Component::getUniqueType();

GraphicsComponent::GraphicsComponent()
	: Component(unique_type)
{}

GraphicsComponent::~GraphicsComponent()
{}