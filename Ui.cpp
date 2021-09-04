#include "Ui.h"

void Ui::TimeDisplay(int game_now_time)
{
	int time = game_now_time / 1000; // game_now_time (ƒQ[ƒ€n‚Ü‚Á‚Ä‚©‚ç‚ÌŠÔ)
	for (int i = 0; i < 3; i++)
	{
		int n = time % 10;
		int number_name;
		switch (n) {
		case 0:
			number_name = number_0;
			break;
		case 1:
			number_name = number_1;
			break;
		case 2:
			number_name = number_2;
			break;
		case 3:
			number_name = number_3;
			break;
		case 4:
			number_name = number_4;
			break;
		case 5:
			number_name = number_5;
			break;
		case 6:
			number_name = number_6;
			break;
		case 7:
			number_name = number_7;
			break;
		case 8:
			number_name = number_8;
			break;
		case 9:
			number_name = number_9;
			break;
		default:
			number_name = number_0;
			break;
		}
		DrawGraph(x + 960 - (i * 100 + 100), y, number_name, TRUE);

		time /= 10;
	}
}
