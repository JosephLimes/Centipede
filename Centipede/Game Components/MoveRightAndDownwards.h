#ifndef _MoveRightAndDownwards
#define _MoveRightAndDownwards

#include "TEAL\CommonElements.h"
#include "MoveState.h"

class CentipedeHead;

class MoveRightAndDownwards : public MoveState
{
public:
	MoveRightAndDownwards();
	virtual const MoveState* GetNextState(sf::Vector2f pos) const override;
};

#endif _MoveRightAndDownwards