#ifndef _ExplosionSpiderFactory
#define _ExplosionSpiderFactory

#include "TEAL\CommonElements.h"
#include "ExplosionSpiderObjectPool.h"
#include "ExplosionSpider.h"

// Forward declaration
class CmdSound;

class ExplosionSpiderFactory
{
private:
	static ExplosionSpiderFactory* ptrInstance;

	ExplosionSpiderFactory();
	ExplosionSpiderFactory(const ExplosionSpiderFactory&) = delete;
	ExplosionSpiderFactory& operator=(const ExplosionSpiderFactory&) = delete;
	~ExplosionSpiderFactory();

	static ExplosionSpiderFactory& Instance()
	{
		if (ptrInstance == nullptr)
		{
			ptrInstance = new ExplosionSpiderFactory;
		}
		return *ptrInstance;
	};

	ExplosionSpiderObjectPool ExplosionSpiderPool;
	CmdSound* pSpawn;

	void privCreateExplosionSpider(sf::Vector2f pos, SpiderDistance distance);
	void privRecycleExplosionSpider(GameObject* e);

public:
	static void CreateExplosionSpider(sf::Vector2f pos, SpiderDistance distance) { Instance().privCreateExplosionSpider(pos, distance); };
	static void RecycleExplosionSpider(GameObject* e) { Instance().privRecycleExplosionSpider(e); };

	static void Terminate();
};

#endif _ExplosionSpiderFactory