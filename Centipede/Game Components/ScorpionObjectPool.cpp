#include "ScorpionObjectPool.h"
#include "Scorpion.h"

Scorpion* ScorpionObjectPool::GetScorpion()
{
	Scorpion* s;

	if (recycledItems.empty())
	{
		s = new Scorpion();
	}
	else
	{
		s = recycledItems.top();
		recycledItems.pop();

		// Tell the object to register itself to the scene
		s->RegisterToCurrentScene();
	}

	return s;
}

void ScorpionObjectPool::ReturnScorpion(Scorpion* s)
{
	recycledItems.push(static_cast<Scorpion*>(s));
}

ScorpionObjectPool::~ScorpionObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}