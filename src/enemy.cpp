#include "entity.h"

namespace gt3d {

	Enemy::Enemy()
	{
		this->obj = new graphics::Model("enemies/enemyRobot1.obj");
	}

	FireEnemy::FireEnemy()
	{
		this->obj = new graphics::Model("enemies/enemyRobot1.obj");
	}

	ShockEnemy::ShockEnemy()
	{
		this->obj = new graphics::Model("enemies/enemyRobot2.obj");
	}

	IceEnemy::IceEnemy()
	{
		this->obj = new graphics::Model("enemies/enemyRobot3.obj");
	}
	
}