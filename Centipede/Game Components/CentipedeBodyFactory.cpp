#include "CentipedeBodyFactory.h"
#include "CentipedeBodyObjectPool.h"
#include "CentipedeBody.h"

CentipedeBodyFactory* CentipedeBodyFactory::ptrInstance = nullptr;

CentipedeBody* CentipedeBodyFactory::privCreateCentipedeBody(CentipedeSegment* pNext)
{
	CentipedeBody* c = CentipedeBodyPool.GetCentipedeBody();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	c->SetExternalManagement(RecycleCentipedeBody);

	c->Initialize(pNext);

	ActiveCentipedeBodies.push_back(c);

	return c;
}

void CentipedeBodyFactory::privRecycleCentipedeBody(GameObject* c)
{
	CentipedeBodyPool.ReturnCentipedeBody(static_cast<CentipedeBody*>(c));
	ActiveCentipedeBodies.erase(std::remove(ActiveCentipedeBodies.begin(), ActiveCentipedeBodies.end(), c), ActiveCentipedeBodies.end());
}

void CentipedeBodyFactory::privRecall()
{
	for (CentipedeBody* c : ActiveCentipedeBodies)
	{
		c->MarkForDestroy();
	}
}

void CentipedeBodyFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
