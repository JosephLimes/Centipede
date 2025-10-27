#include "CentipedeHead.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBody.h"
#include "Blaster.h"
#include "Grid.h"
#include "GameManager.h"
#include "MoveFSM.h"
#include "ScoreManager.h"
#include "GameManager.h"
#include "ExplosionSmallFactory.h"

CentipedeHead::CentipedeHead()
{
	// get score command
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentipedeHeadKilled);
	
	// sprit setup
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 8, 2);
	MainSprite.SetAnimation(0, 7);
	MainSprite.setOrigin((MainSprite.getTextureRect().width / 2.0f), MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2, 2);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("CentipedeHead");
	SetCollider(MainSprite, bitmap);
}

void CentipedeHead::Initialize(sf::Vector2f pos, int _SPEED) // set up organically spawning head (not body being promoted)
{
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentipedeHeadKilled);

	pPrev = nullptr;
	pNext = nullptr;

	basePos = pos;
	Pos = pos;

	SPEED = _SPEED;

	frameMoveCount = 0;

	pCurrentState = &MoveFSM::StateTurnDownSwitchToRight;
	pPrevState = pCurrentState;

	RegisterCollision<CentipedeHead>(*this);
	MainSprite.Update();
}

void CentipedeHead::Initialize(CentipedeSegment* prev) // set up head from promoted body segment
{
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentipedeHeadKilled);
	// inherit body's old properties and update our new trailing segment
	pPrev = prev->GetPrev();
	pNext = nullptr;
	Pos = prev->GetPos();
	basePos = prev->GetBasePos();
	frameMoveCount = prev->GetFrameMoveCount();
	pPrevState = prev->GetPrevState();
	pCurrentState = prev->GetCurrentState();
	SPEED = prev->GetSpeed();

	if (pPrev) pPrev->SetNext(this);

	// destroy segment we're replacing
	prev->MarkForDestroy();

	RegisterCollision<CentipedeHead>(*this);
	MainSprite.setPosition(Pos);
	Update();
}

void CentipedeHead::Update()
{
	frameMoveCount += SPEED;
	if (frameMoveCount > TileSize) // new tile, need to check next
	{
		frameMoveCount -= TileSize; // reset counter
		basePos = Pos;
		pPrevState = pCurrentState;
		pCurrentState = pCurrentState->GetNextState(Pos);
	}

	// Update position by applying appropriate offset
	Pos = basePos + pCurrentState->GetMoveOffsets(frameMoveCount - 1);
	// Update rotation by applying appropriate value
	MainSprite.setRotation(pCurrentState->GetRotation(frameMoveCount - 1));

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}


void CentipedeHead::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeHead::Destroy()
{
	DeregisterCollision<CentipedeHead>(*this);
}

void CentipedeHead::TakeDamage()
{
	// spawn explosion
	ExplosionSmallFactory::CreateExplosionSmall(Pos);

	// update score and play sound
	ScoreManager::SendScoreCmd(pDeath);

	if (pPrev) // Promote following segment to head
	{
		CentipedeHeadFactory::CreateCentipedeHead(pPrev);
	}
	else // Otherwise this centipede dies
	{
		GameManager::centipedeKilled();
	}
	GameManager::currGrid().placeMushroom(Pos);
	MarkForDestroy();
}

void CentipedeHead::Collision(Blaster* other)
{
	other->TakeDamage();
}