#include "PhysicsSystem.h"

#include <cmath>

#include "PhysicsComponent.h"
#include "PositionComponent.h"


PhysicsSystem::PhysicsSystem(EntityManager *manager)
	: System(manager, { PhysicsComponent::type(), PositionComponent::type() })
{}


PhysicsSystem::~PhysicsSystem()
{}

void PhysicsSystem::Update()
{
	for (EID entity : entities())
	{
		PositionComponent *pos = manager()->GetComponent<PositionComponent>(entity);
		PhysicsComponent *phy = manager()->GetComponent<PhysicsComponent>(entity);

		pos->x(pos->x() + phy->hspeed());
		pos->y(pos->y() + phy->vspeed());

		if (CollisionFor(entity) != entity)
		{
			pos->x(round(pos->prev_x()));
			pos->y(round(pos->prev_y()));
		}
	}
}

EntitySystem::EID PhysicsSystem::CollisionFor(EID initial)
{
	EID found = initial;
	PositionComponent *ipos = manager()->GetComponent<PositionComponent>(initial);
	PhysicsComponent *iphy = manager()->GetComponent<PhysicsComponent>(initial);

	if (iphy->solid())
	{
		for (EID entity : entities())
		{
			if (entity != initial)
			{
				PositionComponent *pos = manager()->GetComponent<PositionComponent>(entity);
				PhysicsComponent *phy = manager()->GetComponent<PhysicsComponent>(entity);

				if (phy->solid())
				{
					float diff_x = (pos->x() - ipos->x());
					float diff_y = (pos->y() - ipos->y());

					float dist = sqrt(pow(diff_x, 2) + pow(diff_y, 2));

					if (diff_x > 0 && dist < phy->bounds().width ||
						diff_x < 0 && dist < iphy->bounds().width ||
						diff_y > 0 && dist < phy->bounds().height ||
						diff_y < 0 && dist < iphy->bounds().height)
					{
						found = entity;
						break;
					}
				}
			}
		}
	}

	return found;
}
