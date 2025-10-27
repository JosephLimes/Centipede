#include "CentipedeSpawner.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBodyFactory.h"

CentipedeSpawner::CentipedeSpawner()
	: soloHeadEnabled(true), soloHeadCount(1), speed(2), length(16) // default values
{}

void CentipedeSpawner::startWave()
{
	if (soloHeadEnabled) // spawn our solos first
	{
		for (int i = 0; i < soloHeadCount; i++)
		{
			spawn(1);
		}
	}
	
	// spawn the main centipede
	spawn(length);
}

void CentipedeSpawner::spawn(int _length)
{
	sf::Vector2f spawnPos = sf::Vector2f((float)(rand() % ScreenWidth * TileSize) + (TileSize / 2), (TileSize / 2)); // spawn on a random top tile
	CentipedeSegment* front = CentipedeHeadFactory::CreateCentipedeHead(spawnPos, speed);
	if (_length > 1)
	{
		CentipedeSegment* rear;
		for (int i = 1; i < _length; i++)
		{
			rear = CentipedeBodyFactory::CreateCentipedeBody(front);
			front->SetPrev(rear);
			front = rear;
		}
		rear->SetPrev(nullptr);
	}
}

int CentipedeSpawner::getSoloHeadCount() { return soloHeadCount; }
bool CentipedeSpawner::getSoloHeadEnabled() { return soloHeadEnabled; }

void CentipedeSpawner::setSoloHeadEnabled(bool val) { soloHeadEnabled = val; }
void CentipedeSpawner::setSoloHeadCount(int val) { soloHeadCount = val; }
void CentipedeSpawner::setSpeed(int val) { speed = val; }
void CentipedeSpawner::setLength(int val) { length = val; }

