#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#define new new( _CLIENT_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG

#include "EntityManager.h"
#include "RenderSystem.h"
#include "GraphicsComponent.h"
#include "PositionComponent.h"
#include "PlayerComponent.h"

using namespace EntitySystem;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	EntityManager manager;
	RenderSystem sys_render(&manager);

	// player
	manager.CreateEntity({ new PlayerComponent(), new PositionComponent(7, 8), new GraphicsComponent() });

	// bushes
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(3, 3) });
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(4, 8) });
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(1, 15) });
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(12, 10) });

	// Update the manager and systems
	//while (true)
	//{
		manager.Update();
		sys_render.Update();
	//}



	return 0;
}