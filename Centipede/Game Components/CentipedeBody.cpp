#include "CentipedeBody.h"
#include "CentipedeHeadFactory.h"
#include "Blaster.h"
#include "Grid.h"
#include "GameManager.h"
#include "MoveFSM.h"
#include "ScoreManager.h"
#include "ExplosionSmallFactory.h"

CentipedeBody::CentipedeBody()
{
	// get score command
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentipedeBodyKilled);

	// sprite setup
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeBody"), 8, 2);
	MainSprite.SetAnimation(0, 7);
	MainSprite.setOrigin((MainSprite.getTextureRect().width / 2.0f), MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2, 2);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("CentipedeBody");
	SetCollider(MainSprite, bitmap);
}

void CentipedeBody::Initialize(CentipedeSegment* _pNext)
{
	// inherit properties from next segment
	pNext = _pNext;
	sf::Vector2f pNextPos = pNext->GetPos();
	basePos = sf::Vector2f(pNextPos.x, pNextPos.y - TileSize);
	Pos = basePos;
	SPEED = _pNext->GetSpeed();

	frameMoveCount = 0;

	pCurrentState = pNext->GetCurrentState();
	pPrevState = pCurrentState;

	RegisterCollision<CentipedeBody>(*this);
	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void CentipedeBody::Update()
{
	frameMoveCount += SPEED;
	if (frameMoveCount > TileSize) // new tile, need to update state
	{
		frameMoveCount -= TileSize;
		basePos = Pos;
		pPrevState = pCurrentState;
		pCurrentState = pNext->GetPrevState();
	}

	// Update position by applying appropriate offset
	Pos = basePos + pCurrentState->GetMoveOffsets(frameMoveCount - 1);
	// Update rotation by applying appropriate value
	MainSprite.setRotation(pCurrentState->GetRotation(frameMoveCount - 1));

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}


void CentipedeBody::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeBody::Destroy()
{
	DeregisterCollision<CentipedeBody>(*this);
}



void CentipedeBody::TakeDamage()
{
	// spawn explosion
	ExplosionSmallFactory::CreateExplosionSmall(Pos);

	// update score and play sound
	ScoreManager::SendScoreCmd(pDeath);

	pNext->SetPrev(nullptr);
	if (pPrev)
	{
		CentipedeHeadFactory::CreateCentipedeHead(pPrev);
		GameManager::centipedeCreated();
	}
	GameManager::currGrid().placeMushroom(Pos);
	MarkForDestroy();
}

void CentipedeBody::Collision(Blaster* other)
{
	other->TakeDamage();
}