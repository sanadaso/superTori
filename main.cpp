#include "DxLib.h"
#include "main.h"
#include "CollisionDetection.h"
#include "KeyInput.h"

// プログラムは WinMain から始まります

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(960, 544, 32); //ウィンドウサイズ変更

	if (DxLib_Init() == -1)        // ＤＸライブラリ初期化処理
	{
		return -1;         // エラーが起きたら直ちに終了
	}

	//画像ロード
	const int TORNEV_GRAPH = LoadGraph("picture/tornev_r.png");
	const int TORNEV_SUPER_GRAPH = LoadGraph("picture/tornev_r_s.png");	const int background_art = LoadGraph("picture/backgroundart.png");
	const int star_graph = LoadGraph("picture/star.png");
	const int tokage_graph = LoadGraph("picture/tokage.png");
	const int chip_0 = LoadGraph("picture/32_0.png");
	const int chip_1 = LoadGraph("picture/32_1.png");
	const int chip_2 = LoadGraph("picture/32_2.png");
	const int chip_3 = LoadGraph("picture/32_3.png");
	const int chip_debug = LoadGraph("picture/debug_flag.png");
	const int game_over = LoadGraph("picture/game_over.png");

	//BGMロード
	int normal_bgm = LoadSoundMem("music/game_maoudamashii_4_field08.mp3");
	int super_BGM = LoadSoundMem("music/bgm_maoudamashii_neorock63.mp3");

	//変数たち
	Tornev tornev;
	tornev.set(150, 300, 5, true, TORNEV_GRAPH, -10, 5, 0, false, false, false);
	Ui ui = { 0,0 };
	ItemObject star;
	star.set(600, 200, 8, true, star_graph, true);
	Enemy tokage;
	tokage.set(900, 300, 7, false, tokage_graph, false, false);
	BGA bg = { 0,0 };

	int super_start_time;
	int super_time;
	int super_max_time = 5000;

	int game_start_time = GetNowCount();
	int game_now_time;
	int now_time = 0;

	//int tokage_time;

	bool super_mode = false;


	//マップチップ
	//int  mapx = GetRand(10);
	//mapx += 10;
	//int maps[5][mapx];

	const int map_max_x = 60;
	const int map_max_y = 17;
	int maps[map_max_y][map_max_x];

	int map_limit_x = map_max_x - GetRand(20);
	int map_limit_y = map_max_y - GetRand(0);

	for (int i = 0; i < map_limit_y; i++) {
		for (int j = 0; j < map_limit_x; j++) {
			maps[i][j] = GetRand(3);
		}
	}

	enum TornevStatus
	{
		Wait,
		Walk
	};

	TornevStatus player_state = Wait;


	//int maps[5][11] =
	//{
	//	{ 0,0,0,0,0,0,0,0,0,0,0 },
	//	{ 0,0,1,1,1,1,1,1,1,0,0 },
	//	{ 0,0,1,2,2,2,2,2,1,0,0 },
	//	{ 0,0,1,1,1,1,2,3,1,0,0 },
	//	{ 0,0,0,0,0,0,0,0,0,0,0 }
	//};

	//描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	bool debug_flag = false;
	int key_old = 0;

	//動かす
	while (CheckHitKey(KEY_INPUT_RETURN) == 0) {

		//時間測る
		now_time = GetNowCount();
		game_now_time =  now_time - game_start_time;

		//キー入力処理
		int key_trg, key_info;
		key_trg = key_info = key_old = 0;

		key_info = KeyInput::HitCheck();

		key_trg = (key_info ^ key_old) & key_info;
		key_old = key_info;

		//トルネフがスーパー状態か否か
		tornev.transformNormal(TORNEV_GRAPH); // 右向きトルネフ画像をロードする変数

		if (super_mode == true) {
			super_time = GetNowCount() - super_start_time;
			if (super_time < 10000) {
				tornev.setSpeed(10);
				tornev.transformSuper(TORNEV_SUPER_GRAPH);
			} else if (super_time >= super_max_time) {
				star.setFlag(true);
				super_mode = false;
				StopSoundMem(super_BGM);
			}
		}

		// トルネフが入力で左右に移動する
		if (key_info & KEY_CODE_RIGHT) { // 右キーが入力されている
			tornev.setDirection(true);
			//debug_flag = true;
			if (tornev.getX() < 710) {
				tornev.moveAdvance();
			} else {
				bg.x -= tornev.getSpeed();
			}
		}
		if (key_info & KEY_CODE_LEFT) { // 左キーが入力されている
			tornev.setDirection(false);
			//debug_flag = false;
			if (tornev.getX() > 150) {
				tornev.moveBackwards();
			} else if (tornev.getX() <= 150 && bg.x <= 0) {
				int nowspeed = tornev.getSpeed()*(-1);
				if (bg.x <= 0 && bg.x > nowspeed) {
					bg.x = 0;
					ui.x = 0;
				} else {
					bg.x += tornev.getSpeed();
				}
			}
		}

		// トルネフジャンプ処理
		tornev.jump(key_trg);

		//スターの動き
		CollisionDetection collisionDetection(tornev, bg);
		if (star.getFlag() == true) {
			if (star.getDirection() == true) {
				star.moveAdvance();
			} else if (star.getDirection() == false) {
				star.moveBackwards();
			}

			if (star.getX() >= 900) {
				star.setDirection(false);
			} else if (star.getX() <= 600) {
				star.setDirection(true);
			}

			if (collisionDetection.itemColision(star) == true) {
				star.setFlag(false);
				super_mode = true;
				super_start_time = GetNowCount();
				//BGM再生
				StopSoundMem(normal_bgm);
				PlaySoundMem(super_BGM, DX_PLAYTYPE_LOOP);
			}
		}

		//敵の動き
		if (tornev.getX() > 450)
			tokage.setFlag(true);
		if (tokage.getFlag() == true)
			tokage.moveBackwards();

		if (tokage.getIsDead() == false && super_mode == false && collisionDetection.enemyColision(tokage) == true) {
			tornev.setIsDead(true); // トルネフ死亡フラグオン
		}
		if (
			(tokage.getIsDead() == false && collisionDetection.tornevAttack(tokage) == true) ||						// トカゲが生きてて、踏んだら
			(tokage.getIsDead() == false && super_mode == true && collisionDetection.enemyColision(tokage) == true) // トカゲが生きてて、スーパーモードで、当たったら
			) {
			tokage.setIsDead(true); // トカゲ死亡フラグオン
		}
		if (tokage.getIsDead() == true) {
			tokage.setY(tokage.getX() + 2000);
		}

		//BGM
		if (CheckSoundMem(normal_bgm) != 1 && super_mode == false) {
			PlaySoundMem(normal_bgm, DX_PLAYTYPE_LOOP);
		}
			
		//描画する
		ClearDrawScreen();
		//DrawGraph(bgx, bgy, backgroundArt, TRUE);
		//マップチップ描画
		int chip_side_length = 32;//正方形チップの縦と幅
		for (int i = 0; i < map_limit_y; i++) {
			for (int j = 0; j < map_limit_x; j++) {
				int chip_name;
				switch (maps[i][j]) {
				case 0:
					chip_name = chip_0;
					break;
				case 1:
					chip_name = chip_1;
					break;
				case 2:
					chip_name = chip_2;
					break;
				case 3:
					chip_name = chip_3;
					break;
				}

				DrawGraph(bg.x + (j*chip_side_length), i*chip_side_length, chip_name, TRUE);
			}
		}

		// 時間表示
		ui.TimeDisplay(game_now_time);

		//トルネフ描画
		if (tornev.getDirection() == true) {
			DrawGraph(tornev.getX(), tornev.getY(), tornev.getGraph(), TRUE);
		} else if (tornev.getDirection() == false) {
			DrawTurnGraph(tornev.getX(), tornev.getY(), tornev.getGraph(), TRUE);
		}

		if (star.getFlag() == true)
			DrawGraph(bg.x + star.getX(), star.getY(), star.getGraph(), TRUE);
		if (tokage.getFlag() == true)
			DrawGraph(bg.x + tokage.getX(), tokage.getY(), tokage.getGraph(), TRUE);

		if (debug_flag == true)
			DrawGraph(ui.x, ui.y, chip_debug, TRUE);

		if (tornev.getIsDead() == true)
			DrawExtendGraph(ui.x+230, ui.y+181, ui.x+730, ui.y+362, game_over, TRUE);

		ScreenFlip();

		// メッセージループに代わる処理をする
		if (ProcessMessage() == -1)	break;        // エラーが起きたらループを抜ける

	}

	DxLib_End(); // DXライブラリ使用の終了処理

	return 0;    // ソフトの終了
}
