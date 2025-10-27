#include "SpiderMoveFSM.h"
#include "SpiderMoveState.h"

// Set up all the unique copies of states
const SpiderMoveRightAndDownwards SpiderMoveFSM::StateMoveRightAndDownwards;
const SpiderMoveRightAndUpwards SpiderMoveFSM::StateMoveRightAndUpwards;
const SpiderMoveLeftAndDownwards SpiderMoveFSM::StateMoveLeftAndDownwards;
const SpiderMoveLeftAndUpwards SpiderMoveFSM::StateMoveLeftAndUpwards;
const SpiderMoveUpGoingLeft SpiderMoveFSM::StateMoveUpGoingLeft;
const SpiderMoveUpGoingRight SpiderMoveFSM::StateMoveUpGoingRight;
const SpiderMoveDownGoingLeft SpiderMoveFSM::StateMoveDownGoingLeft;
const SpiderMoveDownGoingRight SpiderMoveFSM::StateMoveDownGoingRight;

const float SpiderMoveState::GetRotation() const
{
	return MyRotation;
}