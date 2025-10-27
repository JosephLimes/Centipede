#ifndef _TurnUpSwitchToRight
#define _TurnUpSwitchToRight

#include "TEAL\CommonElements.h"
#include "MoveState.h"

class CentipedeHead;

class TurnUpSwitchToRight : public MoveState
{
public:
	TurnUpSwitchToRight();
	virtual const MoveState* GetNextState(sf::Vector2f pos) const override;
};

#endif _TurnUpSwitchToRight