#include "MushroomObjectPool.h"
#include "Mushroom.h"

Mushroom* MushroomObjectPool::GetMushroom()
{
	Mushroom* m;

	if (recycledItems.empty())
	{
		m = new Mushroom();
	}
	else
	{
		m = recycledItems.top();
		recycledItems.pop();

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}

void MushroomObjectPool::ReturnMushroom(Mushroom* m)
{
	recycledItems.push(static_cast<Mushroom*>(m));
}

MushroomObjectPool::~MushroomObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}