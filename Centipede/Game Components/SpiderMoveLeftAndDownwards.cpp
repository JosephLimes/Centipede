#include "SpiderMoveFSM.h"
#include "SpiderMoveLeftAndDownwards.h"
#include "Spider.h"

SpiderMoveLeftAndDownwards::SpiderMoveLeftAndDownwards()
{
	MyRotation = 0.0f;
}

const SpiderMoveState* SpiderMoveLeftAndDownwards::GetNextState(sf::Vector2f pos) const
{
	const SpiderMoveState* pNextState;

	if (pos.x - Spider::MoveUnitLength < 0) // about to go off screen, switch direction
	{
		if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveRightAndUpwards;
		else pNextState = &SpiderMoveFSM::StateMoveUpGoingRight;
	}
	else
	{
		if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveLeftAndUpwards;
		else pNextState = &SpiderMoveFSM::StateMoveUpGoingLeft;
	}

	return pNextState;
}

void SpiderMoveLeftAndDownwards::GetMovement(Spider* s) const
{
	s->MoveDownLeft();
}