#include "ExplosionSmallObjectPool.h"
#include "ExplosionSmall.h"

ExplosionSmall* ExplosionSmallObjectPool::GetExplosionSmall()
{
	ExplosionSmall* e;

	if (recycledItems.empty())
	{
		e = new ExplosionSmall();
	}
	else
	{
		e = recycledItems.top();
		recycledItems.pop();

		// Tell the object to register itself to the scene
		e->RegisterToCurrentScene();
	}

	return e;
}

void ExplosionSmallObjectPool::ReturnExplosionSmall(ExplosionSmall* e)
{
	recycledItems.push(static_cast<ExplosionSmall*>(e));
}

ExplosionSmallObjectPool::~ExplosionSmallObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}