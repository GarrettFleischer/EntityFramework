#include "RenderSystem.h"

#include <Windows.h>

#include "GraphicsComponent.h"
#include "PositionComponent.h"

#include "Console.h"

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
	Console::Clear();
	for (EID entity : entities())
	{
		// get graphics and position components from the EntityManager
		GraphicsComponent * gfx = manager()->GetComponent<GraphicsComponent>(entity);
		PositionComponent * pos = manager()->GetComponent<PositionComponent>(entity);

		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		Console::Write(pos->x(), pos->y(), gfx->graphic(), gfx->color());
	}
}

