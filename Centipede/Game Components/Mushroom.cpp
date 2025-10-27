#include "Mushroom.h"
#include "Grid.h"
#include "GameManager.h"
#include "ScoreManager.h"

Mushroom::Mushroom()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	SetCollider(MainSprite, bitmap);
}

void Mushroom::Initialize(sf::Vector2f pos)
{
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomKilled);
	Poisoned = false;
	Pos = pos;
	Damage = 0;
	MainSprite.setPosition(Pos);
	MainSprite.SetFrame(Damage);
	RegisterCollision<Mushroom>(*this);
	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Mushroom::Update()
{

}

void Mushroom::Poison()
{
	if (!Poisoned)
	{
		pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomPoisonKilled);
		MainSprite.SetFrame(MainSprite.GetFrame() + 4);
		Poisoned = true;
	}

}

bool Mushroom::IsPoisoned()
{
	return Poisoned;
}

void Mushroom::TakeDamage()
{
	Damage++;
	if (Damage > 3)
	{
		ScoreManager::SendScoreCmd(pDeath);
		GameManager::currGrid().removeMushroom(Pos);
	}
	else MainSprite.SetFrame(MainSprite.GetFrame() + 1);
	//else
	//{
	//	MainSprite.NextFrame(); // why doesn't this work
	//	MainSprite.Update();
	//}
}

void Mushroom::GetEaten()
{
	GameManager::currGrid().removeMushroom(Pos);
}

void Mushroom::Heal()
{
	Damage = 0;
	Poisoned = false;
	MainSprite.SetFrame(0);
	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomKilled);
}

void Mushroom::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Mushroom::Destroy()
{
	DeregisterCollision<Mushroom>(*this);
}