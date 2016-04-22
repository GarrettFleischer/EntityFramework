#include "System.h"

namespace EntitySystem
{

	System::System(EntityManager *manager, list<ComponentType> types)
		: View(manager), m_types(types)
	{}

	System::~System()
	{
		getModel()->Remove(*this);
	}

	void System::ModelUpdated()
	{
		EntityManager *manager = dynamic_cast<EntityManager *>(getModel());
		m_entities = manager->GetAllEntitiesWithComponents(m_types);
	}

}