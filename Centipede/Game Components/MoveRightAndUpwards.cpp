#include "MoveFSM.h"
#include "MoveRightAndUpwards.h"
#include "GameManager.h"
#include "Grid.h"

MoveRightAndUpwards::MoveRightAndUpwards()
{
	for (float i = 0; i < TileSize; i++)
	{
		MyMoveOffsets[(int)i] = sf::Vector2f(i + 1.0f, 0.0f);
		MyRotations[(int)i] = 180.0f;
	}
}

const MoveState* MoveRightAndUpwards::GetNextState(sf::Vector2f pos) const
{
	const MoveState* pNextState;
	const TileState next = GameManager::currGrid().getTileState(sf::Vector2f(pos.x + TileSize, pos.y));

	// forward is free, keep moving
	if (next == FREE) pNextState = &MoveFSM::StateMoveRightAndUpwards;
	else if (next == POISONED) pNextState = &MoveFSM::StatePoisonedDownSwitchToLeft;
	else // obstacle
	{
		// need to test if we're at top of player zone...
		if (pos.y < playerZoneHeight)
		{
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		}
		else pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	}

	return pNextState;
}