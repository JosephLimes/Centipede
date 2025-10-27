#include "SpiderObjectPool.h"
#include "Spider.h"

Spider* SpiderObjectPool::GetSpider()
{
	Spider* s;

	if (recycledItems.empty())
	{
		s = new Spider();
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

void SpiderObjectPool::ReturnSpider(Spider* s)
{
	recycledItems.push(static_cast<Spider*>(s));
}

SpiderObjectPool::~SpiderObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}