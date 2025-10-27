#include "Flea.h"
#include "Blaster.h"
#include "Grid.h"
#include "GameManager.h"
#include "ScoreManager.h"
#include "ExplosionSmall.h"
#include "ExplosionSmallFactory.h"
#include "FleaSpawner.h"

Flea::Flea()
	: 
	pDeath(ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::FleaKilled))
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 2, 2);
	MainSprite.SetAnimation(0, 3);
	MainSprite.setOrigin((MainSprite.getTextureRect().width / 2.0f) - (TileSize / 2), MainSprite.getTextureRect().height / 2.0f); // for some reason I need this manual -(1/2tilesize) because the sprite doesnt line up
	MainSprite.setScale(1, 1);
	MainSprite.setPosition(Pos);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Flea");
	SetCollider(MainSprite, bitmap);
}

void Flea::Initialize(sf::Vector2f pos, FleaSpawner* _pSpawner, int _SPEED, int _mushroomChance)
{
	Pos = pos;
	ENRAGED = false;
	SPEED = _SPEED;
	mushroomChance = _mushroomChance;
	frameMoveCount = 0;
	pSpawner = _pSpawner;
	RegisterCollision<Flea>(*this);
	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Flea::Update()
{
	frameMoveCount += SPEED;

	if (frameMoveCount >= TileSize && !ENRAGED) // reached a new tile, potentially spawn mushroom
	{
		frameMoveCount -= TileSize;
		if (rand() % 100 + 1 <= mushroomChance) GameManager::currGrid().placeMushroom(Pos);
	}

	Pos.y += SPEED;

	if (Pos.y > ScreenHeight * 16) MarkForDestroy(); // Flea goes offscreen

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}


void Flea::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Flea::Destroy()
{
	pSpawner->death();
	DeregisterCollision<Flea>(*this);
}

void Flea::TakeDamage()
{
	if (ENRAGED == true)
	{
		ExplosionSmallFactory::CreateExplosionSmall(Pos);
		ScoreManager::SendScoreCmd(pDeath);
		MarkForDestroy();
	}
	else
	{
		SPEED = SPEED * 2;
		ENRAGED = true;
	}
}

void Flea::Collision(Blaster* other)
{
	other->TakeDamage();
}