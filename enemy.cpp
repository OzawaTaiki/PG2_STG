#include "enemy.h"
#include <Novice.h>

Enemy::Enemy(const Vector2& _pos, float _dir)
{
	Init(_pos, _dir);
}

void Enemy::Init(const Vector2& _pos, float _dir)
{
	pos = _pos;
	size = { 32,32 };
	spd = 3;
	velocity.x = _dir * spd;
	velocity.y = 0;

	color = RED;
}

void Enemy::Update()
{
	Respawn();

	if (!isAlive)
		return;
	Move();
}

void Enemy::Draw()
{
	if (!isAlive)
		return;
	Novice::DrawEllipse(int(pos.x), int(pos.y), int(size.x), int(size.y), 0, color, kFillModeSolid);
}

void Enemy::Move()
{
	pos.x += velocity.x;

	if (pos.x < size.x)
	{
		pos.x = size.x;
		velocity.x *= -1;
	}
	else if (pos.x > 1280 - size.x)
	{
		pos.x = 1280 - size.x;
		velocity.x *= -1;
	}
}

void Enemy::Respawn()
{
	if (isAlive)
		return;

	cntUp++;
	if (cntUp % kRespawnTime == 0)
		isAlive = true;

}
