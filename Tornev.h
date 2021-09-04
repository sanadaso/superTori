#pragma once
#include "KeyInput.h"
#include "IngameObject.h"

class Tornev :
    public IngameObject
{
private:
		int y_prev;
		int y_temp;
		int jump_y;
		bool jump_flag_1;
		bool jump_flag_2;
		bool is_dead;

public:
	void Tornev::set(int x, int y, int speed, bool direction, int y_prev, int y_temp, int jump_y, bool jump_flag_1, bool jump_flag_2, bool is_dead);

	void Tornev::setYPrev(int y_prev);
	void Tornev::setYTemp(int y_temp);
	void Tornev::setJumpY(int jump_y);
	void Tornev::setJumpFlag1(int jump_flag_1);
	void Tornev::setJumpFlag2(int jump_flag_2);
	void Tornev::setIsDead(int is_dead);

	int Tornev::getYPrev();
	int Tornev::getYTemp();
	int Tornev::getJumpY();
	bool Tornev::getJumpFlag1();
	bool Tornev::getJumpFlag2();
	bool Tornev::getIsDead();

	void Tornev::jump(int key_trg);
};
