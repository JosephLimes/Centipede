#include "PlayerManager.h"
#include "Player.h"
#include "GameManager.h"
#include "HUD.h"
#include "BlasterControllerKeyboard.h"
#include "BlasterControllerAI.h"
#include "Blaster.h"

PlayerManager* PlayerManager::ptrInstance;

PlayerManager::PlayerManager()
	: pCurrentPlayer(nullptr), pPlayerOne(nullptr), pPlayerTwo(nullptr), pPlayerAI(nullptr)
{

}

void PlayerManager::privSetCurrentPlayer(Player* p)
{
	pCurrentPlayer = p;
}

void PlayerManager::privPlayerDeath()
{
	pCurrentPlayer->loseLife();

	// update HUD
	GameManager::currHUD().updateLives(PlayerManager::CurrentPlayer().getLives());
}

void PlayerManager::privCreatePlayerOne()
{						
	if (!pPlayerOne)
	{
		pPlayerOne = new Player(new BlasterControllerKeyboard(), false);
	}
}						
						
void PlayerManager::privCreatePlayerTwo()
{						
	// there is no player two in the final version
}						
						
void PlayerManager::privCreatePlayerAI()
{
	if (!pPlayerAI)
	{
		pPlayerAI = new Player(new BlasterControllerAI(), true);
		pPlayerAI->getBlaster()->setSpeed(2); // makes movement less erratic
	}
}

Player& PlayerManager::CurrentPlayer()
{
	return *Instance().pCurrentPlayer;
}

Player* PlayerManager::PlayerOne()
{
	return Instance().pPlayerOne;
}

Player* PlayerManager::PlayerTwo()
{
	return Instance().pPlayerTwo;
}

Player* PlayerManager::PlayerAI()
{
	return Instance().pPlayerAI;
}

void PlayerManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

PlayerManager::~PlayerManager()
{
	delete pPlayerOne;
	delete pPlayerTwo;
	delete pPlayerAI;
}