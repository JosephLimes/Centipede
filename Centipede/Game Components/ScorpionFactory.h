#ifndef _ScorpionFactory
#define _ScorpionFactory

#include "TEAL\CommonElements.h"
#include "ScorpionObjectPool.h"

// Forward declarations
class ScorpionSpawner;
class CmdSound;
enum ScorpionDirection;

class ScorpionFactory
{
private:
	static ScorpionFactory* ptrInstance;

	ScorpionFactory();
	ScorpionFactory(const ScorpionFactory&) = delete;
	ScorpionFactory& operator=(const ScorpionFactory&) = delete;
	~ScorpionFactory();

	static ScorpionFactory& Instance()
	{
		if (ptrInstance == nullptr)
		{
			ptrInstance = new ScorpionFactory;
		}
		return *ptrInstance;
	};

	ScorpionObjectPool ScorpionPool;
	std::vector<Scorpion*> ActiveScorpions;
	CmdSound* pSpawn;

	void privCreateScorpion(sf::Vector2f pos, ScorpionSpawner* pSpawner, ScorpionDirection direction, int speed);
	void privRecycleScorpion(GameObject* f);
	void privRecall();

public:
	static void CreateScorpion(sf::Vector2f pos, ScorpionSpawner* pSpawner, ScorpionDirection direction, int speed) { Instance().privCreateScorpion(pos, pSpawner, direction, speed); };
	static void RecycleScorpion(GameObject* f) { Instance().privRecycleScorpion(f); };
	static void Recall() { Instance().privRecall(); };

	static void Terminate();
};

#endif _ScorpionFactory