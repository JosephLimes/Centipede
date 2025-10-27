#include "Player.h"
#include "Blaster.h"
#include "BlasterControllerKeyboard.h"

Player::Player(BlasterController* b, bool AI)
	: controller(b), blaster(new Blaster(controller)), score(0), lives(3), currentWave(1), AI(AI)
{
	// link the controller to its blaster
	controller->SetBlaster(blaster);
}

void Player::addScore(int val)
{
	score += val;
}

int Player::getScore()
{
	return score;
}

int Player::getLives()
{
	return lives;
}

void Player::loseLife()
{
	if (!AI) // don't want attractor screen to be able to game-over
	{
		lives--;
	}
}

Blaster* Player::getBlaster()
{
	return blaster;
}