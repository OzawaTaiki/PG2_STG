#pragma once
#include "object.h"

class Enemy : public Object
{
public:
	Enemy(const Vector2& _pos, float _dir);

	void Init(const Vector2& _pos, float _dir);
	void Update();
	void Draw();

	void getPosSize(Vector2& _pos, Vector2& _size) { _pos = pos; _size = size; };
	void Dead() { isAlive = false; };
	bool GetIsAlive() { return isAlive; };

private:
	bool isAlive = true;

	const int kRespawnTime = 120;
	int cntUp = 0;

	void Move();
	void Respawn();

};