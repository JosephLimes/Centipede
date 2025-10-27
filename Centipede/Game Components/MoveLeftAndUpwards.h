#ifndef _MoveLeftAndUpwards
#define _MoveLeftAndUpwards

#include "TEAL\CommonElements.h"
#include "MoveState.h"

class CentipedeHead;

class MoveLeftAndUpwards : public MoveState
{
public:
	MoveLeftAndUpwards();
	virtual const MoveState* GetNextState(sf::Vector2f pos) const override;
};

#endif _MoveLeftAndUpwards