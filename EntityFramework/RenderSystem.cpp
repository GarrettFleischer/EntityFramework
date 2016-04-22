#include "RenderSystem.h"

#include <Windows.h>

#include "GraphicsComponent.h"
#include "PositionComponent.h"

#include <iostream>
using std::cout;


RenderSystem::RenderSystem(EntityManager *manager)
	: System(manager, { GraphicsComponent::type(), PositionComponent::type() })
{
	// hide the blinking cursor...
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &cursorInfo);
}


RenderSystem::~RenderSystem()
{}

void RenderSystem::Update()
{
	for (EID entity : entities())
	{
		GraphicsComponent * gfx = manager()->GetComponent<GraphicsComponent>(entity);
		PositionComponent * pos = manager()->GetComponent<PositionComponent>(entity);

		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

		// set position and color
		SetConsoleCursorPosition(handle, { pos->x(), pos->y() });
		SetConsoleTextAttribute(handle, gfx->color());

		// draw graphic
		cout << gfx->graphic();

		// reset color to black and white...
		SetConsoleTextAttribute(handle, 7);
	}
}

