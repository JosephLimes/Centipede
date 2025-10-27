#include "Blaster.h"
#include "BlasterControllerAI.h"
#include "BlasterControllerKeyboard.h"
#include "BulletFactory.h"
#include "GameManager.h"
#include "ExplosionBigFactory.h"

Blaster::Blaster(BlasterController* b)
	: 
	SPEED(5), 
	bulletActive(false), 
	MainSprite(sf::Sprite(ResourceManager::GetTexture("Blaster"))), 
	controller(b)
{
	// Sprite setup
	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1,1);
	MainSprite.setPosition(Pos);
	
	// Spawn in the middle of the player zone
	Pos = sf::Vector2f(WindowManager::Window().getView().getSize().x / 2.0f, (WindowManager::Window().getView().getSize().y - playerZoneHeight) / 2.0f + playerZoneHeight);

	// Collision setup
	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Blaster");
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Blaster>(*this);
}

void Blaster::Update()
{
	PrevPos = Pos;

	// Keyboard checks and movement
	controller->ProcessInputs();

	// Make sure pos stays within bounds
	Tools::Clamp<float>(Pos.x, (float) MainSprite.getTextureRect().width / 2.0f, WindowManager::Window().getView().getSize().x - ((float) MainSprite.getTextureRect().width / 2.0f) );
	Tools::Clamp<float>(Pos.y, playerZoneHeight, WindowManager::Window().getView().getSize().y - (MainSprite.getTextureRect().height / 2.0f));
	MainSprite.setPosition(Pos);
}

void Blaster::FireBullet()
{
	if (bulletActive == false)
	{
		bulletActive = true;
		BulletFactory::CreateBullet(Pos, this);
	}
}

void Blaster::MoveUp() { Pos += sf::Vector2f(0, -SPEED); }
void Blaster::MoveDown() { Pos += sf::Vector2f(0, SPEED); }
void Blaster::MoveLeft() { Pos += sf::Vector2f(-SPEED, 0); }
void Blaster::MoveRight() { Pos += sf::Vector2f(SPEED, 0); }

void Blaster::Collision(Mushroom* other)
{
	Pos = PrevPos;
	MainSprite.setPosition(Pos);
}

sf::Vector2f Blaster::getPos()
{
	return Pos;
}

float Blaster::getSpeed()
{
	return SPEED;
}

void Blaster::setSpeed(float speed)
{
	SPEED = speed;
}

void Blaster::setBulletActive(bool val)
{
	bulletActive = val;
}

void Blaster::TakeDamage()
{
	// spawn explosion
	ExplosionBigFactory::CreateExplosionBig(Pos);

	// teleport to middle
	Pos = sf::Vector2f(WindowManager::Window().getView().getSize().x / 2.0f, (WindowManager::Window().getView().getSize().y - playerZoneHeight) / 2.0f + playerZoneHeight);

	// update game manager
	GameManager::playerDeath();

	// recall active bullet
	BulletFactory::Recall();
}

void Blaster::Draw()
{
	WindowManager::Window().draw(MainSprite);
	MainSprite.setPosition(Pos);
}

void Blaster::Destroy()
{
	delete controller;
	DeregisterInput();
	DeregisterCollision<Blaster>(*this);
}
