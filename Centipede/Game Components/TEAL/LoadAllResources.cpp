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

	AddTexture("Blaster", "..\\..\\Asset\\Sprites\\blaster.png");
	AddTexture("Bullet", "..\\..\\Asset\\Sprites\\bullet.png");
	AddTexture("CentipedeBody", "..\\..\\Asset\\Sprites\\centipede_segment.png");
	AddTexture("CentipedeHead", "..\\..\\Asset\\Sprites\\centipede_head.png");
	AddTexture("ExplosionBig", "\\..\\..\\Asset\\Sprites\\death.png");
	AddTexture("ExplosionSmall", "\\..\\..\\Asset\\Sprites\\spawn.png");
	AddTexture("ExplosionSpider", "\\..\\..\\Asset\\Sprites\\SPRITES.png");
	AddTexture("Flea", "\\..\\..\\Asset\\Sprites\\flea.png");
	AddTexture("HUDFont", "\\..\\..\\Asset\\Sprites\\FONTwPLAYER.bmp");
	AddTexture("Mushroom", "\\..\\..\\Asset\\Sprites\\mushroom.png");
	AddTexture("Scorpion", "\\..\\..\\Asset\\Sprites\\scorpion.png");
	AddTexture("Spider", "\\..\\..\\Asset\\Sprites\\spider.png");

	AddSound("Centipede", "\\..\\..\\Asset\\Sounds\\newBeat.wav");
	AddSound("CritterDeath", "\\..\\..\\Asset\\Sounds\\kill.wav");
	AddSound("Flea", "\\..\\..\\Asset\\Sounds\\flea_new.wav");
	AddSound("PlayerDeath", "\\..\\..\\Asset\\Sounds\\death.wav");
	AddSound("PlayerFire", "\\..\\..\\Asset\\Sounds\\fire1.wav");
	AddSound("Scorpion", "\\..\\..\\Asset\\Sounds\\scorpion_new.wav");
	AddSound("Spider", "\\..\\..\\Asset\\Sounds\\spiderloop.wav");
}

