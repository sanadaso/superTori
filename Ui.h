#include "DxLib.h"

#pragma once
class Ui
{
public:
	int x;
	int y;

	const int number_0 = LoadGraph("picture/number_0.png");
	const int number_1 = LoadGraph("picture/number_1.png");
	const int number_2 = LoadGraph("picture/number_2.png");
	const int number_3 = LoadGraph("picture/number_3.png");
	const int number_4 = LoadGraph("picture/number_4.png");
	const int number_5 = LoadGraph("picture/number_5.png");
	const int number_6 = LoadGraph("picture/number_6.png");
	const int number_7 = LoadGraph("picture/number_7.png");
	const int number_8 = LoadGraph("picture/number_8.png");
	const int number_9 = LoadGraph("picture/number_9.png");

	void TimeDisplay(int game_now_time);
};
