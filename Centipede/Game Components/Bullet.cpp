#include "Bullet.h"
#include "Blaster.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "Flea.h"
#include "Mushroom.h"
#include "Scorpion.h"
#include "Spider.h"

Bullet::Bullet()
	:	SPEED(16), parentBlaster(nullptr)
{
	MainSprite = sf::Sprite(ResourceManager::GetTexture("Bullet"));
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Bullet");
	SetCollider(MainSprite, bitmap);
}

void Bullet::Initialize(sf::Vector2f p, Blaster* pBlaster)
{
	Pos = p;
	parentBlaster = pBlaster;
	RegisterCollision<Bullet>(*this);
}

void Bullet::Update()
{
	Pos.y -= SPEED;

	if (Pos.y < 0) // Bullet goes offscreen
	{ 
		parentBlaster->setBulletActive(false);
		MarkForDestroy();
	}

	MainSprite.setPosition(Pos);
}

void Bullet::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Bullet::Destroy()
{
	// let blaster know it can fire again
	parentBlaster->setBulletActive(false);

	DeregisterCollision<Bullet>( *this );
}

void Bullet::Collision(CentipedeHead* other)
{
	other->TakeDamage();
	MarkForDestroy();
}

void Bullet::Collision(CentipedeBody* other)
{
	other->TakeDamage();
	MarkForDestroy();
}

void Bullet::Collision( Mushroom *other )
{
	other->TakeDamage();
	MarkForDestroy();
}

void Bullet::Collision(Flea* other)
{
	other->TakeDamage();
	MarkForDestroy();
}

void Bullet::Collision(Scorpion* other)
{
	other->TakeDamage();
	MarkForDestroy();
}

void Bullet::Collision(Spider* other)
{
	
	other->TakeDamage(parentBlaster->getPos()); // grab blaster pos for score calculation
	MarkForDestroy();
}