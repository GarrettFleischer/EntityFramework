#include "SystemManager.h"

namespace EntitySystem
{

	SystemManager::SystemManager()
	{}

	SystemManager::SystemManager(list<System *> systems)
		: m_sytems(systems)
	{}

	SystemManager::~SystemManager()
	{
		for (auto it = m_sytems.begin(); it != m_sytems.end(); ++it)
			delete (*it);
		m_sytems.clear();
	}

	void SystemManager::AddSystems(list<System *> systems)
	{
		for (auto it = systems.begin(); it != systems.end(); ++it)
			m_sytems.push_back(*it);
	}

	void SystemManager::RemoveSystems(list<System *> systems)
	{
		for (auto it = systems.begin(); it != systems.end(); ++it)
			m_sytems.remove(*it);
	}

	void SystemManager::Update()
	{
		for (auto it = m_sytems.begin(); it != m_sytems.end(); ++it)
			(*it)->Update();
	}

}
