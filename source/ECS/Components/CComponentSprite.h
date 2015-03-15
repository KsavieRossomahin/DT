#pragma once

#include "IComponent.h"
#include "../Utils/vertexes.h"

class CComponentSprite : public IComponent
{
public:
	CComponentSprite();
	~CComponentSprite();

	CIwGxStream* xyStream();
	CIwGxStream* colStream();

private:
	CIwGxStream* _shared_stream;
	CIwGxStream* _xy_stream;
	CIwGxStream* _col_stream;
};