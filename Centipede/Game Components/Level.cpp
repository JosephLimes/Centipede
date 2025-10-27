#include "TEAL\CommonElements.h"

#include "Level.h"
#include "Blaster.h"
#include "Bullet.h"
#include "BulletFactory.h"
#include "CentipedeHead.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBody.h"
#include "CentipedeBodyFactory.h"
#include "EnemyManager.h"
#include "Flea.h"
#include "FleaFactory.h"
#include "Grid.h"
#include "Mushroom.h"
#include "MushroomFactory.h"
#include "Scorpion.h"
#include "ScorpionFactory.h"
#include "Spider.h"
#include "SpiderFactory.h"
#include "ScoreManager.h"
#include "PlayerManager.h"
#include "HUD.h"
#include "GameManager.h"
#include "GameUpdater.h"
#include "ExplosionSmallFactory.h"
#include "ExplosionBigFactory.h"
#include "ExplosionSpiderFactory.h"
//clean these up later, don't need all anymore

void Level::Initialize()
{
	WindowManager::SetBackgroundColor( sf::Color(0,0,0,255) );

	EnemyManager* e = new EnemyManager();
	Grid* g = new Grid();
	HUD* h = new HUD();

	GameManager::Initialize(e, g, h, true, 1);
	new GameUpdater();
	h->Initialize();

	g->setEnemyManager(e);
	g->clearPlayerSpawn(); // must do after enemy manager is set up so potential flea check can happen

	PlayerManager::createPlayerOne(); // set up player
	PlayerManager::setCurrentPlayer(PlayerManager::PlayerOne());


	// bullet -> character collisions
	CollisionTestPair<Bullet, CentipedeHead>();
	CollisionTestPair<Bullet, CentipedeBody>();
	CollisionTestPair<Bullet, Flea>();
	CollisionTestPair<Bullet, Mushroom>();
	CollisionTestPair<Bullet, Scorpion>();
	CollisionTestPair<Bullet, Spider>();

	// character -> obstacle collision
	CollisionTestPair<Blaster, Mushroom>();
	CollisionTestPair<Scorpion, Mushroom>();
	CollisionTestPair<Spider, Mushroom>();

	// character -> blaster collisions
	CollisionTestPair<CentipedeHead, Blaster>();
	CollisionTestPair<CentipedeBody, Blaster>();
	CollisionTestPair<Flea, Blaster>();
	CollisionTestPair<Spider, Blaster>();

};

void Level::Terminate()
{
	BulletFactory::Terminate();
	CentipedeHeadFactory::Terminate();
	CentipedeBodyFactory::Terminate();
	FleaFactory::Terminate();
	MushroomFactory::Terminate();
	ScorpionFactory::Terminate();
	SpiderFactory::Terminate();
	ExplosionSmallFactory::Terminate();
	ExplosionBigFactory::Terminate();
	ExplosionSpiderFactory::Terminate();

	ScoreManager::Terminate();
	PlayerManager::Terminate();
};