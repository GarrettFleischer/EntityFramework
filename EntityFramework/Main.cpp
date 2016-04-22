#include "EntityManager.h"
#include "RenderSystem.h"
#include "GraphicsComponent.h"
#include "PositionComponent.h"
#include "PlayerComponent.h"

using namespace EntitySystem;

int main()
{
	EntityManager manager;
	RenderSystem sys_render(&manager);

	// player
	manager.CreateEntity({ new PlayerComponent(), new GraphicsComponent() });

	// bushes
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(3, 3) });
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(4, 8) });
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(1, 15) });
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(12, 10) });

	// Update the manager and systems
	while (true)
	{
		manager.Update();
		sys_render.Update();
	}

	return 0;
}