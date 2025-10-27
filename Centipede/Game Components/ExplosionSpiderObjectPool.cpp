#include "ExplosionSpiderObjectPool.h"
#include "ExplosionSpider.h"

ExplosionSpider* ExplosionSpiderObjectPool::GetExplosionSpider()
{
	ExplosionSpider* e;

	if (recycledItems.empty())
	{
		e = new ExplosionSpider();
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

void ExplosionSpiderObjectPool::ReturnExplosionSpider(ExplosionSpider* e)
{
	recycledItems.push(static_cast<ExplosionSpider*>(e));
}

ExplosionSpiderObjectPool::~ExplosionSpiderObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}