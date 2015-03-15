#pragma once

#include "IComponent.h"
#include "IwGeom.h"

class CComponentVelocity : public IComponent
{
public:
	CComponentVelocity();

	void setDir(CIwFVec2 val);
	void setDir(float x, float y);
	void setDirX(float val);
	void setDirY(float val);
	CIwFVec2 dir();
	float dirX();
	float dirY();
	void setSpeed(float val);
	float speed();

private:
	CIwFVec2 _dir;
	float _speed;
};