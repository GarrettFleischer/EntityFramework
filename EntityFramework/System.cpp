#include "System.h"

namespace EntitySystem
{

	System::System(EntityManager *manager, list<ComponentType> types)
		: View(manager), m_types(types)
	{}

	System::~System()
	{
		if(model())
			model()->Remove(*this);
	}

	void System::ModelUpdated()
	{
		if(manager())
			m_entities = manager()->GetAllEntitiesWithComponents(m_types);
	}

}