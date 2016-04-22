#pragma once

namespace EntitySystem
{
	typedef unsigned int ComponentType;

	class Component
	{
	public:
		virtual ~Component() {}

		ComponentType type() const { return m_type; }

	protected:
		Component(ComponentType type) : m_type(type){}

		static ComponentType getUniqueType() { return m_unique++; }

	private:
		ComponentType m_type;
		static ComponentType m_unique;
	};
}

