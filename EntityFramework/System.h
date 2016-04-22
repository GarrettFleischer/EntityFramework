#pragma once

#include "View.h"

#include <list>
using std::list;

#include "EntityManager.h"


namespace EntitySystem
{

	class System : public View
	{
	public:
		System(EntityManager *manager, list<ComponentType> types);

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
