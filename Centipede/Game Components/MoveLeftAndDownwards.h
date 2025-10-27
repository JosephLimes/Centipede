#ifndef _MoveLeftAndDownwards
#define _MoveLeftAndDownwards

#include "TEAL\CommonElements.h"
#include "MoveState.h"

class CentipedeHead;

class MoveLeftAndDownwards : public MoveState
{
public:
	MoveLeftAndDownwards();
	virtual const MoveState* GetNextState(sf::Vector2f pos) const override;
};

#endif _MoveLeftAndDownwards