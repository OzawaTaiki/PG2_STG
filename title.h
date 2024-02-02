#pragma once

class Title
{
public:

	Title();

	void Init();
	void Update(const char* _keys, const char* _preKeys);
	void Draw();

	bool GetIsExit() { return isExit; };

private:

	bool isTriger = false;
	bool isExit = false;
	bool brighten = true;
	
	int alpha = 255;
	int titleTextGH;
	int guideTextGH;
};