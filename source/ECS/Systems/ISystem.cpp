#pragma once

#include "ISystem.h"

ISystem::~ISystem()
{
}

void ISystem::init(vector <CEntity*>& entities)
{
	_entities = &entities;
}
