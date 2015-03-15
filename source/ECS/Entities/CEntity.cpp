#include "CEntity.h"

CEntity::CEntity()
{
	int a = 0;
}

CComponentsCollection* CEntity::collection()
{
	return &_collection;
}