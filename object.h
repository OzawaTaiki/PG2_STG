#pragma once
#include <Vector2.h>

class Object
{
protected:
	Vector2 pos;
	Vector2 size;
	Vector2 velocity;
	float spd;

	unsigned int color = 0xffffffff;

};