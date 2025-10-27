#ifndef _FleaFactory
#define _FleaFactory

#include "TEAL\CommonElements.h"
#include "FleaObjectPool.h"

// Forward declarations
class FleaSpawner;
class CmdSound;

class FleaFactory
{
private:
	static FleaFactory* ptrInstance;

	FleaFactory();
	FleaFactory(const FleaFactory&) = delete;
	FleaFactory& operator=(const FleaFactory&) = delete;
	~FleaFactory();

	static FleaFactory& Instance()
	{
		if (ptrInstance == nullptr)
		{
			ptrInstance = new FleaFactory;
		}
		return *ptrInstance;
	};

	FleaObjectPool FleaPool;
	std::vector<Flea*> ActiveFleas;
	CmdSound* pSpawn;

	void privCreateFlea(sf::Vector2f pos, FleaSpawner* pSpawner, int speed, int mushroomChance);
	void privRecycleFlea(GameObject* f);
	void privRecall();

public:
	static void CreateFlea(sf::Vector2f pos, FleaSpawner* pSpawner, int speed, int mushroomChance) { Instance().privCreateFlea(pos, pSpawner, speed, mushroomChance); };
	static void RecycleFlea(GameObject* f) { Instance().privRecycleFlea(f); };
	static void Recall() { Instance().privRecall(); }

	static void Terminate();
};

#endif _FleaFactory