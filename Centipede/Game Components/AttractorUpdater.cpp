#include "AttractorUpdater.h"
#include "GameManager.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "Level.h"

#include "Grid.h"

AttractorUpdater::AttractorUpdater()
{
	RegisterInput(InputFlags::KeyPressed);
}

void AttractorUpdater::Update()
{
	ScoreManager::ProcessScores();
	GameManager::currSoundManager().ProcessSounds();
}

void AttractorUpdater::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	SceneManager::ChangeScene(new Level());
}