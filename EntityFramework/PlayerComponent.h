#pragma once
#include "Component.h"

namespace EntitySystem
{

	class PlayerComponent : public Component
	{
	public:

		PlayerComponent() : Component(unique_type)
		{}

		virtual ~PlayerComponent()
		{}

		static const ComponentType type() { return unique_type; }

	private:
		static const ComponentType unique_type;
	};
	const ComponentType PlayerComponent::unique_type = Component::getUniqueType();

}
