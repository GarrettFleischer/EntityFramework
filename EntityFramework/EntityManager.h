#pragma once

#include <map>
using std::map;
#include <list>
using std::list;

namespace EntitySystem
{
	typedef unsigned int EID;

	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager();

		EID CreateEntity();
		void DestroyEntity(EID);

	private:
		map<EID, list<int>> m_entities;
	};
}
