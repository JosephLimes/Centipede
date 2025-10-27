#include "ExplosionSmallFactory.h"
#include "ExplosionSmallObjectPool.h"
#include "ExplosionSmall.h"
#include "CmdSoundSingle.h"
#include "GameManager.h"
#include "SoundManager.h"

ExplosionSmallFactory* ExplosionSmallFactory::ptrInstance = nullptr;

ExplosionSmallFactory::ExplosionSmallFactory()
	: pSpawn(new CmdSoundSingle(ResourceManager::GetSound("CritterDeath")))
{}

void ExplosionSmallFactory::privCreateExplosionSmall(sf::Vector2f pos)
{
	ExplosionSmall* e = ExplosionSmallPool.GetExplosionSmall();
	GameManager::currSoundManager().SendSoundCmd(pSpawn);
	e->Initialize(pos);

	// Declares that this object should be returned here (rather than deleted) when destroyed
	e->SetExternalManagement(RecycleExplosionSmall);
}

void ExplosionSmallFactory::privRecycleExplosionSmall(GameObject* e)
{
	ExplosionSmallPool.ReturnExplosionSmall(static_cast<ExplosionSmall*>(e));
}

void ExplosionSmallFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

ExplosionSmallFactory::~ExplosionSmallFactory()
{
	delete pSpawn;
}