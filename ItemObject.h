#pragma once
#include "IngameObject.h"

class ItemObject :
    public IngameObject
{
	private:
		bool flag;
	public:
		void set(int x, int y, int speed, bool direction, int graph, bool flag);
		void setFlag(bool flag);
		bool getFlag();
};
