#pragma once

#include "View.h"

#include <list>
using std::list;

#include "EntityManager.h"


/****************************************************************************
*	class System
*
*	System(EntityManager *, list<ComponentType>)
*		initializes this System with the given EntityManager
*		and the component types this System requires.
*
*	Update() : void
*		implement to handle logic for this System
*
*	ModelUpdated() : void override
*		Inherited from View.
*		Called when the EntityManager Model changes.
*		Automatically requests GetAllEntitiesWithComponents() with the components provided in the constructor.
*
*	entities() : list<EID>
*		returns a list of EIDs that contain ALL the component types provided in the constructor.
*
*	manager() : EntityManager *
*		returns the EntityManager provided in the constructor.
****************************************************************************/

namespace EntitySystem
{

	class System : public View
	{
	public:
		System(EntityManager *manager = nullptr, list<ComponentType> types = {});

		virtual ~System();

		virtual void Update() = 0;

	protected:
		virtual void ModelUpdated() override;

		const list<EID> & entities() const { return m_entities; }
		EntityManager * manager() { return dynamic_cast<EntityManager *>(model()); }

	private:
		list<EID> m_entities;
		list<ComponentType> m_types;
	};

}
