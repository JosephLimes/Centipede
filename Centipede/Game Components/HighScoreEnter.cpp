#include "HighScoreEnter.h"
#include "HighScoreEnterUpdater.h"
#include "GameManager.h"
#include "SoundManagerMuted.h"

void HighScoreEnter::Initialize()
{
	new HighScoreEnterUpdater();
	GameManager::setSoundActive(false);
};