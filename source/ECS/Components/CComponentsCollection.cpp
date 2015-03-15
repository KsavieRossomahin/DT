#include "CComponentsCollection.h"

CComponentsCollection::CComponentsCollection()
{
}

CComponentsCollection::~CComponentsCollection()
{
	for(auto component: _components_map)
		delete component.second;
	_components_map.clear();
}

size_t CComponentsCollection::size()
{
	return _components_map.size();
}