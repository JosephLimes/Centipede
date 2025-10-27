#include "ScoreManager.h"
#include "CmdScoreValue.h"
#include "CmdScoreByDistance.h"
#include "PlayerManager.h"
#include "Player.h"
#include "GameManager.h"
#include "HUD.h"

ScoreManager* ScoreManager::ptrInstance = nullptr;

ScoreManager::ScoreManager()
	:
	pCentipedeHeadDeath(nullptr),
	pCentipedeBodyDeath(nullptr),
	pFleaDeath(nullptr),
	pScorpionDeath(nullptr),
	pMushroomDeath(nullptr),
	pMushroomPoisonDeath(nullptr),
	pSpiderDeath(nullptr)
{
}

CmdScore* ScoreManager::privGetScoreCommand(ScoreEvents ev)
{
	switch (ev)
	{
	case ScoreEvents::CentipedeHeadKilled:
		if (!pCentipedeHeadDeath)
		{
			pCentipedeHeadDeath = new CmdScoreValue(CentipedeHeadDeath);
		}
		return pCentipedeHeadDeath;
	case ScoreEvents::CentipedeBodyKilled:
		if (!pCentipedeBodyDeath)
		{
			pCentipedeBodyDeath = new CmdScoreValue(CentipedeBodyDeath);
		}
		return pCentipedeBodyDeath;
	case ScoreEvents::FleaKilled:
		if (!pFleaDeath)
		{
			pFleaDeath = new CmdScoreValue(FleaDeath);
		}
		return pFleaDeath;
	case ScoreEvents::ScorpionKilled:
		if (!pScorpionDeath)
		{
			pScorpionDeath = new CmdScoreValue(ScorpionDeath);
		}
		return pScorpionDeath;
	case ScoreEvents::MushroomKilled:
		if (!pMushroomDeath)
		{
			pMushroomDeath = new CmdScoreValue(MushroomDeath);
		}
		return pMushroomDeath;
	case ScoreEvents::MushroomPoisonKilled:
		if (!pMushroomPoisonDeath)
		{
			pMushroomPoisonDeath = new CmdScoreValue(MushroomPoisonDeath);
		}
		return pMushroomPoisonDeath;
	case ScoreEvents::SpiderKilled:
		if (!pSpiderDeath)
		{
			pSpiderDeath = new CmdScoreByDistance(SpiderDistNear, SpiderDistMedium, SpiderDistFar,
				SpiderDeathNear, SpiderDeathMedium, SpiderDeathFar);
		}
		return pSpiderDeath;
	default:
		return nullptr;
	}
}

void ScoreManager::AddScore(int val)
{
	PlayerManager::CurrentPlayer().addScore(val);
}

void ScoreManager::SendScoreCmd(CmdScore* c)
{
	Instance().QueueCmds.push(c);
}

void ScoreManager::ProcessScores()
{
	Instance().privProcessScore();
}

void ScoreManager::privProcessScore()
{
	CmdScore* c;

	if (!QueueCmds.empty())
	{
		while (!QueueCmds.empty())
		{
			c = QueueCmds.front();

			c->Execute();

			QueueCmds.pop();
		}

		// update HUD
		GameManager::currHUD().updateScore(PlayerManager::CurrentPlayer().getScore());
	}

}

void ScoreManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

ScoreManager::~ScoreManager()
{
	delete pCentipedeHeadDeath;
	delete pCentipedeBodyDeath;
	delete pFleaDeath;
	delete pScorpionDeath;
	delete pMushroomDeath;
	delete pMushroomPoisonDeath;
	delete pSpiderDeath;
}