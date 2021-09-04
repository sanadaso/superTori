#pragma once

class IngameObject
{
protected:
	int x;
	int y;
	int speed;
	bool direction;

public:
	void IngameObject::moveAdvance();
	void IngameObject::moveBackwards();
	void IngameObject::set(int x, int y, int speed, bool direction);

	void IngameObject::setX(int x);
	void IngameObject::setY(int y);
	void IngameObject::setSpeed(int speed);
	void IngameObject::setDirection(bool direction);

	int IngameObject::getX();
	int IngameObject::getY();
	int IngameObject::getSpeed();
	bool IngameObject::getDirection();
};
