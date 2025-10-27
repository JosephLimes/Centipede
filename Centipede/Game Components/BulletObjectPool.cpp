#include "BulletObjectPool.h"
#include "Bullet.h"

Bullet* BulletObjectPool::GetBullet()
{
	Bullet* b;

	if (recycledItems.empty())
	{
		b = new Bullet();
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();

		// Tell the object to register itself to the scene
		b->RegisterToCurrentScene();
	}

	return b;
}

void BulletObjectPool::ReturnBullet(Bullet* b)
{
	recycledItems.push(static_cast<Bullet*>(b));
}

BulletObjectPool::~BulletObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}