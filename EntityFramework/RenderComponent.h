#pragma once
#include "Component.h"

namespace EntitySystem
{

	class RenderComponent : public Component
	{
	public:
		RenderComponent() : Component(unique_type)
		{}

		virtual ~RenderComponent()
		{}

		static const ComponentType type() { return unique_type; }

	private:
		static const ComponentType unique_type;
	};
	const ComponentType RenderComponent::unique_type = Component::getUniqueType();

}
