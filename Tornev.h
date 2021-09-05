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
		int mode;

public:
	void set(int x, int y, int speed, bool direction, int tornev_graph, int y_prev, int y_temp, int jump_y, bool jump_flag_1, bool jump_flag_2, bool is_dead);

	void setYPrev(int y_prev);
	void setYTemp(int y_temp);
	void setJumpY(int jump_y);
	void setJumpFlag1(int jump_flag_1);
	void setJumpFlag2(int jump_flag_2);
	void setIsDead(int is_dead);

	int getYPrev();
	int getYTemp();
	int getJumpY();
	bool getJumpFlag1();
	bool getJumpFlag2();
	bool getIsDead();
	int getMode();

	void jump(int key_trg);
	void transformSuper(int tornev_super_graph);
	void transformNormal(int tornev_graph);
};
