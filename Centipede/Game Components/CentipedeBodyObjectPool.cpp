#include "CentipedeBodyObjectPool.h"
#include "CentipedeBody.h"

CentipedeBody* CentipedeBodyObjectPool::GetCentipedeBody()
{
	CentipedeBody* c;

	if (recycledItems.empty())
	{
		c = new CentipedeBody();
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

void CentipedeBodyObjectPool::ReturnCentipedeBody(CentipedeBody* c)
{
	recycledItems.push(static_cast<CentipedeBody*>(c));
}

CentipedeBodyObjectPool::~CentipedeBodyObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}