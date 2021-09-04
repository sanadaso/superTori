#include "IngameObject.h"

void IngameObject::moveAdvance()
{
	this->setX(this->x + this->speed);
}



void IngameObject::moveBackwards()
{
	this->setX(this->x - this->speed);
}



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
