// �V�[����\���萔.
#define SCENE_ID_TITLE 0
#define SCENE_ID_GAME 1

class GameManager
{
public:
    // �����ǂ̃V�[���������l.
    int now_scene_code;

    GameManager();

    // �Q�[���̎����������s����.
    void GameManager::run();
};
