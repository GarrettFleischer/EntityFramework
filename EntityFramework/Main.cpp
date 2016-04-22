#include "RenderComponent.h"
#include "PlayerComponent.h"

using namespace EntitySystem;

int main()
{
	RenderComponent a;
	PlayerComponent b;

	if (a.type() == RenderComponent::type())
	{
		RenderComponent d;
	}

	if (b.type() == PlayerComponent::type())
	{
		RenderComponent d;
	}

	if (PlayerComponent::type() == RenderComponent::type())
	{
		RenderComponent d;
	}

	return 0;
}