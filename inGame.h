#pragma once

#include <Vector2.h>

const int kMaxEnemy = 3;

class Player;
class Enemy;

class InGame
{
public:
	InGame();

	void Init();
	void Update(const char* _keys);
	void Draw();

	bool GetIsExit() { return isExit; };


private:
	bool Collision(const Vector2& _pos1, const Vector2& _size1, const Vector2& _pos2, const Vector2& _size2);

	Player* player = nullptr;
	Enemy* enemy[kMaxEnemy];

	bool isExit = false;
	bool isBlackout = false;
	bool brighten = true;

	int alpha = 255;
};