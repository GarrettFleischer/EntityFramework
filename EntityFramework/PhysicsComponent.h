#pragma once

#include "Component.h"
#include <cmath>

#define PI 3.14159265358979323846

using namespace EntitySystem;

class PhysicsComponent : public Component
{
public:
	struct Boundary
	{
		float x;
		float y;
		float width;
		float height;

		Boundary(float offset_x = 0.0f, float offset_y = 0.0f, float _width = 0.0f, float _height = 0.0f)
			: x(offset_x), y(offset_y), width(_width), height(_height) {}
	};

	PhysicsComponent(Boundary bounds, bool solid = false, float speed = 0, int direction = 0);

	virtual ~PhysicsComponent();

	// Should be implemented in all derived Component classes
	static const ComponentType type() { return unique_type; }


	float speed() const { return m_speed; }
	void speed(float speed);

	int direction() const { return (int)(m_direction * 180.0 / PI); }
	void direction(int direction);

	float vspeed() const { return m_vspeed; }
	void vspeed(float speed) { m_vspeed = speed; }
	float hspeed() const { return m_hspeed; }
	void hspeed(float speed) { m_hspeed = speed; }

	Boundary bounds() const { return m_bounds; }
	void bounds(Boundary bounds) { m_bounds = bounds; }

	bool solid() const { return m_solid; }
	void solid(bool solid) { m_solid = solid; }

private:
	// Should be implemented in all derived Component classes
	static const ComponentType unique_type;

	float m_speed;
	float m_direction;
	
	float m_vspeed;
	float m_hspeed;

	bool m_solid;

	Boundary m_bounds;

};

