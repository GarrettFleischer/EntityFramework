#include "ControlSystem.h"

#include "Keyboard.h"
#include "PlayerComponent.h"
#include "PhysicsComponent.h"


ControlSystem::ControlSystem(EntityManager *manager)
	: System(manager, { PlayerComponent::type(), PhysicsComponent::type() })
{}


ControlSystem::~ControlSystem()
{}


void ControlSystem::Update()
{
	for (EID entity : entities())
	{
		PhysicsComponent *phy = manager()->GetComponent<PhysicsComponent>(entity);

		if (Keyboard::KeyReleased(VK_RIGHT) ||
			Keyboard::KeyReleased(VK_DOWN) ||
			Keyboard::KeyReleased(VK_LEFT) ||
			Keyboard::KeyReleased(VK_UP))
		{
			phy->speed(0.0f);
		}
		else
		{
			const float spd = 0.01f;

			if (Keyboard::KeyDown(VK_RIGHT))
			{
				phy->direction(0);
				phy->speed(spd);
			}
			if (Keyboard::KeyDown(VK_DOWN))
			{
				phy->direction(90);
				phy->speed(spd);
			}
			if (Keyboard::KeyDown(VK_LEFT))
			{
				phy->direction(180);
				phy->speed(spd);
			}
			if (Keyboard::KeyDown(VK_UP))
			{
				phy->direction(270);
				phy->speed(spd);
			}
		}
	}
}
