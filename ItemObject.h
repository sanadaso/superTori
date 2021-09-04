#pragma once
#include "IngameObject.h"

class ItemObject :
    public IngameObject
{
	private:
		bool flag;
	public:
		void ItemObject::set(int x, int y, int speed, bool direction, bool flag);
		void ItemObject::setFlag(bool flag);
		bool ItemObject::getFlag();
};
