#include "CComponentVelocity.h"

CComponentVelocity::CComponentVelocity() : _dir(CIwFVec2::g_Zero), _speed(0)
{
}

void CComponentVelocity::setDir(CIwFVec2 val)
{
	_dir = val;
}

void CComponentVelocity::setDir(float x, float y)
{
	_dir.x = x;
	_dir.y = y;
}

void CComponentVelocity::setDirX(float val)
{
	_dir.x = val;
}

void CComponentVelocity::setDirY(float val)
{
	_dir.y = val;
}

CIwFVec2 CComponentVelocity::dir()
{
	return _dir;
}

float CComponentVelocity::dirX()
{
	return _dir.x;
}

float CComponentVelocity::dirY()
{
	return _dir.y;
}

void CComponentVelocity::setSpeed(float val)
{
	_speed = val;
}

float CComponentVelocity::speed()
{
	return _speed;
}