#include "Spider.h"
#include "Mushroom.h"
#include "SpiderSpawner.h"
#include "SpiderMoveFSM.h"
#include "Blaster.h"
#include "ScoreManager.h"
#include "CmdScoreByDistance.h"
#include "GameManager.h"

Spider::Spider()
	: pDeath(ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::SpiderKilled))
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2, 15);
	MainSprite.SetAnimation(0, 7);
	MainSprite.setScale(sf::Vector2f(2, 2));
	MainSprite.setOrigin((MainSprite.getTextureRect().width / 2.0f), MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Spider");
	SetCollider(MainSprite, bitmap);
}

void Spider::Initialize(sf::Vector2f pos, SpiderSpawner* _pSpawner, int _SPEED)
{
	frameMoveCount = 0;
	Pos = pos;
	SPEED = _SPEED;
	if (Pos.x - MoveUnitLength < 0) pCurrentState = &SpiderMoveFSM::StateMoveRightAndDownwards; // left side of screen
	else pCurrentState = &SpiderMoveFSM::StateMoveLeftAndDownwards; // right side of screen
	pSpawner = _pSpawner;
	RegisterCollision<Spider>(*this);
	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Spider::Update()
{
	pCurrentState->GetMovement(this);
	frameMoveCount += SPEED;
	if (frameMoveCount >= MoveUnitLength)
	{
		frameMoveCount -= MoveUnitLength;
		pCurrentState = pCurrentState->GetNextState(Pos);
	}

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}


void Spider::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Spider::Destroy()
{
	pSpawner->death();
	DeregisterCollision<Spider>(*this);
}

void Spider::MoveUpLeft()
{
	Pos.x -= SPEED;
	Pos.y -= SPEED;
}

void Spider::MoveUpRight()
{
	Pos.x += SPEED;
	Pos.y -= SPEED;
}

void Spider::MoveDownLeft()
{
	Pos.x -= SPEED;
	Pos.y += SPEED;
}

void Spider::MoveDownRight()
{
	Pos.x += SPEED;
	Pos.y += SPEED;
}

void Spider::MoveUp()
{
	Pos.y -= SPEED;
}

void Spider::MoveDown()
{
	Pos.y += SPEED;
}

void Spider::TakeDamage(sf::Vector2f playerPos)
{
	static_cast<CmdScoreByDistance*>(pDeath)->setPositions(Pos, playerPos);
	ScoreManager::SendScoreCmd(pDeath);
	MarkForDestroy();
}

void Spider::Collision(Mushroom* other)
{
	other->GetEaten();
}

void Spider::Collision(Blaster* other)
{
	other->TakeDamage();
}