#ifndef _PoisonedDownSwitchToRight
#define _PoisonedDownSwitchToRight

#include "TEAL\CommonElements.h"
#include "MoveState.h"

class CentipedeHead;

class PoisonedDownSwitchToRight : public MoveState
{
public:
	PoisonedDownSwitchToRight();
	virtual const MoveState* GetNextState(sf::Vector2f pos) const override;
};

#endif _PoisonedDownSwitchToRight