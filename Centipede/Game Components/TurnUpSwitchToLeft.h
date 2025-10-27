#ifndef _TurnUpSwitchToLeft
#define _TurnUpSwitchToLeft

#include "TEAL\CommonElements.h"
#include "MoveState.h"

class CentipedeHead;

class TurnUpSwitchToLeft : public MoveState
{
public:
	TurnUpSwitchToLeft();
	virtual const MoveState* GetNextState(sf::Vector2f pos) const override;
};

#endif _TurnUpSwitchToLeft