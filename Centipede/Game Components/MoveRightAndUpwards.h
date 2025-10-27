#ifndef _MoveRightAndUpwards
#define _MoveRightAndUpwards

#include "TEAL\CommonElements.h"
#include "MoveState.h"

class CentipedeHead;

class MoveRightAndUpwards : public MoveState
{
public:
	MoveRightAndUpwards();
	virtual const MoveState* GetNextState(sf::Vector2f pos) const override;
};

#endif _MoveRightAndDownwards