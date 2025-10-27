#include "CentipedeHeadObjectPool.h"
#include "CentipedeHead.h"

CentipedeHead* CentipedeHeadObjectPool::GetCentipedeHead()
{
	CentipedeHead* c;

	if (recycledItems.empty())
	{
		c = new CentipedeHead();
	}
	else
	{
		c = recycledItems.top();
		recycledItems.pop();

		// Tell the object to register itself to the scene
		c->RegisterToCurrentScene();
	}

	return c;
}

void CentipedeHeadObjectPool::ReturnCentipedeHead(CentipedeHead* c)
{
	recycledItems.push(static_cast<CentipedeHead*>(c));
}

CentipedeHeadObjectPool::~CentipedeHeadObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}