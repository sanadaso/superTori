#pragma once
#include "IngameObject.h"

class Enemy :
    public IngameObject
{
	bool flag;
	bool is_dead;
	int graph;

public:
	void set(int x, int y, int speed, bool direction, bool flag, bool is_dead, int graph);

	void setFlag(int flag);
	void setIsDead(bool is_dead);
	void setGraph(int graph);

	bool getFlag();
	bool getIsDead();
	int getGraph();
};
