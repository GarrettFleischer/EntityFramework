#pragma once

#include "Model.h"

#include <stdexcept>
#include <map>
using std::map;
#include <list>
using std::list;

#include "Component.h"
//class Component;

namespace EntitySystem
{
	typedef unsigned int EID;

	class EntityManager : public Model
	{
	public:
		EntityManager();
		~EntityManager();

		EID CreateEntity();
		EID CreateEntity(list<Component *> components);
		void DestroyEntity(EID entity);

		void AddComponent(EID entity, Component *component);
		bool RemoveComponent(EID entity, ComponentType type);

		list<EID> GetAllEntitiesWithComponents(list<ComponentType> types);

		template<typename T>
		T * GetComponent(EID entity);

		void Update();

	private:
		EID GenerateUniqueEID();

		map<EID, list<Component *>> m_entities;
		bool m_changed;
	};

	template<typename T>
	T * EntitySystem::EntityManager::GetComponent(EID entity)
	{
		if (m_entities.count(entity) == 0)
			throw std::runtime_error("Error!\nEntity with EID does not exist!");

		for (Component * component : m_entities[entity])
		{
			if (component->type() == T::type())
				return dynamic_cast<T *>(component);
		}

		throw std::runtime_error("Error!\nCannot access component.\nEntity does not contain a component of the given type.");
	}

}
