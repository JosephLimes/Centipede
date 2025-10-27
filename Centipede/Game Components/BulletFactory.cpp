#include "BulletFactory.h"
#include "BulletObjectPool.h"
#include "Bullet.h"
#include "CmdSoundSingle.h"
#include "GameManager.h"
#include "SoundManager.h"

BulletFactory* BulletFactory::ptrInstance = nullptr;

BulletFactory::BulletFactory()
	: pSpawn(new CmdSoundSingle(ResourceManager::GetSound("PlayerFire")))
{}

void BulletFactory::privCreateBullet(sf::Vector2f pos, Blaster* pBlaster)
{
	Bullet* b = BulletPool.GetBullet();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	b->SetExternalManagement(RecycleBullet);

	GameManager::currSoundManager().SendSoundCmd(pSpawn);
	b->Initialize(pos, pBlaster);
	ActiveBullets.push_back(b);
}

void BulletFactory::privRecycleBullet(GameObject* b)
{
	BulletPool.ReturnBullet(static_cast<Bullet*>(b));
	ActiveBullets.erase(std::remove(ActiveBullets.begin(), ActiveBullets.end(), b), ActiveBullets.end());
}

void BulletFactory::privRecall()
{
	for (Bullet* b : ActiveBullets)
	{
		b->MarkForDestroy();
	}
}

void BulletFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

BulletFactory::~BulletFactory()
{
	delete pSpawn;
}