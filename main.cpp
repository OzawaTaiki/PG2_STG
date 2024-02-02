#include <Novice.h>

#include "title.h"
#include "inGame.h"
#include <Vector2.h>
#include <math.h>

const char kWindowTitle[] = "LC1A_07_オザワ_タイキ_PG2_STG";

enum Scene
{
	TITLE,
	GAME
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	int currentScene = TITLE;

	Title* title = new Title;
	title->Init();

	InGame* ingame = nullptr;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (currentScene)
		{
		case TITLE:

			title->Update(keys, preKeys);

			if (title->GetIsExit())
			{
				currentScene = GAME;
				ingame = new InGame;

				delete title;
			}

			break;
		case GAME:

			ingame->Update(keys);
			if (ingame->GetIsExit())
			{
				currentScene = TITLE;
				title = new Title;

				delete ingame;
			}

			break;
		default:
			break;
		}



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (currentScene)
		{
		case TITLE:
			title->Draw();
			break;
		case GAME:
			ingame->Draw();
			break;
		default:
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}


/// objとobjの円の衝突判定
