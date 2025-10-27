#include "MoveFSM.h"
#include "MoveLeftAndDownwards.h"
#include "Grid.h"
#include "GameManager.h"

MoveLeftAndDownwards::MoveLeftAndDownwards()
{
	for (float i = 0; i < TileSize; i++)
	{
		MyMoveOffsets[(int)i] = sf::Vector2f(0.0f - (i + 1.0f), 0.0f);
		MyRotations[(int)i] = 0.0f;
	}
}

const MoveState* MoveLeftAndDownwards::GetNextState(sf::Vector2f pos) const
{
	const MoveState* pNextState;
	const TileState next = GameManager::currGrid().getTileState(sf::Vector2f(pos.x - TileSize, pos.y));

	// forward is free, keep moving
	if (next == FREE) pNextState = &MoveFSM::StateMoveLeftAndDownwards;
	else if (next == POISONED) pNextState = &MoveFSM::StatePoisonedDownSwitchToRight;
	else // obstacle
	{
		// need to test if we're on the bottom...
		const TileState below = GameManager::currGrid().getTileState(sf::Vector2f(pos.x, pos.y + TileSize));
		if (below == OFFBOTTOM)
		{
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
		}
		else pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	}

	return pNextState;
}