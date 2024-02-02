#include "title.h"
#include <Novice.h>

Title::Title()
{
	Init();

	titleTextGH = Novice::LoadTexture("./images/titleText.png");
	guideTextGH = Novice::LoadTexture("./images/pressText.png");
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
	Novice::DrawSprite(480, 200, titleTextGH, 1, 1, 0, WHITE);
	Novice::DrawSprite(448, 400, guideTextGH, 1, 1, 0, WHITE);

	if (isTriger || brighten)
	{
		Novice::DrawBox(0, 0, 1280, 720, 0, alpha, kFillModeSolid);
	}
}

