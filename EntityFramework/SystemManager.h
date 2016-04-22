#pragma once

#include <list>
using std::list;

#include "EntityManager.h"
#include "System.h"

namespace EntitySystem
{

	class SystemManager
	{
	public:
		SystemManager();
		SystemManager(list<System *> systems);

		~SystemManager();

		const list<System *> & systems() const { return m_sytems; }

		void AddSystems(list<System *> systems);
		void RemoveSystems(list<System *> systems);

		void Update();

	private:
		list<System *> m_sytems;
	};

}
