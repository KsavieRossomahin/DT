#pragma once

#include "../Utils/std.h"

#include "CComponentPosition.h"
#include "CComponentVelocity.h"
#include "CComponentSprite.h"

class CComponentsCollection
{
public:
	CComponentsCollection();
	~CComponentsCollection();

	template <typename T>
	void addComponent();

	template <typename T>
	void removeComponent();

	template <typename T>
	T* getComponent();

	size_t size();

private:
	map <const type_info*, IComponent*> _components_map;
};

template <typename T>
void CComponentsCollection::addComponent()
{
	_components_map[&typeid(T)] = new T;
}

template <typename T>
T* CComponentsCollection::getComponent()
{
	if (_components_map.count(&typeid(T)) != 0)
	{
		return static_cast <T*> (_components_map[&typeid(T)]);
	}
	else
	{
		return NULL;
	}
}