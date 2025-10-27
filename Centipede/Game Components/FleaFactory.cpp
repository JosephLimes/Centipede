#include "FleaFactory.h"
#include "FleaObjectPool.h"
#include "Flea.h"
#include "CmdSoundSingle.h"
#include "FleaSpawner.h"
#include "GameManager.h"
#include "SoundManager.h"

FleaFactory* FleaFactory::ptrInstance = nullptr;

FleaFactory::FleaFactory()
	: pSpawn(new CmdSoundSingle(ResourceManager::GetSound("Flea")))
{}

void FleaFactory::privCreateFlea(sf::Vector2f pos, FleaSpawner* pSpawner, int speed, int mushroomChance)
{
	Flea* f = FleaPool.GetFlea();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	f->SetExternalManagement(RecycleFlea);

	GameManager::currSoundManager().SendSoundCmd(pSpawn);
	f->Initialize(pos, pSpawner, speed, mushroomChance);

	ActiveFleas.push_back(f);
}

void FleaFactory::privRecycleFlea(GameObject* f)
{
	FleaPool.ReturnFlea(static_cast<Flea*>(f));
	ActiveFleas.erase(std::remove(ActiveFleas.begin(), ActiveFleas.end(), f), ActiveFleas.end());
}

void FleaFactory::privRecall()
{
	for (Flea* f : ActiveFleas)
	{
		f->MarkForDestroy();
	}
}

void FleaFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

FleaFactory::~FleaFactory()
{
	delete pSpawn;
}