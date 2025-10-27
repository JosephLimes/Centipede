#include "ExplosionSmall.h"

void ExplosionSmall::Initialize(sf::Vector2f pos)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("ExplosionSmall"), 3, 2, 60);
	MainSprite.SetAnimation(0, 5);

	MainSprite.scale(2, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(pos);

	SetDrawOrder(1000);
}

void ExplosionSmall::Update()
{
	if ( MainSprite.IsLastAnimationFrame() )
	{
		MarkForDestroy();
	}

	MainSprite.Update();
}

void ExplosionSmall::Draw()
{
	WindowManager::Window().draw(MainSprite);
}