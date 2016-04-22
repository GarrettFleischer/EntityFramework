#include "GraphicsComponent.h"

// Should be implemented in all derived Component classes
const ComponentType GraphicsComponent::unique_type = Component::getUniqueType();


GraphicsComponent::GraphicsComponent(char graphic, COLOR color)
	: Component(unique_type), m_graphic(graphic), m_color(color)
{}

GraphicsComponent::~GraphicsComponent()
{}