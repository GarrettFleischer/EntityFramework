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
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}


RenderSystem::~RenderSystem()
{}

void RenderSystem::Update()
{
	for (EID entity : entities())
	{
		// get graphics and position components from the EntityManager
		GraphicsComponent * gfx = manager()->GetComponent<GraphicsComponent>(entity);
		PositionComponent * pos = manager()->GetComponent<PositionComponent>(entity);

		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(out, 7);
		SetConsoleCursorPosition(out, { (SHORT)pos->prev_x(), (SHORT)pos->prev_y() });
		cout << '\0';

		// set position and color
		SetConsoleCursorPosition(out, { (SHORT)pos->x(), (SHORT)pos->y() });
		SetConsoleTextAttribute(out, gfx->color());

		// draw graphic
		cout << gfx->graphic();

		// reset color to black and white...
		SetConsoleTextAttribute(out, 7);
	}
}

