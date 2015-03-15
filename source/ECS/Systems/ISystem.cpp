#pragma once

#include "ISystem.h"

vector <CEntity*>* ISystem::_entities = NULL;

ISystem::~ISystem()
{
}

void ISystem::init(vector <CEntity*>& entities)
{
	_entities = &entities;
}
