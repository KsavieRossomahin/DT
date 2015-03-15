#pragma once

#include "../Components/CComponentsCollection.h"

class CEntity
{
public:
	CEntity();
	CComponentsCollection* collection();

private:
	CComponentsCollection _collection;
};