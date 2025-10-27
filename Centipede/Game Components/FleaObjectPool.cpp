#include "FleaObjectPool.h"
#include "Flea.h"

Flea* FleaObjectPool::GetFlea()
{
	Flea* f;

	if (recycledItems.empty())
	{
		f = new Flea();
	}
	else
	{
		f = recycledItems.top();
		recycledItems.pop();

		// Tell the object to register itself to the scene
		f->RegisterToCurrentScene();
	}

	return f;
}

void FleaObjectPool::ReturnFlea(Flea* f)
{
	recycledItems.push(static_cast<Flea*>(f));
}

FleaObjectPool::~FleaObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}