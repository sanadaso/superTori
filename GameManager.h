// シーンを表す定数.
#define SCENE_ID_TITLE 0
#define SCENE_ID_GAME 1

class GameManager
{
public:
    // 今がどのシーンか示す値.
    int now_scene_code;

    GameManager();

    // ゲームの実処理を実行する.
    void GameManager::run();
};
