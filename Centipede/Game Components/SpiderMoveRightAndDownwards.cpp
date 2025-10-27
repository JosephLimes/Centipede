#include "SpiderMoveFSM.h"
#include "SpiderMoveRightAndDownwards.h"
#include "Spider.h"

SpiderMoveRightAndDownwards::SpiderMoveRightAndDownwards()
{
	MyRotation = 0.0f;
}

const SpiderMoveState* SpiderMoveRightAndDownwards::GetNextState(sf::Vector2f pos) const
{
	const SpiderMoveState* pNextState;

	if (pos.x + Spider::MoveUnitLength > ScreenWidth * TileSize) // about to go off screen, switch direction
	{
		if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveLeftAndUpwards;
		else pNextState = &SpiderMoveFSM::StateMoveUpGoingLeft;
	}
	else
	{
		if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveRightAndUpwards;
		else pNextState = &SpiderMoveFSM::StateMoveUpGoingRight;
	}

	return pNextState;
}

void SpiderMoveRightAndDownwards::GetMovement(Spider* s) const
{
	s->MoveDownRight();
}