#pragma once

/****************************************************************************
*	class Component
*
*	Component(ComponentType)
*		initializes this Component with the given type
*		type should be static for all instances of the subclass
*
*	type() : ComponentType
*		returns the static type of this subclass of Component
*
*	getUniqueType() : ComponentType static
*		Call once at static initialization time for each subclass
*		to receive a unique type. (see example components)
****************************************************************************/

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

