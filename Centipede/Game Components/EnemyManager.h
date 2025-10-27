#ifndef _EnemyManager
#define _EnemyManager

#include "TEAL\CommonElements.h"

class FleaSpawner;
class ScorpionSpawner;
class SpiderSpawner;
class CentipedeSpawner;

class EnemyManager : public GameObject
{
public:
	EnemyManager();
	EnemyManager(const EnemyManager&) = delete;
	EnemyManager& operator=(const EnemyManager&) = delete;
	~EnemyManager();

	virtual void Alarm0();
	virtual void Alarm1();

	void fleaSpawnFlagCheck(); // for requests from grid
	void playerDeath();

	void processWaveData(int wave, std::string data);
	void startWave();

private:
	FleaSpawner* pFleaSpawner;
	ScorpionSpawner* pScorpionSpawner;
	SpiderSpawner* pSpiderSpawner;
	CentipedeSpawner* pCentipedeSpawner;
};

#endif _Grid