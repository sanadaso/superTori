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

const int KEY_CODE_LEFT   = 0x01;
const int KEY_CODE_RIGHT  = 0x02;
const int KEY_CODE_UP     = 0x04;
const int KEY_CODE_DOWN   = 0x08;
const int KEY_CODE_SPACE  = 0x10;
const int KEY_CODE_Z      = 0x20;
const int KEY_CODE_ESCAPE = 0x40;

#endif