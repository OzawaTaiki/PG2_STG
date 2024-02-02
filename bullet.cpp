#include "bullet.h"
#include <Novice.h>

int Bullet::bulletCnt = 0;

Bullet::Bullet(const Vector2& _pos)
{
	pos = _pos;
	size = {10,10 };
	velocity = { 0,7 };

	color = BLUE;

	IsInScreen = true;

	bulletCnt++;
}


void Bullet::Update()
{
	pos.y -= velocity.y;

	if (pos.y < -30)
	{
		IsInScreen = false;
		bulletCnt--;
	}
}

void Bullet::Draw()
{
	Novice::DrawEllipse(int(pos.x), int(pos.y), int(size.x), int(size.y), 0, color, kFillModeSolid);
}
