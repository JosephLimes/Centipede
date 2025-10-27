// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "../Level.h"
#include "../Attractor.h"

#include "../HighScoreEnter.h"

void ResourceManager::LoadAllResources()
{
	SetStartScene(new Attractor());

	AddTexture("Blaster", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\blaster.png");
	AddTexture("Bullet", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\bullet.png");
	AddTexture("CentipedeBody", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\centipede_segment.png");
	AddTexture("CentipedeHead", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\centipede_head.png");
	AddTexture("ExplosionBig", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\death.png");
	AddTexture("ExplosionSmall", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\spawn.png");
	AddTexture("ExplosionSpider", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\SPRITES.png");
	AddTexture("Flea", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\flea.png");
	AddTexture("HUDFont", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\FONTwPLAYER.bmp");
	AddTexture("Mushroom", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\mushroom.png");
	AddTexture("Scorpion", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\scorpion.png");
	AddTexture("Spider", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sprites\\spider.png");

	AddSound("Centipede", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sounds\\newBeat.wav");
	AddSound("CritterDeath", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sounds\\kill.wav");
	AddSound("Flea", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sounds\\flea_new.wav");
	AddSound("PlayerDeath", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sounds\\death.wav");
	AddSound("PlayerFire", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sounds\\fire1.wav");
	AddSound("Scorpion", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sounds\\scorpion_new.wav");
	AddSound("Spider", "\\..\\..\\..\\..\\..\\reference\\Asset\\Sounds\\spiderloop.wav");
}

