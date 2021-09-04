﻿#ifndef __MAIN_H__
#define __MAIN_H__
#include "IngameObject.h"

#pragma once

struct Map {
	const int max_x;
	const int max_y;
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
