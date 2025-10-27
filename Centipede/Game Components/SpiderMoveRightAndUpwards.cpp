#include "SpiderMoveFSM.h"
#include "SpiderMoveRightAndUpwards.h"
#include "Spider.h"

SpiderMoveRightAndUpwards::SpiderMoveRightAndUpwards()
{
	MyRotation = 0.0f;
}

const SpiderMoveState* SpiderMoveRightAndUpwards::GetNextState(sf::Vector2f pos) const
{
	const SpiderMoveState* pNextState;
	
	if (pos.x + Spider::MoveUnitLength > ScreenWidth * TileSize) // about to go off screen, switch direction
	{
		if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveLeftAndDownwards;
		else pNextState = &SpiderMoveFSM::StateMoveDownGoingLeft;
	}
	else
	{
		if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveRightAndDownwards;
		else pNextState = &SpiderMoveFSM::StateMoveDownGoingRight;
	}

	return pNextState;
}

void SpiderMoveRightAndUpwards::GetMovement(Spider* s) const
{
	s->MoveUpRight();
}