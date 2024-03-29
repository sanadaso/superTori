#include "IngameObject.h"

/*
* オブジェクトが前進する
*/
void IngameObject::moveAdvance()
{
	this->setX(this->x + this->speed);
}



/*
* オブジェクトが後進する
*/
void IngameObject::moveBackwards()
{
	this->setX(this->x - this->speed);
}



void IngameObject::die()
{
	this->setIsDead(true);
}



/*
* setter
*/
void IngameObject::set(int x, int y, int speed, bool direction)
{
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->direction = direction;
}



void IngameObject::setX(int x)
{
	this->x = x;
}



void IngameObject::setY(int y)
{
	this->y = y;
}



void IngameObject::setSpeed(int speed)
{
	this->speed = speed;
}



void IngameObject::setDirection(bool direction)
{
	this->direction = direction;
}



void IngameObject::setGraph(int graph)
{
	this->graph = graph;
}



void IngameObject::setIsDead(int is_dead)
{
	this->is_dead = is_dead;

}



/*
* getter
*/
int IngameObject::getX()
{
	return this->x;
}



int IngameObject::getY()
{
	return this->y;
}



int IngameObject::getSpeed()
{
	return this->speed;
}



bool IngameObject::getDirection()
{
	return this->direction;
}


int IngameObject::getGraph()
{
	return this->graph;
}



bool IngameObject::getIsDead()
{
	return this->is_dead;
}
