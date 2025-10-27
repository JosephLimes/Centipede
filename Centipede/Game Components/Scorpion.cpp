#include "Scorpion.h"
#include "Mushroom.h"
#include "ScorpionSpawner.h"
#include "ScorpionControllerLeft.h"
#include "ScorpionControllerRight.h"
#include "ScoreManager.h"
#include "ExplosionSmallFactory.h"

Scorpion::Scorpion()
	: 
	pDeath(ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::ScorpionKilled))
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Scorpion"), 4, 1, 15);
	MainSprite.SetAnimation(0, 3);
	MainSprite.setOrigin((MainSprite.getTextureRect().width / 2.0f), MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Scorpion");
	SetCollider(MainSprite, bitmap);
}

void Scorpion::Initialize(sf::Vector2f pos, ScorpionSpawner* _pSpawner, ScorpionDirection direction, int _SPEED)
{

	if (direction == LEFT)
	{
		controller = new ScorpionControllerLeft(this);
		pos.x += ScreenWidth * (TileSize + 1);
	}
	else
	{
		controller = new ScorpionControllerRight(this);
		pos.x -= TileSize;
	}


	controller->SetOrientation();
	Pos = pos;
	SPEED = _SPEED;
	pSpawner = _pSpawner;
	RegisterCollision<Scorpion>(*this);
	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Scorpion::Update()
{
	controller->GetMovement();

	if (Pos.x > ScreenWidth * (TileSize + 1) || Pos.x < (0 - TileSize)) MarkForDestroy(); // Scorpion goes offscreen

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}


void Scorpion::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Scorpion::Destroy()
{
	pSpawner->death();
	delete controller;
	DeregisterCollision<Scorpion>(*this);
}

void Scorpion::SetOrientation(float i, float j)
{
	MainSprite.setScale(i, j);
}

void Scorpion::MoveLeft()
{
	Pos.x -= SPEED;
}

void Scorpion::MoveRight()
{
	Pos.x += SPEED;
}

void Scorpion::TakeDamage()
{
	ExplosionSmallFactory::CreateExplosionSmall(Pos);
	ScoreManager::SendScoreCmd(pDeath);
	MarkForDestroy();
}

void Scorpion::Collision(Mushroom* other)
{
	other->Poison();
}