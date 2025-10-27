#ifndef _SpiderFactory
#define _SpiderFactory

#include "TEAL\CommonElements.h"
#include "SpiderObjectPool.h"

// Forward declarations
class SpiderSpawner;
class CmdSound;
enum SpiderDirection;

class SpiderFactory
{
private:
	static SpiderFactory* ptrInstance;

	SpiderFactory();
	SpiderFactory(const SpiderFactory&) = delete;
	SpiderFactory& operator=(const SpiderFactory&) = delete;
	~SpiderFactory();

	static SpiderFactory& Instance()
	{
		if (ptrInstance == nullptr)
		{
			ptrInstance = new SpiderFactory;
		}
		return *ptrInstance;
	};

	SpiderObjectPool SpiderPool;
	std::vector<Spider*> ActiveSpiders;

	void privCreateSpider(sf::Vector2f pos, SpiderSpawner* pSpawner, int speed);
	void privRecycleSpider(GameObject* f);
	void privRecall();

	CmdSound* pSound;

public:
	static void CreateSpider(sf::Vector2f pos, SpiderSpawner* pSpawner, int speed) { Instance().privCreateSpider(pos, pSpawner, speed); };
	static void RecycleSpider(GameObject* f) { Instance().privRecycleSpider(f); };
	static void Recall() { Instance().privRecall(); };

	static void Terminate();
};

#endif _SpiderFactory