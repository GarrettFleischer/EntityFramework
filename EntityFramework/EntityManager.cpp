#include "EntityManager.h"

#include <algorithm>
using std::find;


namespace EntitySystem
{

	EntityManager::EntityManager()
	{}


	EntityManager::~EntityManager()
	{
		for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
		{
			for (Component * component : it->second)
				delete component;
			it->second.clear();
		}
		m_entities.clear();
	}

	EID EntityManager::CreateEntity()
	{
		EID entity = GenerateUniqueEID();
		m_entities[entity] = list<Component *>();

		Notify();

		return entity;
	}

	EID EntityManager::CreateEntity(list<Component *> components)
	{
		EID entity = GenerateUniqueEID();
		m_entities[entity] = components;

		Notify();

		return entity;
	}

	void EntityManager::DestroyEntity(EID entity)
	{
		if (m_entities.count(entity) == 0)
			throw std::runtime_error("Error!\nEntity with EID does not exist!");

		for (Component * component : m_entities[entity])
			delete component;
		m_entities[entity].clear();

		m_entities.erase(entity);

		Notify();
	}

	void EntityManager::AddComponent(EID entity, Component *component)
	{
		if (m_entities.count(entity) == 0)
			throw std::runtime_error("Error!\nEntity with EID does not exist!");

		for (Component * c : m_entities[entity])
		{
			if (c->type() == component->type())
				throw std::runtime_error("Error!\nCannot add component to entity.\nDuplicate types.");
		}

		m_entities[entity].push_back(component);

		Notify();
	}

	bool EntityManager::RemoveComponent(EID entity, ComponentType type)
	{
		if (m_entities.count(entity) == 0)
			throw std::runtime_error("Error!\nEntity with EID does not exist!");

		for (Component * component : m_entities[entity])
		{
			if (component->type() == type)
			{
				m_entities[entity].remove(component);
				Notify();
				return true;
			}
		}

		return false;
	}

	list<EntitySystem::EID> EntityManager::GetAllEntitiesWithComponents(list<ComponentType> types)
	{
		list<EID> found_entities;

		// loop through given types
		for (ComponentType type : types)
		{
			// loop through all entities
			for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
			{
				// if this entity hasn't already been added
				if (!Contains(found_entities, it->first))
				{
					// loop through components for current entity
					for (Component * component : it->second)
					{
						if (component->type() == type)
						{
							found_entities.push_back(it->first);
							break;
						}
					}
				}
			}
		}

		return found_entities;
	}



	EntitySystem::EID EntityManager::GenerateUniqueEID()
	{
		EID eid = 0;

		while (m_entities.count(eid) == 1)
			++eid;

		return eid;
	}

	bool EntityManager::Contains(const list<EID> &lst, EID entity)
	{
		return (find(lst.begin(), lst.end(), entity) != lst.end());
	}

}