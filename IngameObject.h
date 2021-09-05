#pragma once

class IngameObject
{
protected:
	int x;
	int y;
	int speed;
	bool direction;
	int graph;

public:
	void moveAdvance();
	void moveBackwards();
	void set(int x, int y, int speed, bool direction);

	void setX(int x);
	void setY(int y);
	void setSpeed(int speed);
	void setDirection(bool direction);
	void setGraph(int graph);

	int getX();
	int getY();
	int getSpeed();
	bool getDirection();
	int getGraph();
};
