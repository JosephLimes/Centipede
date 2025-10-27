#include "GameUpdater.h"
#include "GameManager.h"
#include "ScoreManager.h"
#include "SoundManager.h"

void GameUpdater::Update()
{
	ScoreManager::ProcessScores();
	GameManager::currSoundManager().ProcessSounds();
}