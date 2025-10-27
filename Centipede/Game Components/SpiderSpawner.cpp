#include "SpiderSpawner.h"
#include "SpiderFactory.h"
#include "GameManager.h"
#include "Grid.h"
#include "Spider.h"

SpiderSpawner::SpiderSpawner()
	: spiderCount(0), enabled(true), spiderSpeed(2), spiderFrequency(5) // default values
{}

void SpiderSpawner::spawn()
{
	// generate x to be either on the left or right side of the screen
	float x;
	if (rand() % 2 == 0) x = 0;
	else x = ScreenWidth * TileSize;

	// generate a random height for the spider where it won't go above player zone or below screen
	float maxY = ScreenHeight * TileSize - Spider::MoveUnitLength;
	float y = (float)((rand() % int((maxY - playerZoneHeight + 1.0f)) + playerZoneHeight));

	SpiderFactory::CreateSpider(sf::Vector2f(x, y), this, spiderSpeed);

	spiderCount++;
}

void SpiderSpawner::death()
{
	spiderCount--;
}

int SpiderSpawner::count() { return spiderCount; }
bool SpiderSpawner::isEnabled() { return enabled; }
float SpiderSpawner::frequency() { return spiderFrequency; }

void SpiderSpawner::setEnabled(bool val) { enabled = val; }
void SpiderSpawner::setSpeed(int val) { spiderSpeed = val; }
void SpiderSpawner::setFrequency(float val) { spiderFrequency = val; }

