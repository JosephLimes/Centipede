#include "SpiderMoveFSM.h"
#include "SpiderMoveDownGoingRight.h"
#include "Spider.h"

SpiderMoveDownGoingRight::SpiderMoveDownGoingRight()
{
	MyRotation = 0.0f;
}

const SpiderMoveState* SpiderMoveDownGoingRight::GetNextState(sf::Vector2f pos) const
{
	const SpiderMoveState* pNextState;

	if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveRightAndUpwards;
	else pNextState = &SpiderMoveFSM::StateMoveUpGoingRight;

	return pNextState;
}

void SpiderMoveDownGoingRight::GetMovement(Spider* s) const
{
	s->MoveDown();
}