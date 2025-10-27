#include "ExplosionBigObjectPool.h"
#include "ExplosionBig.h"

ExplosionBig* ExplosionBigObjectPool::GetExplosionBig()
{
	ExplosionBig* e;

	if (recycledItems.empty())
	{
		e = new ExplosionBig();
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

void ExplosionBigObjectPool::ReturnExplosionBig(ExplosionBig* e)
{
	recycledItems.push(static_cast<ExplosionBig*>(e));
}

ExplosionBigObjectPool::~ExplosionBigObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}