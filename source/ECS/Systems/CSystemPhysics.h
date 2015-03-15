#pragma once

#include "ISystem.h"
#include "s3eKeyboard.h"

class CSystemPhysics : public ISystem
{
public:
	virtual void process();
	void input(s3eKey key);
};