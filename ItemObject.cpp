#include "ItemObject.h"

void ItemObject::set(int x, int y, int speed, bool direction, bool flag)
{
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->direction = direction;

	this->flag = flag;
}

void ItemObject::setFlag(bool flag)
{
	this->flag = flag;
}

bool ItemObject::getFlag()
{
	return this->flag;
}
