#include "ScorpionFactory.h"
#include "ScorpionObjectPool.h"
#include "Scorpion.h"
#include "GameManager.h"
#include "CmdSoundSingle.h"
#include "GameManager.h"
#include "SoundManager.h"

ScorpionFactory* ScorpionFactory::ptrInstance = nullptr;

ScorpionFactory::ScorpionFactory()
	: pSpawn(new CmdSoundSingle(ResourceManager::GetSound("Scorpion")))
{}

void ScorpionFactory::privCreateScorpion(sf::Vector2f pos, ScorpionSpawner* pSpawner, ScorpionDirection direction, int speed)
{
	Scorpion* s = ScorpionPool.GetScorpion();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	s->SetExternalManagement(RecycleScorpion);

	GameManager::currSoundManager().SendSoundCmd(pSpawn);
	s->Initialize(pos, pSpawner, direction, speed);

	ActiveScorpions.push_back(s);
}

void ScorpionFactory::privRecycleScorpion(GameObject* s)
{
	ScorpionPool.ReturnScorpion(static_cast<Scorpion*>(s));
	ActiveScorpions.erase(std::remove(ActiveScorpions.begin(), ActiveScorpions.end(), s), ActiveScorpions.end());
}

void ScorpionFactory::privRecall()
{
	for (Scorpion* s : ActiveScorpions)
	{
		s->MarkForDestroy();
	}
}

void ScorpionFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

ScorpionFactory::~ScorpionFactory()
{
	delete pSpawn;
}