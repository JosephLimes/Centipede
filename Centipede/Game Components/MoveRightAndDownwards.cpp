#include "MoveFSM.h"
#include "MoveRightAndDownwards.h"
#include "Grid.h"
#include "GameManager.h"

MoveRightAndDownwards::MoveRightAndDownwards()
{
	for (float i = 0; i < TileSize; i++)
	{
		MyMoveOffsets[(int)i] = sf::Vector2f(i + 1.0f, 0.0f);
		MyRotations[(int)i] = 180.0f;
	}
}

const MoveState* MoveRightAndDownwards::GetNextState(sf::Vector2f pos) const
{
	const MoveState* pNextState;
	const TileState next = GameManager::currGrid().getTileState(sf::Vector2f(pos.x + TileSize, pos.y));

	// forward is free, keep moving
	if (next == FREE) pNextState = &MoveFSM::StateMoveRightAndDownwards;
	else if (next == POISONED) pNextState = &MoveFSM::StatePoisonedDownSwitchToLeft;
	else // obstacle
	{
		// need to test if we're on the bottom...
		const TileState below = GameManager::currGrid().getTileState(sf::Vector2f(pos.x, pos.y + TileSize));
		if (below == OFFBOTTOM)
		{
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		}
		else
		{
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		}
		
	}

	return pNextState;
}