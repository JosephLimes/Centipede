#include "GameManager.h"
#include "EnemyManager.h"
#include "Grid.h"
#include "PlayerManager.h"
#include "Player.h"
#include "SoundManagerActive.h"
#include "SoundManagerMuted.h"
#include "Attractor.h"
#include "ScoreSlot.h"
#include "HighScoreEnter.h"
#include <fstream>

#include <iostream>
#include <stdio.h>

GameManager* GameManager::ptrInstance;

GameManager::GameManager()
	: pEnemyManager(nullptr), pGrid(nullptr), pHUD(nullptr), pSoundManager(nullptr)
{
	pSoundActive = new SoundManagerActive();
	pSoundMuted = new SoundManagerMuted();

	for (int i = 0; i < highScoreListSize; i++) // initially populate the high score list with dummy scores
	{
		highScoreList[i].setScore(1000 - i);
		highScoreList[i].setInitials("abc");
	}
}

void GameManager::Initialize(EnemyManager* _pEnemyManager, Grid* _pGrid, HUD* _pHUD, bool soundActive, int startWave)
{
	if (soundActive) Instance().pSoundManager = Instance().pSoundActive;
	else Instance().pSoundManager = Instance().pSoundMuted;

	Instance().pEnemyManager = _pEnemyManager;

	if (Instance().pGrid)
	{
		delete Instance().pGrid;
	}
	Instance().pGrid = _pGrid;

	Instance().pHUD = _pHUD;
	Instance().currentWave = startWave;

	// read wave data from config
	std::ifstream file("..\\config.txt");
	// make sure file is actually there and open
	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file");
	}
	std::string line;
	while (getline(file, line))
	{
		Instance().waveData = Instance().waveData + line + "\n";
	}
	file.close();
	// send data to enemy manager for processing
	Instance().pEnemyManager->processWaveData(Instance().currentWave, Instance().waveData);
}

void GameManager::Terminate()
{
	delete Instance().pSoundActive;
	delete Instance().pSoundMuted;
	delete Instance().pGrid;
	delete ptrInstance;
	ptrInstance = nullptr;
}

EnemyManager& GameManager::privEnemyManager()
{
	return *pEnemyManager;
}

Grid& GameManager::privGrid()
{
	return *pGrid;
}

HUD& GameManager::privHUD()
{
	return *pHUD;
}

SoundManager& GameManager::privSoundManager()
{
	return *pSoundManager;
}

void GameManager::privPlayerDeath()
{
	PlayerManager::playerDeath();

	if (PlayerManager::CurrentPlayer().getLives() == 0) // game over
	{
		int score = PlayerManager::CurrentPlayer().getScore(); // grab their score
		if (score > highScoreList[highScoreListSize - 1].getScore()) // high enough to be a high score, update list and go to high score enter screen
		{
			highScoreList[highScoreListSize - 1].setScore(score);
			SceneManager::ChangeScene(new HighScoreEnter()); // let player enter their initials
		}
		else
		{
			SceneManager::ChangeScene(new Attractor());
		}
	}
	else
	{
		pEnemyManager->playerDeath();
		pGrid->regenerateField();
		pEnemyManager->startWave();
	}
}

void GameManager::privCentipedeKilled()
{
	headCount--;
	Trace::out("Centipede Head Count: %d\n", headCount);
	if (headCount <= 0) // start next wave
	{
		pGrid->regenerateField();
		currentWave++;
		pEnemyManager->processWaveData(currentWave, waveData);
	}
}

void GameManager::privCentipedeCreated()
{
	headCount++;
}

void GameManager::privSetHeadCount(int val)
{
	headCount = val;
}

void GameManager::privHighScoreEntered(std::string initials)
{
	// called when changing from score enter screen -> attractor screen

	highScoreList[highScoreListSize - 1].setInitials(initials);
	std::sort(highScoreList, highScoreList + highScoreListSize);

	SceneManager::ChangeScene(new Attractor());
}

void GameManager::privSetSoundActive(bool soundActive)
{
	pSoundManager->ClearCommands(); // if we don't do this, there is a memory read access error when switching sound modes

	if (soundActive) Instance().pSoundManager = Instance().pSoundActive;
	else Instance().pSoundManager = Instance().pSoundMuted;
}

ScoreSlot* GameManager::privGetHighScore(int index)
{
	return &Instance().highScoreList[index];
}