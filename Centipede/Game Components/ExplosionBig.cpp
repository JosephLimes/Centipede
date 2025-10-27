#include "ExplosionBig.h"

void ExplosionBig::Initialize(sf::Vector2f pos)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("ExplosionBig"), 4, 2, 30);
	MainSprite.SetAnimation(0, 7);

	MainSprite.scale(1, 1);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(pos);

	SetDrawOrder(1000);
}

void ExplosionBig::Update()
{
	if ( MainSprite.IsLastAnimationFrame() )
	{
		MarkForDestroy();
	}

	MainSprite.Update();
}

void ExplosionBig::Draw()
{
	WindowManager::Window().draw(MainSprite);
}