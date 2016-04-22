#include "EntityManager.h"

#include <algorithm>
using std::find;


namespace EntitySystem
{

	EntityManager::EntityManager()
		: m_changed(false)
	{}


	EntityManager::~EntityManager()
	{
		for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
		{
			for (auto jt = it->second.begin(); jt != it->second.end(); ++jt )
				delete jt->second;
			it->second.clear();
		}
		m_entities.clear();
	}

	EID EntityManager::CreateEntity()
	{
		EID entity = GenerateUniqueEID();
		m_entities[entity] = map<ComponentType, Component *>();

		m_changed = true;

		return entity;
	}

	EID EntityManager::CreateEntity(list<Component *> components)
	{
		EID entity = GenerateUniqueEID();
		m_entities[entity] = map<ComponentType, Component *>(); // add entity to map

		for (Component * component : components) // ensure no duplicate component types
			AddComponent(entity, component);

		m_changed = true;

		return entity;
	}

	void EntityManager::DestroyEntity(EID entity)
	{
		if (m_entities.count(entity) == 0)
			throw std::runtime_error("Error!\nEntity with EID does not exist!");

		for (auto it = m_entities[entity].begin(); it != m_entities[entity].end(); ++it)
			delete it->second;
		m_entities[entity].clear();

		m_entities.erase(entity);

		m_changed = true;
	}

	void EntityManager::AddComponent(EID entity, Component *component)
	{
		if (m_entities.count(entity) == 0)
			throw std::runtime_error("Error!\nEntity with EID does not exist!");

		if(m_entities[entity].count(component->type()) == 1)
			throw std::runtime_error("Error!\nCannot add component to entity!\nDuplicate types.");

		m_entities[entity][component->type()] = component;

		m_changed = true;
	}

	void EntityManager::RemoveComponent(EID entity, ComponentType type)
	{
		if (m_entities.count(entity) == 0)
			throw std::runtime_error("Error!\nEntity with EID does not exist!");

		if (m_entities[entity].count(type) == 0)
			throw std::runtime_error("Error!\nCannot remove component from entity!\nEntity does not contain a component of the given type.");

		m_entities[entity].erase(type);

		m_changed = true;
	}

	list<EntitySystem::EID> EntityManager::GetAllEntitiesWithComponents(list<ComponentType> types)
	{
		list<EID> found_entities;

		// loop through all entities
		for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
		{
			bool found = true;

			// loop through given components
			for (ComponentType type : types)
			{
				// if it doesn't contain the component...
				if (it->second.count(type) == 0)
				{
					found = false;
					break;
				}
			}

			if (found)
				found_entities.push_back(it->first);
		}

		return found_entities;
	}



	void EntityManager::Update()
	{
		// Let any watching Systems know that the entities have changed
		if (m_changed)
		{
			m_changed = false;
			Notify();
		}
	}

	EntitySystem::EID EntityManager::GenerateUniqueEID()
	{
		EID eid = 0;

		while (m_entities.count(eid) == 1)
			++eid;

		return eid;
	}
}