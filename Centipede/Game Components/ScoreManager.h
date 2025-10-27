#ifndef _ScoreManager
#define _ScoreManager

#include "TEAL\CommonElements.h"
#include <queue>

class CmdScore;

class ScoreManager
{
public:
	// events
	enum class ScoreEvents { CentipedeHeadKilled, CentipedeBodyKilled, FleaKilled, ScorpionKilled, MushroomKilled, MushroomPoisonKilled, SpiderKilled };
private:
	static const int CentipedeHeadDeath = 200;
	static const int CentipedeBodyDeath = 50;
	static const int FleaDeath = 200;
	static const int ScorpionDeath = 250;
	static const int MushroomDeath = 4;
	static const int MushroomPoisonDeath = 8;

	static const int SpiderDeathFar = 300;
	static const int SpiderDistFar = 9999;
	static const int SpiderDeathMedium = 600;
	static const int SpiderDistMedium = 75;
	static const int SpiderDeathNear = 900;
	static const int SpiderDistNear = 50;

	CmdScore* pCentipedeHeadDeath;
	CmdScore* pCentipedeBodyDeath;
	CmdScore* pFleaDeath;
	CmdScore* pScorpionDeath;
	CmdScore* pMushroomDeath;
	CmdScore* pMushroomPoisonDeath;
	CmdScore* pSpiderDeath;

	std::queue<CmdScore*> QueueCmds;

	static ScoreManager* ptrInstance;

	ScoreManager();
	ScoreManager(const ScoreManager&) = delete;
	ScoreManager& operator=(const ScoreManager&) = delete;
	~ScoreManager();

	static ScoreManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ScoreManager;
		return *ptrInstance;
	};

	void privProcessScore();
	CmdScore* privGetScoreCommand(ScoreEvents ev);

public:

	static void AddScore(int val);

	static CmdScore* GetScoreCommand(ScoreEvents ev) { return Instance().privGetScoreCommand(ev); };

	static void SendScoreCmd(CmdScore* c);
	static void ProcessScores();

	static void Terminate();
};

#endif _ScoreManager