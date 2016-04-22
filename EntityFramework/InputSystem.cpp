#include "InputSystem.h"

#include "Keyboard.h"


InputSystem::InputSystem(bool & running)
	: m_running(running)
{}


InputSystem::~InputSystem()
{}

void InputSystem::Update()
{
	if (Keyboard::KeyPressed(VK_ESCAPE))
		m_running = false;
}
