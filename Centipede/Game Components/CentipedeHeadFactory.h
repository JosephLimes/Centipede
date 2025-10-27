#ifndef _CentipedeHeadFactory
#define _CentipedeHeadFactory

#include "TEAL\CommonElements.h"
#include "CentipedeHeadObjectPool.h"

// Forward declarations
class CentipedeSegment;
class CmdSound;
class EnemyManager;

class CentipedeHeadFactory
{
private:
	static CentipedeHeadFactory* ptrInstance;

	CentipedeHeadFactory();
	CentipedeHeadFactory(const CentipedeHeadFactory&) = delete;
	CentipedeHeadFactory& operator=(const CentipedeHeadFactory&) = delete;
	~CentipedeHeadFactory();

	static CentipedeHeadFactory& Instance()
	{
		if (ptrInstance == nullptr)
		{
			ptrInstance = new CentipedeHeadFactory;
		}
		return *ptrInstance;
	};

	CentipedeHeadObjectPool CentipedeHeadPool;
	std::vector<CentipedeHead*> ActiveCentipedeHeads;

	CentipedeHead* privCreateCentipedeHead(sf::Vector2f pos, int speed);
	CentipedeHead* privCreateCentipedeHead(CentipedeSegment* prev);
	void privRecycleCentipedeHead(GameObject* c);
	void privRecall();

	CmdSound* pSound;

public:
	static CentipedeHead* CreateCentipedeHead(sf::Vector2f pos, int speed) { return Instance().privCreateCentipedeHead(pos, speed); };
	static CentipedeHead* CreateCentipedeHead(CentipedeSegment* prev) { return Instance().privCreateCentipedeHead(prev); };
	static void RecycleCentipedeHead(GameObject* c) { Instance().privRecycleCentipedeHead(c); };
	static void Recall() { Instance().privRecall(); };

	static void Terminate();
};

#endif _CentipedeHeadFactory