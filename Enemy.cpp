#include "Enemy.h"

void Enemy::set(int x, int y, int speed, bool direction, bool flag, bool is_dead, int graph)
{
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->direction = direction;

	this->flag = flag;
	this->is_dead = is_dead;
	this->graph = graph;
}



void Enemy::setFlag(int flag)
{
	this->flag = flag;
}



void Enemy::setIsDead(bool is_dead)
{
	this->is_dead = is_dead;
}



void Enemy::setGraph(int graph)
{
	this->graph = graph;
}



bool Enemy::getFlag()
{
	return this->flag;
}



bool Enemy::getIsDead()
{
	return this->is_dead;
}



int Enemy::getGraph()
{
	return this->graph;
}
