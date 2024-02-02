#pragma once
#include "object.h"
#include <vector>

class Bullet;

class Player :public Object
{
public:
	Player();

	void Init();
	void Update(const char* _keys);
	void Draw();

	size_t GetBulletSize() { return bullet.size(); };	
	void getPosSize(Vector2& _pos, Vector2& _size) { _pos = pos; _size = size; };
	void getBulletPosSize(int _num, Vector2& _pos, Vector2& _size);
	void Dead() { isAlive = false; };
	bool GetIsAlive() { return isAlive; };

private:
	const int kMaxBulletCnt = 10;

	bool isAlive = true;
	bool isShot = false;
	bool canShot = true;

	const int kShotCoolTime = 15;
	int cntUp = 0;

	std::vector<Bullet*> bullet;

	void Move(const char* _keys);
	void Shot(const char* _keys);

};