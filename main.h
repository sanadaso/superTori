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

struct Tornev
{
	int x; //トルネフのx,y座標
	int y;
	int y_prev;
	int y_temp;
	int jump_y;
	int speed;
	bool direction;
	bool jump_flag_1;
	bool jump_flag_2;
};

struct Item
{
	int x;
	int y;
	int speed;
	bool direction;
	bool flag;
};

struct Enemy
{
	int x;
	int y;
	int speed;
	bool direction;
	bool flag;
	bool dead;
};

struct BGA
{
	int x;
	int y;
};
#endif