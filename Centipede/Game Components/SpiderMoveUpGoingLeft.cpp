#include "SpiderMoveFSM.h"
#include "SpiderMoveUpGoingLeft.h"
#include "Spider.h"

SpiderMoveUpGoingLeft::SpiderMoveUpGoingLeft()
{
	MyRotation = 0.0f;
}

const SpiderMoveState* SpiderMoveUpGoingLeft::GetNextState(sf::Vector2f pos) const
{
	const SpiderMoveState* pNextState;

	if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveLeftAndDownwards;
	else pNextState = &SpiderMoveFSM::StateMoveDownGoingLeft;

	return pNextState;
}

void SpiderMoveUpGoingLeft::GetMovement(Spider* s) const
{
	s->MoveUp();
}