#include "KeyInput.h"

int KeyInput::HitCheck()
{
	int key_info = 0;

	if (CheckHitKey(KEY_INPUT_RIGHT)) { key_info |= KEY_CODE_RIGHT; }

	if (CheckHitKey(KEY_INPUT_LEFT)) { key_info |= KEY_CODE_LEFT; }

	if (CheckHitKey(KEY_INPUT_UP)) { key_info |= KEY_CODE_UP; }

	if (CheckHitKey(KEY_INPUT_DOWN)) { key_info |= KEY_CODE_DOWN; }

	if (CheckHitKey(KEY_INPUT_SPACE)) { key_info |= KEY_CODE_SPACE; }

	if (CheckHitKey(KEY_INPUT_Z)) { key_info |= KEY_CODE_Z; }

	if (CheckHitKey(KEY_INPUT_ESCAPE)) { key_info |= KEY_CODE_ESCAPE; }

	return key_info;
}
