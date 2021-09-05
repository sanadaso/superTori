#include "ItemObject.h"

void ItemObject::set(int x, int y, int speed, bool direction, int graph, bool flag)
{
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->direction = direction;
	this->graph = graph;

	this->flag = flag;
}



/*
* setter
*/
void ItemObject::setFlag(bool flag)
{
	this->flag = flag;
}



/*
* getter
*/
bool ItemObject::getFlag()
{
	return this->flag;
}
