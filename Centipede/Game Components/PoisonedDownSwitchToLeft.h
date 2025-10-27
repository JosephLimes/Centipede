#ifndef _PoisonedDownSwitchToLeft
#define _PoisonedDownSwitchToLeft

#include "TEAL\CommonElements.h"
#include "MoveState.h"

class CentipedeHead;

class PoisonedDownSwitchToLeft : public MoveState
{
public:
	PoisonedDownSwitchToLeft();
	virtual const MoveState* GetNextState(sf::Vector2f pos) const override;
};

#endif _PoisonedDownSwitchToLeft