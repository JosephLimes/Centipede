#include "MoveFSM.h"
#include "PoisonedDownSwitchToRight.h"
#include "Grid.h"
#include "GameManager.h"

PoisonedDownSwitchToRight::PoisonedDownSwitchToRight()
{
	for (float i = 0; i < TileSize; i++)
	{
		MyMoveOffsets[(int)i] = sf::Vector2f(0.0f, 1.0f + i);
		MyRotations[(int)i] = 270.0f;
	}
}

const MoveState* PoisonedDownSwitchToRight::GetNextState(sf::Vector2f pos) const
{
	const MoveState* pNextState;
	const TileState next = GameManager::currGrid().getTileState(sf::Vector2f(pos.x, pos.y + TileSize));

	// haven't reached bottom of screen yet, keep going
	if (next != OFFBOTTOM) pNextState = &MoveFSM::StatePoisonedDownSwitchToLeft;
	// reached bottom of screen, resume normal movement
	else pNextState = &MoveFSM::StateMoveRightAndUpwards;

	return pNextState;
}