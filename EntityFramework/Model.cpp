/************************************************************************
* Author:		Garrett Fleischer
* Filename:		Console.cpp
* Date Created:	2/5/16
* Modifications: N/A
*************************************************************************/
#include "Model.h"
#include "View.h"

Model::Model()
{}

Model::Model(const Model & copy)
	: m_views(copy.m_views)
{}

Model::~Model()
{}

Model & Model::operator=(const Model & rhs)
{
	if (this != &rhs)
		m_views = rhs.m_views;

	return *this;
}

void Model::Register(View & view)
{
	m_views.remove(&view); // ensure the same view isn't registered twice...
	m_views.push_back(&view);
}

void Model::Remove(View & view)
{
	m_views.remove(&view);
}

void Model::Notify()
{
	for (auto it = m_views.begin(); it != m_views.end(); ++it)
		(*it)->ModelUpdated();
}
