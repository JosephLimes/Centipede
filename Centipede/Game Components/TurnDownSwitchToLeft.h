#ifndef _TurnDownSwitchToLeft
#define _TurnDownSwitchToLeft

#include "TEAL\CommonElements.h"
#include "MoveState.h"

class CentipedeHead;

class TurnDownSwitchToLeft : public MoveState
{
public:
	TurnDownSwitchToLeft();
	virtual const MoveState* GetNextState(sf::Vector2f pos) const override;
};

#endif _TurnDownSwitchToLeft