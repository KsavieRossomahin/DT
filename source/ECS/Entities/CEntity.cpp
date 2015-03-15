#include "CEntity.h"

CEntity::CEntity()
{
	printf("Entity created: 0x%X\n", this);
}

CEntity::~CEntity()
{
	printf("Entity destroyed: 0x%X\n", this);
}

CComponentsCollection* CEntity::collection()
{
	return &_collection;
}