#include "Enemy.h"

void Enemy::set(int x, int y, int speed, bool direction, int graph, bool flag, bool is_dead)
{
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->direction = direction;
	this->graph = graph;

	this->flag = flag;
	this->is_dead = is_dead;
}



/*
* setter
*/
void Enemy::setFlag(int flag)
{
	this->flag = flag;
}



void Enemy::setIsDead(bool is_dead)
{
	this->is_dead = is_dead;
}



/*
* getter
*/
bool Enemy::getFlag()
{
	return this->flag;
}



bool Enemy::getIsDead()
{
	return this->is_dead;
}
