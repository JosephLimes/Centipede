#include "ExplosionSpider.h"

void ExplosionSpider::Initialize(sf::Vector2f pos, SpiderDistance dist)
{
	if (dist == exNear)
	{
		MainSprite = AnimatedSprite(ResourceManager::GetTexture("ExplosionSpider"), 14, 77);
		MainSprite.SetAnimation(6, 6);
	}
	else if (dist == exMed)
	{
		MainSprite = AnimatedSprite(ResourceManager::GetTexture("ExplosionSpider"), 14, 77);
		MainSprite.SetAnimation(20, 6);
	}
	else // dist == exFar
	{
		MainSprite = AnimatedSprite(ResourceManager::GetTexture("ExplosionSpider"), 14, 77);
		MainSprite.SetAnimation(34, 6);
	}

	MainSprite.scale(2, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(pos);

	SetDrawOrder(1000);

	SetAlarm(0, 1);
}

void ExplosionSpider::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void ExplosionSpider::Alarm0()
{
	MarkForDestroy();
}