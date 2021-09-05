#pragma once
#include "IngameObject.h"

class Enemy :
    public IngameObject
{
	bool flag;
	bool is_dead;

public:
	void set(int x, int y, int speed, bool direction, int graph, bool flag, bool is_dead);

	void setFlag(int flag);
	void setIsDead(bool is_dead);

	bool getFlag();
	bool getIsDead();
};
