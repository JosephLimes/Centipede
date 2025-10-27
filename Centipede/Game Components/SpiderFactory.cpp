#include "SpiderFactory.h"
#include "SpiderObjectPool.h"
#include "Spider.h"
#include "GameManager.h"
#include "SoundManager.h"
#include "CmdSoundLooping.h"

SpiderFactory* SpiderFactory::ptrInstance = nullptr;

SpiderFactory::SpiderFactory()
	: pSound(new CmdSoundLooping(ResourceManager::GetSound("Spider")))
{}

void SpiderFactory::privCreateSpider(sf::Vector2f pos, SpiderSpawner* pSpawner, int speed)
{
	if (ActiveSpiders.empty()) GameManager::currSoundManager().SendSoundCmd(pSound); // first spider on screen, start sound

	Spider* s = SpiderPool.GetSpider();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	s->SetExternalManagement(RecycleSpider);

	s->Initialize(pos, pSpawner, speed);

	ActiveSpiders.push_back(s);
}

void SpiderFactory::privRecycleSpider(GameObject* s)
{
	SpiderPool.ReturnSpider(static_cast<Spider*>(s));
	ActiveSpiders.erase(std::remove(ActiveSpiders.begin(), ActiveSpiders.end(), s), ActiveSpiders.end());
	if (ActiveSpiders.empty()) GameManager::currSoundManager().SendSoundCmd(pSound); // last spider on screen killed, stop sound
}

void SpiderFactory::privRecall()
{
	for (Spider* s : ActiveSpiders)
	{
		s->MarkForDestroy();
	}
}

void SpiderFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

SpiderFactory::~SpiderFactory()
{
	delete pSound;
}