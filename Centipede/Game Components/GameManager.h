#ifndef _GameManager
#define _GameManager

#include "ScoreSlot.h"

class EnemyManager;
class Grid;
class HUD;
class SoundManager;

const int highScoreListSize = 8;

class GameManager
{
public:

	static EnemyManager& currEnemyManager() { return Instance().privEnemyManager(); };
	static Grid& currGrid() { return Instance().privGrid(); };
	static HUD& currHUD() { return Instance().privHUD(); };
	static SoundManager& currSoundManager() { return Instance().privSoundManager(); };

	static void playerDeath() { Instance().privPlayerDeath(); };
	static void centipedeKilled() { Instance().privCentipedeKilled(); };
	static void centipedeCreated() { Instance().privCentipedeCreated(); };
	static void setHeadCount(int val) { Instance().privSetHeadCount(val); };
	static void highScoreEntered(std::string initials) { Instance().privHighScoreEntered(initials); };
	static void setSoundActive(bool soundActive) { Instance().privSetSoundActive(soundActive); };
	static ScoreSlot* getHighScore(int index) { return Instance().privGetHighScore(index); };

	static void Initialize(EnemyManager* _pEnemyManager, Grid* _pGrid, HUD* _pHUD, bool soundActive, int startWave);
	static void Terminate();

private:
	static GameManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new GameManager;
		return *ptrInstance;
	};
	GameManager();
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
	~GameManager() = default;

	EnemyManager& privEnemyManager();
	Grid& privGrid();
	HUD& privHUD();
	SoundManager& privSoundManager();

	void privPlayerDeath();
	void privCentipedeKilled();
	void privCentipedeCreated();
	void privSetHeadCount(int val);
	void privHighScoreEntered(std::string initials);
	void privSetSoundActive(bool soundActive);
	ScoreSlot* privGetHighScore(int index);

	static GameManager* ptrInstance;

	EnemyManager* pEnemyManager;
	Grid* pGrid;
	HUD* pHUD;
	SoundManager* pSoundManager; // currently active
	SoundManager* pSoundActive;
	SoundManager* pSoundMuted;

	ScoreSlot highScoreList[highScoreListSize];

	std::string waveData;
	int currentWave;
	int headCount;
};

#endif _GameManager