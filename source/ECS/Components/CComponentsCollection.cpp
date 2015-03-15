#include "CComponentsCollection.h"

CComponentsCollection::CComponentsCollection() : _mask(ECT_NONE)
{
}

CComponentsCollection::~CComponentsCollection()
{
	for(auto component: _components_map)
		delete component.second;
	_components_map.clear();
}

void CComponentsCollection::addComponent(EComponentType type)
{
	if(type & _mask)
		return;

	_mask |= type;

	printf("mask %d\n", _mask);

	switch(type)
	{
	case ECT_NONE:
		break;
	case ECT_POSITION:
		_components_map.insert(pair <EComponentType, IComponent*> (type, new CComponentPosition));
		break;
	case ECT_VELOCITY:
		_components_map.insert(pair <EComponentType, IComponent*> (type, new CComponentVelocity));
		break;
	case ECT_SPRITE:
		_components_map.insert(pair <EComponentType, IComponent*> (type, new CComponentSprite));
		break;
	default:
		break;
	}
}

void CComponentsCollection::removeComponent(EComponentType type)
{
	if(!(type & _mask))
		return;

	_mask ^= type;
	_components_map.erase(type);
}

IComponent* CComponentsCollection::getComponent(EComponentType type)
{
	if(!(type & _mask))
		return NULL;

	return _components_map[type];
}

size_t CComponentsCollection::size()
{
	return _components_map.size();
}