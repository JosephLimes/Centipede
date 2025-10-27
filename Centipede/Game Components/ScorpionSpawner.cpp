#include "ScorpionSpawner.h"
#include "ScorpionFactory.h"
#include "GameManager.h"
#include "Grid.h"
#include "Scorpion.h"

ScorpionSpawner::ScorpionSpawner()
	: scorpionCount(0), enabled(true), scorpionSpeed(1), scorpionFrequency(5) // default values
{}

void ScorpionSpawner::spawn()
{
	// determine which side of the screen to spawn on
	ScorpionDirection direction;
	if (rand() % 2 == 0) direction = LEFT;
	else direction = RIGHT;

	// get random height in the top half of screen
	sf::Vector2f pos = sf::Vector2f(0.0f, (float)(rand() % (ScreenHeight / 2) * TileSize + (TileSize / 2)));
	ScorpionFactory::CreateScorpion(pos, this, direction, scorpionSpeed);
	scorpionCount++;
}

void ScorpionSpawner::death()
{
	scorpionCount--;
}

int ScorpionSpawner::count() { return scorpionCount; }
bool ScorpionSpawner::isEnabled() { return enabled; }
float ScorpionSpawner::frequency() { return scorpionFrequency; }

void ScorpionSpawner::setEnabled(bool val) { enabled = val; }
void ScorpionSpawner::setSpeed(int val) { scorpionSpeed = val; }
void ScorpionSpawner::setFrequency(float val) { scorpionFrequency = val; }

