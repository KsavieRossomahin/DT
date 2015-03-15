#pragma once

#include "../Entities/CEntity.h"

class ISystem
{
public:
	virtual ~ISystem();
	void init(vector <CEntity*>& entities);
	virtual void process() = 0;

protected:
	vector <CEntity*>* _entities;
};