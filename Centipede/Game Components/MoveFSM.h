#ifndef _MoveFSM
#define _MoveFSM

#include "MoveRightAndDownwards.h"
#include "MoveRightAndUpwards.h"
#include "MoveLeftAndDownwards.h"
#include "MoveLeftAndUpwards.h"
#include "TurnDownSwitchToLeft.h"
#include "TurnDownSwitchToRight.h"
#include "TurnupSwitchToLeft.h"
#include "TurnupSwitchToRight.h"
#include "PoisonedDownSwitchToLeft.h"
#include "PoisonedDownSwitchToRight.h"

class MoveFSM
{
private:

public:
	MoveFSM() = delete;
	MoveFSM(const MoveFSM&) = delete;
	MoveFSM& operator=(const MoveFSM&) = delete;
	~MoveFSM() = delete;

	static const MoveRightAndDownwards StateMoveRightAndDownwards;
	static const MoveRightAndUpwards StateMoveRightAndUpwards;
	static const MoveLeftAndDownwards StateMoveLeftAndDownwards;
	static const MoveLeftAndUpwards StateMoveLeftAndUpwards;
	static const TurnDownSwitchToLeft StateTurnDownSwitchToLeft;
	static const TurnDownSwitchToRight StateTurnDownSwitchToRight;
	static const TurnUpSwitchToLeft StateTurnUpSwitchToLeft;
	static const TurnUpSwitchToRight StateTurnUpSwitchToRight;
	static const PoisonedDownSwitchToLeft StatePoisonedDownSwitchToLeft;
	static const PoisonedDownSwitchToLeft StatePoisonedDownSwitchToRight;
};

#endif _MoveFSM