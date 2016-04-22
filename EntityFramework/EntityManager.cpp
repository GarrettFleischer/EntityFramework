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

		m_changed = true;

		return entity;
	}

	EID EntityManager::CreateEntity(list<Component *> components)
	{
		EID entity = GenerateUniqueEID();
		m_entities[entity] = components;

		m_changed = true;

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

		m_changed = true;
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

		m_changed = true;
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
				m_changed = true;
				return true;
			}
		}

		return false;
	}

	list<EntitySystem::EID> EntityManager::GetAllEntitiesWithComponents(list<ComponentType> types)
	{
		list<EID> found_entities;

		// loop through all entities
		for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
		{
			int found_components = 0;
			// loop through components for current entity
			for (Component * component : it->second)
			{
				// loop through given types
				for (ComponentType type : types)
				{
					if (component->type() == type)
						++found_components;
				}
			}

			if (types.size() == found_components)
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