#pragma once

class IngameObject
{
protected:
	int x;
	int y;
	int speed;
	bool direction;
	int graph;
	bool is_dead;

public:
	void moveAdvance();
	void moveBackwards();
	void die();
	void set(int x, int y, int speed, bool direction);

	void setX(int x);
	void setY(int y);
	void setSpeed(int speed);
	void setDirection(bool direction);
	void setGraph(int graph);
	void setIsDead(int is_dead);

	int getX();
	int getY();
	int getSpeed();
	bool getDirection();
	int getGraph();
	bool getIsDead();
};
