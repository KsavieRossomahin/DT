#pragma once

#include "../Components/CComponentsCollection.h"

class CEntity
{
public:
	CEntity();
	~CEntity();
	CComponentsCollection* collection();

private:
	CComponentsCollection _collection;
};