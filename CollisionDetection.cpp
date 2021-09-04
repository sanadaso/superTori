#include <iostream>
#include <string.h>

#include "CollisionDetection.h"

	CollisionDetection::CollisionDetection(Tornev tornev, BGA bg)
	{
		m_tornev = tornev;
		m_bg = bg;
	}



	bool CollisionDetection::itemColision(ItemObject item)    //メンバ関数の定義
	{
		m_item = item;
		if (
			(m_bg.x + m_item.getX() + 5 < m_tornev.getX() + 95 && m_bg.y + m_item.getY() + 95 > m_tornev.getY() + 5) &&
			(m_bg.x + m_item.getX() + 90 > m_tornev.getX() + 5 && m_bg.y + m_item.getY() + 95 > m_tornev.getY() + 5) &&
			(m_bg.x + m_item.getX() + 5 < m_tornev.getX() + 95 && m_bg.y + m_item.getY() + 5 < m_tornev.getY() + 95) &&
			(m_bg.x + m_item.getX() + 90 > m_tornev.getX() + 5 && m_bg.y + m_item.getY() + 5 < m_tornev.getY() + 95)
			) {
			return true;
		}
		return false;
	}



	bool CollisionDetection::enemyColision(Enemy enemy)    //メンバ関数の定義
	{
		m_enemy = enemy;
		if (
			(m_bg.x + m_enemy.x + 5 < m_tornev.getX() + 95 && m_bg.y + m_enemy.y + 95 > m_tornev.getY() + 5) &&
			(m_bg.x + m_enemy.x + 90 > m_tornev.getX() + 5 && m_bg.y + m_enemy.y + 95 > m_tornev.getY() + 5) &&
			(m_bg.x + m_enemy.x + 5 < m_tornev.getX() + 95 && m_bg.y + m_enemy.y + 5 < m_tornev.getY() + 95) &&
			(m_bg.x + m_enemy.x + 90 > m_tornev.getX() + 5 && m_bg.y + m_enemy.y + 5 < m_tornev.getY() + 95)
			) {
			return true;
		}
		return false;
	}



	bool CollisionDetection::tornevAttack(Enemy enemy)    //メンバ関数の定義
	{
		m_enemy = enemy;
		if (
			(m_bg.x + m_enemy.x + 10 < m_tornev.getX() + 90 && m_bg.y + m_enemy.y + 95 > m_tornev.getY() + 90) && //トルネフの右と上
			(m_bg.x + m_enemy.x + 90 > m_tornev.getX() + 10 && m_bg.y + m_enemy.y + 95 > m_tornev.getY() + 90) && //
			(m_bg.x + m_enemy.x + 10 < m_tornev.getX() + 90 && m_bg.y + m_enemy.y + 5 < m_tornev.getY() + 100) && //
			(m_bg.x + m_enemy.x + 90 > m_tornev.getX() + 10 && m_bg.y + m_enemy.y + 5 < m_tornev.getY() + 100)
			) {
			return true;
		}
		return false;
	}
