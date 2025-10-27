#include "ExplosionBigFactory.h"
#include "ExplosionBigObjectPool.h"
#include "ExplosionBig.h"
#include "CmdSoundSingle.h"
#include "GameManager.h"
#include "SoundManager.h"

ExplosionBigFactory* ExplosionBigFactory::ptrInstance = nullptr;

ExplosionBigFactory::ExplosionBigFactory()
	: pSpawn(new CmdSoundSingle(ResourceManager::GetSound("PlayerDeath")))
{}

void ExplosionBigFactory::privCreateExplosionBig(sf::Vector2f pos)
{
	ExplosionBig* e = ExplosionBigPool.GetExplosionBig();

	GameManager::currSoundManager().SendSoundCmd(pSpawn);
	e->Initialize(pos);

	// Declares that this object should be returned here (rather than deleted) when destroyed
	e->SetExternalManagement(RecycleExplosionBig);
}

void ExplosionBigFactory::privRecycleExplosionBig(GameObject* e)
{
	ExplosionBigPool.ReturnExplosionBig(static_cast<ExplosionBig*>(e));
}

void ExplosionBigFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

ExplosionBigFactory::~ExplosionBigFactory()
{
	delete pSpawn;
}