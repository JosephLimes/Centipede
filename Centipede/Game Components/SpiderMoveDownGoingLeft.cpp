#include "SpiderMoveFSM.h"
#include "SpiderMoveDownGoingLeft.h"
#include "Spider.h"

SpiderMoveDownGoingLeft::SpiderMoveDownGoingLeft()
{
	MyRotation = 0.0f;
}

const SpiderMoveState* SpiderMoveDownGoingLeft::GetNextState(sf::Vector2f pos) const
{
	const SpiderMoveState* pNextState;

	if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveLeftAndUpwards;
	else pNextState = &SpiderMoveFSM::StateMoveUpGoingLeft;

	return pNextState;
}

void SpiderMoveDownGoingLeft::GetMovement(Spider* s) const
{
	s->MoveDown();
}