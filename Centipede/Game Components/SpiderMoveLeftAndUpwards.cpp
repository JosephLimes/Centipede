#include "SpiderMoveFSM.h"
#include "SpiderMoveLeftAndUpwards.h"
#include "Spider.h"

SpiderMoveLeftAndUpwards::SpiderMoveLeftAndUpwards()
{
	MyRotation = 0.0f;
}

const SpiderMoveState* SpiderMoveLeftAndUpwards::GetNextState(sf::Vector2f pos) const
{
	const SpiderMoveState* pNextState;

	if (pos.x - Spider::MoveUnitLength < 0) // about to go off screen, switch direction
	{
		if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveRightAndDownwards;
		else pNextState = &SpiderMoveFSM::StateMoveDownGoingRight;
	}
	else
	{
		if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveLeftAndDownwards;
		else pNextState = &SpiderMoveFSM::StateMoveDownGoingLeft;
	}

	return pNextState;
}

void SpiderMoveLeftAndUpwards::GetMovement(Spider* s) const
{
	s->MoveUpLeft();
}