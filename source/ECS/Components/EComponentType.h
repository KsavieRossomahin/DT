#pragma once

enum EComponentType
{
	ECT_NONE = 0,
	ECT_POSITION = 1 << 0,
	ECT_VELOCITY = 1 << 1,
	ECT_SPRITE = 1 << 2,
};