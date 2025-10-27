#ifndef _ExplosionBigFactory
#define _ExplosionBigFactory

#include "TEAL\CommonElements.h"
#include "ExplosionBigObjectPool.h"

// Forward declaration
class CmdSound;

class ExplosionBigFactory
{
private:
	static ExplosionBigFactory* ptrInstance;

	ExplosionBigFactory();
	ExplosionBigFactory(const ExplosionBigFactory&) = delete;
	ExplosionBigFactory& operator=(const ExplosionBigFactory&) = delete;
	~ExplosionBigFactory();

	static ExplosionBigFactory& Instance()
	{
		if (ptrInstance == nullptr)
		{
			ptrInstance = new ExplosionBigFactory;
		}
		return *ptrInstance;
	};

	ExplosionBigObjectPool ExplosionBigPool;
	CmdSound* pSpawn;

	void privCreateExplosionBig(sf::Vector2f pos);
	void privRecycleExplosionBig(GameObject* e);

public:
	static void CreateExplosionBig(sf::Vector2f pos) { Instance().privCreateExplosionBig(pos); };
	static void RecycleExplosionBig(GameObject* e) { Instance().privRecycleExplosionBig(e); };

	static void Terminate();
};

#endif _ExplosionBigFactory