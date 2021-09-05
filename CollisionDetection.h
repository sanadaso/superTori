#ifndef __COLLISION_DETECTION_H__
#define __COLLISION_DETECTION_H__

#pragma once
#include <iostream>
#include <string.h>
#include "main.h"
#include "Tornev.h"
#include "ItemObject.h"
#include "Enemy.h"

class CollisionDetection
{
private:
	Tornev m_tornev;
	BGA m_bg;
	ItemObject m_item;
	Enemy m_enemy;

public:
	CollisionDetection(Tornev tornev, BGA bg);
	bool itemColision(ItemObject item);
	bool enemyColision(Enemy enemy);
	bool tornevAttack(Enemy enemy);
};
#endif
