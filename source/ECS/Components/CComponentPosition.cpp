#include "CComponentPosition.h"

CComponentPosition::CComponentPosition() : _pos(CIwFVec2::g_Zero)
{
}

void CComponentPosition::setPos(CIwFVec2 val)
{
	_pos = val;
}

void CComponentPosition::setPosX(float val)
{
	_pos.x = val;
}

void CComponentPosition::setPosY(float val)
{
	_pos.y = val;
}

CIwFVec2 CComponentPosition::pos()
{
	return _pos;
}

float CComponentPosition::posX()
{
	return _pos.x;
}

float CComponentPosition::posY()
{
	return _pos.y;
}