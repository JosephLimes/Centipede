#ifndef _TurnDownSwitchToRight
#define _TurnDownSwitchToRight

#include "TEAL\CommonElements.h"
#include "MoveState.h"

class CentipedeHead;

class TurnDownSwitchToRight : public MoveState
{
public:
	TurnDownSwitchToRight();
	virtual const MoveState* GetNextState(sf::Vector2f pos) const override;
};

#endif _TurnDownSwitchToLeft