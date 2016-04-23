#pragma once

#include "System.h"

using namespace EntitySystem;

class PositionComponent;


class PhysicsSystem : public System
{
public:
	PhysicsSystem(EntityManager *manager);

	virtual ~PhysicsSystem();

	virtual void Update() override;

private:
	EID CollisionFor(EID initial);

};

