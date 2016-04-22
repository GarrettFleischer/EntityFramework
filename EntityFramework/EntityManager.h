#pragma once

#include "Model.h"

#include <stdexcept>
#include <map>
using std::map;
#include <list>
using std::list;

#include "Component.h"


/****************************************************************************
*	class EntityManager
*	
*	CreateEntity() : EID
*		creates a new entity and returns its EID
*
*	CreateEntity(components : list<Component *>) : EID
*		creates an entity with the given components and returns its EID
*		ensures no duplicate component types
*
*	DestroyEntity() : void
*		deletes the components associated with this entity
*		and removes it from the list of entities.
*
*	GetAllEntitiesWithComponents(types : list<ComponentType>) : list<EID>
*		returns a list of EIDs that contain ALL the given component types.
*
*	GetComponent(entity : EID) : T *
*		returns the component specified in the template
*		for the given EID. (Assumes that T has a static T::type() method)
*
*	GetComponent(entity : EID, type ComponentType) : T *
*		returns the component specified by the given type
*		for the given EID. (makes no assumptions about T)
*
*	Update()
*		notifies watching systems of any pending changes.
*		should be called BEFORE updating any watching Systems.
*		(Done this way to prevent invalid iterators when adding
*		and removing entities/components.)
****************************************************************************/


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
		void RemoveComponent(EID entity, ComponentType type);

		list<EID> GetAllEntitiesWithComponents(list<ComponentType> types);

		// if using Component::getUniqueType() 
		template<typename T>
		T * GetComponent(EID entity);

		// if using custom types
		template<typename T>
		T * GetComponent(EID entity, ComponentType type);

		void Update();

	private:
		EID GenerateUniqueEID();

		map<EID, map<ComponentType, Component *>> m_entities;
		bool m_changed;
	};

	template<typename T>
	T * EntitySystem::EntityManager::GetComponent(EID entity)
	{
		if (m_entities.count(entity) == 0)
			throw std::runtime_error("Error!\nEntity with EID does not exist!");

		if (m_entities[entity].count(T::type()) == 0)
			throw std::runtime_error("Error!\nCannot access component!\nEntity does not contain a component of the given type.");

		return dynamic_cast<T *>(m_entities[entity][T::type()]);
	}


	template<typename T>
	T * EntitySystem::EntityManager::GetComponent(EID entity, ComponentType type)
	{
		if (m_entities.count(entity) == 0)
			throw std::runtime_error("Error!\nEntity with EID does not exist!");

		if(m_entities[entity].count(type) == 0)
			throw std::runtime_error("Error!\nCannot access component!\nEntity does not contain a component of the given type.");

		return dynamic_cast<T *>(m_entities[entity][type]);
	}


}
