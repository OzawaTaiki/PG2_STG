#pragma once
#include "object.h"

class Bullet : public Object
{
public:

	static int bulletCnt;

	Bullet(const Vector2& _pos);

	void Update();
	void Draw();

	bool GetIsInScreen() { return IsInScreen; };
	Vector2 GetPos() { return pos; };
	Vector2 GetSize() { return size; };

private:
	bool IsInScreen = true;
};