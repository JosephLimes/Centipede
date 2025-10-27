#include "FleaSpawner.h"
#include "FleaFactory.h"
#include "GameManager.h"
#include "Grid.h"

FleaSpawner::FleaSpawner()
	: fleaCount(0), enabled(true), fleaSpeed(4), fleaMushroomThreshold(5), fleaMushroomChance(10) // default values
{}

void FleaSpawner::spawn()
{
	// random top tile
	sf::Vector2f pos = sf::Vector2f((float)(rand() % ScreenWidth * TileSize) + (TileSize / 2), (TileSize / 2));

	FleaFactory::CreateFlea(pos, this, fleaSpeed, fleaMushroomChance);
	fleaCount++;
}

void FleaSpawner::spawnConditional()
{
	if (enabled)
	{
		if (GameManager::currGrid().getMushroomsInPlayerZone() < fleaMushroomThreshold && fleaCount < 1) spawn();
	}
}

void FleaSpawner::death()
{
	fleaCount--;
	spawnConditional();
}

void FleaSpawner::setEnabled(bool val) { enabled = val; }
void FleaSpawner::setSpeed(int val) { fleaSpeed = val; }
void FleaSpawner::setMushroomThreshold(int val) { fleaMushroomThreshold = val; }
void FleaSpawner::setMushroomChance(int val) { fleaMushroomChance = val; }

