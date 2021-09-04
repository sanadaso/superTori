#ifndef __MAIN_H__
#define __MAIN_H__
#pragma once

struct UI
{
	int x;
	int y;
};

struct Map {
	const int max_x;
	const int max_y;
};

class IngameObject
{
public:
	int x;
	int y;
	int speed;
	bool direction;

	void IngameObject::set(int x, int y, int speed, bool direction)
	{
		this->x = x;
		this->y = y;
		this->speed = speed;
		this->direction = direction;
	}
};

class Tornev : public IngameObject
{
public:
	int y_prev;
	int y_temp;
	int jump_y;
	bool jump_flag_1;
	bool jump_flag_2;
	bool is_dead;

	void Tornev::set(int x, int y, int speed, bool direction, int y_prev, int y_temp, int jump_y, bool jump_flag_1, bool jump_flag_2, bool is_dead)
	{
		this->x = x;
		this->y = y;
		this->speed = speed;
		this->direction = direction;

		this->y_prev = y_prev;
		this->y_temp = y_temp;
		this->jump_y = jump_y;
		this->jump_flag_1 = jump_flag_1;
		this->jump_flag_2 = jump_flag_2;
		this->is_dead = is_dead;
	}

	void Tornev::setSpeed(int speed)
	{
		this->speed = speed;
	}
};

class Item
{
public:
	int x;
	int y;
	int speed;
	bool direction;
	bool flag;
};

class Enemy
{
public:
	int x;
	int y;
	int speed;
	bool direction;
	bool flag;
	bool is_dead;
	int graph;
};

struct BGA
{
	int x;
	int y;
};

const int KEY_CODE_LEFT   = 0x01;
const int KEY_CODE_RIGHT  = 0x02;
const int KEY_CODE_UP     = 0x04;
const int KEY_CODE_DOWN   = 0x08;
const int KEY_CODE_SPACE  = 0x10;
const int KEY_CODE_Z      = 0x20;
const int KEY_CODE_ESCAPE = 0x40;

#endif