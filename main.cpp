#include "DxLib.h"
#include "main.h"
#include "GameManager.h"

// プログラムは WinMain から始まります

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(960, 544, 32); // ウィンドウサイズ変更

	if (DxLib_Init() == -1)     // DXライブラリ初期化処理
	{
		return -1;              // エラーが起きたら直ちに終了
	}

	// ゲームマネージャー
	GameManager * game_manager = new GameManager;
	game_manager->run();

	DxLib_End(); // DXライブラリ使用の終了処理

	return 0;    // ソフトの終了
}
