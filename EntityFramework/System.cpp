#include "System.h"

namespace EntitySystem
{

	System::System(EntityManager *manager, list<ComponentType> types)
		: View(manager), m_types(types)
	{}

	System::~System()
	{
		model()->Remove(*this);
	}

	void System::ModelUpdated()
	{
		m_entities = manager()->GetAllEntitiesWithComponents(m_types);
	}

}