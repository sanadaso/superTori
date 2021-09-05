#include "Tornev.h"

void Tornev::jump(int key_trg)
{
	if (key_trg & KEY_CODE_SPACE && this->getY() >= 300) { // ジャンプボタンを押す
		this->jump_flag_1 = true;
		this->y_prev = this->getY();
		this->setY(this->getY() - 15);
	} else if (this->getJumpFlag1() == true) { // ジャンプ中のY方向の動き処理
		this->y_temp = this->getY();
		this->setY(this->getY() + (this->getY() - this->y_prev) + 1);
		this->y_prev = this->y_temp;

		if (this->getY() >= 300)
			this->jump_flag_1 = false;
	}
}



void Tornev::transformSuper(int tornev_super_graph)
{
	this->graph = tornev_super_graph;
	this->mode = TornevMode::Super;
}



void Tornev::transformNormal(int tornev_graph)
{
	this->graph = tornev_graph;
	this->mode = TornevMode::Normal;
}



/*
* setter
*/
void Tornev::set(int x, int y, int speed, bool direction, int tornev_graph, int y_prev, int y_temp, int jump_y, bool jump_flag_1, bool jump_flag_2, bool is_dead)
{
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->direction = direction;
	this->graph = tornev_graph;

	this->y_prev = y_prev;
	this->y_temp = y_temp;
	this->jump_y = jump_y;
	this->jump_flag_1 = jump_flag_1;
	this->jump_flag_2 = jump_flag_2;
	this->is_dead = is_dead;
}



void Tornev::setYPrev(int y_prev)
{
	this->y_prev = y_prev;
}



void Tornev::setYTemp(int y_temp)
{
	this->y_temp = jump_flag_1;
}



void Tornev::setJumpY(int jump_y)
{
	this->jump_y = jump_y;
}



void Tornev::setJumpFlag1(int jump_flag_1)
{
	this->jump_flag_1 = jump_flag_1;
}



void Tornev::setJumpFlag2(int jump_flag_2)
{
	this->jump_flag_2 = jump_flag_2;
}



/*
* getter
*/
int Tornev::getYPrev()
{
	return this->y_prev;
}



int Tornev::getYTemp()
{
	return this->y_temp;
}



int Tornev::getJumpY()
{
	return this->jump_y;
}



bool Tornev::getJumpFlag1()
{
	return this->jump_flag_1;
}



bool Tornev::getJumpFlag2()
{
	return this->jump_flag_2;
}



int Tornev::getMode()
{
	return this->mode;
}
