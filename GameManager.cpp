#include "GameManager.h"
#include "DxLib.h"
#include "main.h"
#include "CollisionDetection.h"
#include "KeyInput.h"



// �R���X�g���N�^�A������ʂ��^�C�g���ɃZ�b�g����.
GameManager::GameManager() {
    now_scene_code = SCENE_ID_TITLE;
}



// �Q�[���̎����������s����.
void GameManager::run() {

	//�摜���[�h
	const int TORNEV_GRAPH = LoadGraph("picture/tornev_r.png");
	const int TORNEV_SUPER_GRAPH = LoadGraph("picture/tornev_r_s.png");
	const int background_art = LoadGraph("picture/backgroundart.png");
	const int star_graph = LoadGraph("picture/star.png");
	const int tokage_graph = LoadGraph("picture/tokage.png");
	const int chip_0 = LoadGraph("picture/32_0.png");
	const int chip_1 = LoadGraph("picture/32_1.png");
	const int chip_2 = LoadGraph("picture/32_2.png");
	const int chip_3 = LoadGraph("picture/32_3.png");
	const int chip_debug = LoadGraph("picture/debug_flag.png");
	const int game_over = LoadGraph("picture/game_over.png");
	const int text_start = LoadGraph("picture/start.png");

	//BGM���[�h
	int normal_bgm = LoadBGM("music/game_maoudamashii_4_field08.mp3");
	int super_BGM = LoadBGM("music/bgm_maoudamashii_neorock63.mp3");
	int se_system_49 = LoadBGM("music/se_maoudamashii_system49.mp3");
	
	//�ϐ�����
	Tornev tornev;
	tornev.set(150, 300, 5, true, TORNEV_GRAPH, -10, 5, 0, false, false, false);
	Ui ui = { 0,0 };
	ItemObject star;
	star.set(600, 200, 8, true, star_graph, true);
	Lizard tokage;
	tokage.set(900, 300, 7, false, tokage_graph, false, false);
	BGA bg = { 0,0 };

	int super_start_time;
	int super_time;
	int super_max_time = 5000;

	int game_start_time = GetNowCount();
	int game_now_time;
	int now_time = 0;

	tornev.transformNormal(TORNEV_GRAPH);

	//�}�b�v�`�b�v
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

	//int maps[5][11] =
	//{
	//	{ 0,0,0,0,0,0,0,0,0,0,0 },
	//	{ 0,0,1,1,1,1,1,1,1,0,0 },
	//	{ 0,0,1,2,2,2,2,2,1,0,0 },
	//	{ 0,0,1,1,1,1,2,3,1,0,0 },
	//	{ 0,0,0,0,0,0,0,0,0,0,0 }
	//};

	//�`���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	bool debug_flag = false;
	int key_old = 0;

    //���C�����[�v
    while (CheckHitKey(KEY_INPUT_RETURN) == 0) {

		//���ԑ���
		now_time = GetNowCount();
		game_now_time = now_time - game_start_time;

		//�L�[���͏���
		int key_trg, key_info;
		key_trg = key_info = key_old = 0;

		key_info = KeyInput::HitCheck();

		key_trg = (key_info ^ key_old) & key_info;
		key_old = key_info;

		// ��ʂ̃N���A
		ClearDrawScreen();

        // �V�[���ɉ������������s��.
        switch (now_scene_code) {
        
            case SCENE_ID_TITLE: {
                // �^�C�g�����̏���,���͂�҂��ăQ�[����ʂɑJ�ڂ���B
				DrawExtendGraph(ui.x + 230, ui.y + 181, ui.x + 730, ui.y + 362, text_start, TRUE);

				if (CheckHitKey(KEY_INPUT_SPACE) == 1) {
					PlaySoundMem(se_system_49, DX_PLAYTYPE_NORMAL);
					now_scene_code = SCENE_ID_GAME;

				}

				ScreenFlip();

				break;
            }
        

            case SCENE_ID_GAME: {
                // �Q�[�����̏���,�L�����N�^�[�𓮂������肷��.

				//�g���l�t���X�[�p�[��Ԃ��ۂ�
				if (tornev.getMode() == TornevMode::Super) {
					super_time = GetNowCount() - super_start_time;
					if (super_time < 10000) {
						tornev.setSpeed(10);
						tornev.transformSuper(TORNEV_SUPER_GRAPH);
					}
					else if (super_time >= super_max_time) {
						star.setFlag(true);
						tornev.transformNormal(TORNEV_GRAPH);
						StopSoundMem(super_BGM);
					}
				}

				// �g���l�t�����͂ō��E�Ɉړ�����
				if (key_info & KEY_CODE_RIGHT) { // �E�L�[�����͂���Ă���
					tornev.setDirection(true);
					//debug_flag = true;
					if (tornev.getX() < 710) {
						tornev.moveAdvance();
					}
					else {
						bg.x -= tornev.getSpeed();
					}
				}
				if (key_info & KEY_CODE_LEFT) { // ���L�[�����͂���Ă���
					tornev.setDirection(false);
					//debug_flag = false;
					if (tornev.getX() > 150) {
						tornev.moveBackwards();
					}
					else if (tornev.getX() <= 150 && bg.x <= 0) {
						int nowspeed = tornev.getSpeed() * (-1);
						if (bg.x <= 0 && bg.x > nowspeed) {
							bg.x = 0;
							ui.x = 0;
						}
						else {
							bg.x += tornev.getSpeed();
						}
					}
				}

				// �g���l�t�W�����v����
				tornev.jump(key_trg);

				//�X�^�[�̓���
				CollisionDetection collisionDetection(tornev, bg);
				if (star.getFlag() == true) {
					if (star.getDirection() == true) {
						star.moveAdvance();
					}
					else if (star.getDirection() == false) {
						star.moveBackwards();
					}

					if (star.getX() >= 900) {
						star.setDirection(false);
					}
					else if (star.getX() <= 600) {
						star.setDirection(true);
					}

					if (collisionDetection.itemColision(star) == true) {
						star.setFlag(false);
						tornev.transformSuper(TORNEV_SUPER_GRAPH);
						super_start_time = GetNowCount();
						//BGM�Đ�
						StopSoundMem(normal_bgm);
						PlaySoundMem(super_BGM, DX_PLAYTYPE_LOOP);
					}
				}

				//�G�̓���
				tokage.Appear(tornev.getX(), 450);
				if (tokage.getFlag() == true)
					tokage.moveBackwards();

				if (tokage.getIsDead() == false && tornev.getMode() == false && collisionDetection.enemyColision(tokage) == true) {
					tornev.die(); // �g���l�t���S�t���O�I��
				}
				if (
					(tokage.getIsDead() == false && collisionDetection.tornevAttack(tokage) == true) ||						// �g�J�Q�������ĂāA���񂾂�
					(tokage.getIsDead() == false && tornev.getMode() == true && collisionDetection.enemyColision(tokage) == true) // �g�J�Q�������ĂāA�X�[�p�[���[�h�ŁA����������
					) {
					tokage.die(); // �g�J�Q���S�t���O�I��
				}
				if (tokage.getIsDead() == true) {
					tokage.setY(tokage.getX() + 2000);
				}

				//BGM
				if (CheckSoundMem(normal_bgm) != 1 && tornev.getMode() == false) {
					PlaySoundMem(normal_bgm, DX_PLAYTYPE_LOOP);
				}

				//�`�悷��
				//DrawGraph(bgx, bgy, backgroundArt, TRUE);
				//�}�b�v�`�b�v�`��
				int chip_side_length = 32;//�����`�`�b�v�̏c�ƕ�
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

						DrawGraph(bg.x + (j * chip_side_length), i * chip_side_length, chip_name, TRUE);
					}
				}

				// ���ԕ\��
				ui.TimeDisplay(game_now_time);

				//�g���l�t�`��
				if (tornev.getDirection() == true) {
					DrawGraph(tornev.getX(), tornev.getY(), tornev.getGraph(), TRUE);
				}
				else if (tornev.getDirection() == false) {
					DrawTurnGraph(tornev.getX(), tornev.getY(), tornev.getGraph(), TRUE);
				}

				if (star.getFlag() == true)
					DrawGraph(bg.x + star.getX(), star.getY(), star.getGraph(), TRUE);
				if (tokage.getFlag() == true)
					DrawGraph(bg.x + tokage.getX(), tokage.getY(), tokage.getGraph(), TRUE);

				if (debug_flag == true)
					DrawGraph(ui.x, ui.y, chip_debug, TRUE);

				if (tornev.getIsDead() == true)
					DrawExtendGraph(ui.x + 230, ui.y + 181, ui.x + 730, ui.y + 362, game_over, TRUE);

				ScreenFlip();

				// ���b�Z�[�W���[�v�ɑ��鏈��������
				if (ProcessMessage() == -1)	break;        // �G���[���N�����烋�[�v�𔲂���        

                break;
            }

			// ���b�Z�[�W���[�v�ɑ��鏈��������
			if (ProcessMessage() == -1)	break;        // �G���[���N�����烋�[�v�𔲂���        
        }
    }
};
