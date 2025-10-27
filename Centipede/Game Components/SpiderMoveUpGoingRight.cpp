#include "SpiderMoveFSM.h"
#include "SpiderMoveUpGoingRight.h"
#include "Spider.h"

SpiderMoveUpGoingRight::SpiderMoveUpGoingRight()
{
	MyRotation = 0.0f;
}

const SpiderMoveState* SpiderMoveUpGoingRight::GetNextState(sf::Vector2f pos) const
{
	const SpiderMoveState* pNextState;

	if (rand() % 2 == 0) pNextState = &SpiderMoveFSM::StateMoveRightAndDownwards;
	else pNextState = &SpiderMoveFSM::StateMoveDownGoingRight;

	return pNextState;
}

void SpiderMoveUpGoingRight::GetMovement(Spider* s) const
{
	s->MoveUp();
}