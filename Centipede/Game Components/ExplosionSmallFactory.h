#ifndef _ExplosionSmallFactory
#define _ExplosionSmallFactory

#include "TEAL\CommonElements.h"
#include "ExplosionSmallObjectPool.h"

// Forward declaration
class CmdSound;

class ExplosionSmallFactory
{
private:
	static ExplosionSmallFactory* ptrInstance;

	ExplosionSmallFactory();
	ExplosionSmallFactory(const ExplosionSmallFactory&) = delete;
	ExplosionSmallFactory& operator=(const ExplosionSmallFactory&) = delete;
	~ExplosionSmallFactory();

	static ExplosionSmallFactory& Instance()
	{
		if (ptrInstance == nullptr)
		{
			ptrInstance = new ExplosionSmallFactory;
		}
		return *ptrInstance;
	};

	ExplosionSmallObjectPool ExplosionSmallPool;
	CmdSound* pSpawn;

	void privCreateExplosionSmall(sf::Vector2f pos);
	void privRecycleExplosionSmall(GameObject* e);

public:
	static void CreateExplosionSmall(sf::Vector2f pos) { Instance().privCreateExplosionSmall(pos); };
	static void RecycleExplosionSmall(GameObject* e) { Instance().privRecycleExplosionSmall(e); };

	static void Terminate();
};

#endif _ExplosionSmallFactory