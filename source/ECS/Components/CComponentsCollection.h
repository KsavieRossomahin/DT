#pragma once

#include "../Utils/std.h"

#include "EComponentType.h"
#include "CComponentPosition.h"
#include "CComponentVelocity.h"
#include "CComponentSprite.h"

class CComponentsCollection
{
public:
	CComponentsCollection();
	~CComponentsCollection();

	void addComponent(EComponentType type);
	void removeComponent(EComponentType type);
	IComponent* getComponent(EComponentType type);

	size_t size();

private:
	int32 _mask;
	map <EComponentType , IComponent*> _components_map;
};
