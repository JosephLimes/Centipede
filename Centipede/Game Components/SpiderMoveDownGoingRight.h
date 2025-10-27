#ifndef _SpiderMoveDownGoingRight
#define _SpiderMoveDownGoingRight

#include "TEAL\CommonElements.h"
#include "SpiderMoveState.h"

class SpiderMoveDownGoingRight : public SpiderMoveState
{
public:
	SpiderMoveDownGoingRight();
	SpiderMoveDownGoingRight(const SpiderMoveDownGoingRight&) = delete;
	SpiderMoveDownGoingRight& operator=(const SpiderMoveDownGoingRight&) = delete;
	~SpiderMoveDownGoingRight() = default;

	virtual const SpiderMoveState* GetNextState(sf::Vector2f pos) const override;
	virtual void GetMovement(Spider* s) const override;
};

#endif _SpiderMoveDownGoingRight