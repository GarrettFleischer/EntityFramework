// Let the debug log show file and line numbers of the "new" causing memory leaks.
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#define new new( _CLIENT_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG

#include "EntityManager.h"
#include "SystemManager.h"

#include "RenderSystem.h"
#include "InputSystem.h"
#include "ControlSystem.h"
#include "PhysicsSystem.h"

#include "GraphicsComponent.h"
#include "PositionComponent.h"
#include "PlayerComponent.h"
#include "PhysicsComponent.h"

#include "Keyboard.h"

using namespace EntitySystem;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	bool running = true;

	EntityManager manager;
	SystemManager systems({ new RenderSystem(&manager), new InputSystem(running), new ControlSystem(&manager), new PhysicsSystem(&manager) });

	// player
	manager.CreateEntity({ new PlayerComponent(), new PositionComponent(7, 8), new PhysicsComponent({0,0,1,1}, true),  new GraphicsComponent() });

	// bushes
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(3, 3), new PhysicsComponent({ 0,0,1,1 }, true) });
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(4, 8), new PhysicsComponent({ 0,0,1,1 }, true) });
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(1, 15), new PhysicsComponent({ 0,0,1,1 }, true) });
	manager.CreateEntity({ new GraphicsComponent('*', 2), new PositionComponent(12, 10), new PhysicsComponent({ 0,0,1,1 }, true) });

	// Update the manager and systems (press "Esc" to break out of loop)
	while (running)
	{
		Keyboard::Update();

		manager.Update();
		systems.Update();
	}

	return 0;
}