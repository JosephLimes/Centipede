#include "MoveFSM.h"
#include "MoveLeftAndUpwards.h"
#include "Grid.h"
#include "GameManager.h"

MoveLeftAndUpwards::MoveLeftAndUpwards()
{
	for (float i = 0; i < TileSize; i++)
	{
		MyMoveOffsets[(int)i] = sf::Vector2f(0.0f - (i + 1.0f), 0.0f);
		MyRotations[(int)i] = 0.0f;
	}
}

const MoveState* MoveLeftAndUpwards::GetNextState(sf::Vector2f pos) const
{
	const MoveState* pNextState;
	const TileState next = GameManager::currGrid().getTileState(sf::Vector2f(pos.x - TileSize, pos.y));

	// forward is free, keep moving
	if (next == FREE) pNextState = &MoveFSM::StateMoveLeftAndUpwards;
	else if (next == POISONED) pNextState = &MoveFSM::StatePoisonedDownSwitchToRight;
	else // obstacle
	{
		// need to test if we're at top of player zone...
		if (pos.y < playerZoneHeight)
		{
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		}
		else pNextState = &MoveFSM::StateTurnUpSwitchToRight;
	}

	return pNextState;
}