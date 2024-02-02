#include "inGame.h"

#include "player.h"
#include "enemy.h"
#include <Novice.h>

InGame::InGame()
{
	Init();
}

void InGame::Init()
{
	isExit = false;
	isBlackout = false;
	brighten = true;
	alpha = 255;

	player = new Player;
	player->Init();

	enemy[0] = new Enemy({ 100,100 }, 1);
	enemy[1] = new Enemy({ 500,200 }, 1);
	enemy[2] = new Enemy({ 300,300 }, -1);
}

void InGame::Update(const char* _keys)
{
	if (brighten)
	{
		alpha -= 4;
		if (alpha <= 0)
		{
			brighten = false;
			alpha = 0;
		}
		return;
	}

	for (int i = 0; i < kMaxEnemy; i++)
		enemy[i]->Update();
	player->Update(_keys);

	for (int i = 0; i < kMaxEnemy; i++)
	{
		Vector2 temp[4];
		player->getPosSize(temp[0], temp[1]);
		enemy[i]->getPosSize(temp[2], temp[3]);
		if (Collision(temp[0], temp[1], temp[2], temp[3]))
			player->Dead();

		for (int j = 0; j < player->GetBulletSize(); j++)
		{
			player->getBulletPosSize(j, temp[0], temp[1]);

			if (Collision(temp[0], temp[1], temp[2], temp[3]))
			{
				enemy[i]->Dead();
			}
		}
	}

	if (!player->GetIsAlive())	
		isBlackout = true;	
	else
	{
		isBlackout = true;
		for (int i = 0; i < kMaxEnemy; i++)
		{
			if (enemy[i]->GetIsAlive())
				isBlackout = false;
		}
	}

	if (isBlackout)
	{
		alpha += 4;
		if (alpha >= 255)
		{
			alpha = 255;
			isExit = true;
		}
	}

}

void InGame::Draw()
{
	for (int i = 0; i < kMaxEnemy; i++)
		enemy[i]->Draw();
	player->Draw();

	if(isBlackout|| brighten)
		Novice::DrawBox(0, 0, 1280, 720, 0, alpha, kFillModeSolid);

}

bool InGame::Collision(const Vector2& _pos1, const Vector2& _size1, const Vector2& _pos2, const Vector2& _size2)
{
	Vector2 sub;
	sub.x = _pos1.x - _pos2.x;
	sub.y = _pos1.y - _pos2.y;

	float length = _size1.x + _size2.x;

	if (sqrtf(sub.x * sub.x + sub.y * sub.y) <= length)
		return true;

	return false;
}

