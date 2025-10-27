#include "CentipedeHeadFactory.h"
#include "CentipedeHeadObjectPool.h"
#include "CentipedeHead.h"
#include "CentipedeBodyFactory.h"
#include "CentipedeBody.h"
#include "GameManager.h"
#include "SoundManager.h"
#include "CmdSoundLooping.h"

CentipedeHeadFactory* CentipedeHeadFactory::ptrInstance = nullptr;

CentipedeHeadFactory::CentipedeHeadFactory()
	: pSound(new CmdSoundLooping(ResourceManager::GetSound("Centipede")))
{}

CentipedeHead* CentipedeHeadFactory::privCreateCentipedeHead(sf::Vector2f pos, int speed)
{
	// if first head on screen, start sound
	if (ActiveCentipedeHeads.empty()) GameManager::currSoundManager().SendSoundCmd(pSound); 

	CentipedeHead* c = CentipedeHeadPool.GetCentipedeHead();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	c->SetExternalManagement(RecycleCentipedeHead);

	c->Initialize(pos, speed);

	ActiveCentipedeHeads.push_back(c);

	return c;
}

CentipedeHead* CentipedeHeadFactory::privCreateCentipedeHead(CentipedeSegment* prev)
{
	CentipedeHead* c = CentipedeHeadPool.GetCentipedeHead();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	c->SetExternalManagement(RecycleCentipedeHead);

	c->Initialize(prev);

	ActiveCentipedeHeads.push_back(c);
	
	return c;
}

void CentipedeHeadFactory::privRecycleCentipedeHead(GameObject* c)
{
	CentipedeHeadPool.ReturnCentipedeHead(static_cast<CentipedeHead*>(c));
	ActiveCentipedeHeads.erase(std::remove(ActiveCentipedeHeads.begin(), ActiveCentipedeHeads.end(), c), ActiveCentipedeHeads.end());
	// if last centipede on screen killed, stop sound
	if (ActiveCentipedeHeads.empty()) GameManager::currSoundManager().SendSoundCmd(pSound);
}

void CentipedeHeadFactory::privRecall()
{
	for (CentipedeHead* c : ActiveCentipedeHeads)
	{
		c->MarkForDestroy();
	}
}

void CentipedeHeadFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

CentipedeHeadFactory::~CentipedeHeadFactory()
{
	delete pSound;
}