#ifndef _CentipedeBodyFactory
#define _CentipedeBodyFactory

#include "TEAL\CommonElements.h"
#include "CentipedeBodyObjectPool.h"

// Forward declarations
class CentipedeSegment;

class CentipedeBodyFactory
{
private:
	static CentipedeBodyFactory* ptrInstance;

	CentipedeBodyFactory() = default;
	CentipedeBodyFactory(const CentipedeBodyFactory&) = delete;
	CentipedeBodyFactory& operator=(const CentipedeBodyFactory&) = delete;
	~CentipedeBodyFactory() = default;

	static CentipedeBodyFactory& Instance()
	{
		if (ptrInstance == nullptr)
		{
			ptrInstance = new CentipedeBodyFactory;
		}
		return *ptrInstance;
	};

	CentipedeBodyObjectPool CentipedeBodyPool;
	std::vector<CentipedeBody*> ActiveCentipedeBodies;

	CentipedeBody* privCreateCentipedeBody(CentipedeSegment* pNext);
	void privRecycleCentipedeBody(GameObject* c);
	void privRecall();

public:
	static CentipedeBody* CreateCentipedeBody(CentipedeSegment* pNext) { return Instance().privCreateCentipedeBody(pNext); };
	static void RecycleCentipedeBody(GameObject* c) { Instance().privRecycleCentipedeBody(c); };
	static void Recall() { Instance().privRecall(); };
	
	static void Terminate();
};

#endif _CentipedeBodyFactory