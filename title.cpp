#include "title.h"
#include <Novice.h>

Title::Title()
{
	Init();
}

void Title::Init()
{
	isTriger = false;
	isExit = false;
	brighten = true;
	alpha = 255;
}

void Title::Update(const char* _keys, const char* _preKeys)
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

	if (_keys[DIK_SPACE] && !_preKeys[DIK_SPACE] && !brighten)
	{
		isTriger = true;
	}

	if (isTriger)
	{
		alpha += 4;
		if (alpha >= 255)
		{
			alpha = 255;
			isExit = true;
		}
	}
}

void Title::Draw()
{


	if (isTriger|| brighten)
	{
		Novice::DrawBox(0, 0, 1280, 720, 0, alpha, kFillModeSolid);
	}
}

