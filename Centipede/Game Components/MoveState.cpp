#include "MoveFSM.h"
#include "MoveState.h"

// Set up all the unique copies of states
const MoveRightAndDownwards MoveFSM::StateMoveRightAndDownwards;
const MoveRightAndUpwards MoveFSM::StateMoveRightAndUpwards;
const MoveLeftAndDownwards MoveFSM::StateMoveLeftAndDownwards;
const MoveLeftAndUpwards MoveFSM::StateMoveLeftAndUpwards;
const TurnDownSwitchToLeft MoveFSM::StateTurnDownSwitchToLeft;
const TurnDownSwitchToRight MoveFSM::StateTurnDownSwitchToRight;
const TurnUpSwitchToLeft MoveFSM::StateTurnUpSwitchToLeft;
const TurnUpSwitchToRight MoveFSM::StateTurnUpSwitchToRight;
const PoisonedDownSwitchToLeft MoveFSM::StatePoisonedDownSwitchToLeft;
const PoisonedDownSwitchToLeft MoveFSM::StatePoisonedDownSwitchToRight;

const sf::Vector2f MoveState::GetMoveOffsets(int frame) const
{
	return MyMoveOffsets[frame];
}

const float MoveState::GetRotation(int frame) const
{
	return MyRotations[frame];
}