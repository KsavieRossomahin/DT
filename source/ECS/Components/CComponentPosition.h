#pragma once

#include "IComponent.h"
#include "IwGeom.h"

class CComponentPosition : public IComponent
{
public:
	CComponentPosition();

	void setPos(CIwFVec2 val);
	void setPosX(float val);
	void setPosY(float val);
	CIwFVec2 pos();
	float posX();
	float posY();

private:
	CIwFVec2 _pos;
};