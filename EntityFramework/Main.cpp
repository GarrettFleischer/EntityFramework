#include "EntityManager.h"
#include "GraphicsComponent.h"
#include "PlayerComponent.h"

using namespace EntitySystem;

int main()
{
	EntityManager manager;
	
	EID player = manager.CreateEntity({ new PlayerComponent(), new GraphicsComponent() });
	EID other = manager.CreateEntity({ new GraphicsComponent() });

	list<EID> players = manager.GetAllEntitiesWithComponents({ PlayerComponent::type() });
	list<EID> renderable = manager.GetAllEntitiesWithComponents({ GraphicsComponent::type() });

	PlayerComponent *pc = manager.GetComponent<PlayerComponent>(player, PlayerComponent::type());

	return 0;
}