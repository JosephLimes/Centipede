#include "ExplosionSpiderFactory.h"
#include "ExplosionSpiderObjectPool.h"
#include "CmdSoundSingle.h"
#include "GameManager.h"
#include "SoundManager.h"

ExplosionSpiderFactory* ExplosionSpiderFactory::ptrInstance = nullptr;

ExplosionSpiderFactory::ExplosionSpiderFactory()
	: pSpawn(new CmdSoundSingle(ResourceManager::GetSound("CritterDeath")))
{}

void ExplosionSpiderFactory::privCreateExplosionSpider(sf::Vector2f pos, SpiderDistance distance)
{
	ExplosionSpider* e = ExplosionSpiderPool.GetExplosionSpider();
	GameManager::currSoundManager().SendSoundCmd(pSpawn);
	e->Initialize(pos, distance);

	// Declares that this object should be returned here (rather than deleted) when destroyed
	e->SetExternalManagement(RecycleExplosionSpider);
}

void ExplosionSpiderFactory::privRecycleExplosionSpider(GameObject* e)
{
	ExplosionSpiderPool.ReturnExplosionSpider(static_cast<ExplosionSpider*>(e));
}

void ExplosionSpiderFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

ExplosionSpiderFactory::~ExplosionSpiderFactory()
{
	delete pSpawn;
}