#include "player.h"
#include <Novice.h>
#include "bullet.h"

Player::Player()
{
	Init();
}

void Player::Init()
{
	pos = { 640,400 };
	size = { 20,20 };
	velocity = { 0,0 };
	spd = 5;

	bullet.clear();
}

void Player::Update(const char* _keys)
{
	if (!isAlive)
		return;

	Move(_keys);
	Shot(_keys);

	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i]->Update();
		if (!bullet[i]->GetIsInScreen())
			bullet.erase(bullet.begin() + i);
	}
}

void Player::Draw()
{
	if (!isAlive)
		return;

	for (int i = 0; i < bullet.size(); i++)
		bullet[i]->Draw();
	Novice::DrawEllipse(int(pos.x), int(pos.y), int(size.x), int(size.y), 0, color, kFillModeSolid);
}

void Player::getBulletPosSize(int _num, Vector2& _pos, Vector2& _size)
{
	_pos = bullet[_num]->GetPos();
	_size = bullet[_num]->GetSize();
}

void Player::Move(const char* _keys)
{
	if (_keys[DIK_A])		pos.x += -spd;
	if (_keys[DIK_S])		pos.y += spd;
	if (_keys[DIK_W])		pos.y += -spd;
	if (_keys[DIK_D])		pos.x += spd;
}

void Player::Shot(const char* _keys)
{
	if (_keys[DIK_SPACE]  && canShot)
	{
		if (Bullet::bulletCnt < kMaxBulletCnt)
		{
			bullet.push_back(new Bullet(pos));
			isShot = true;
			canShot = false;
		}
	}

	if (isShot)
	{
		cntUp++;
		if (cntUp % kShotCoolTime == 0)
		{
			cntUp = 0;
			canShot = true;
			isShot = false;
		}
	}
}
