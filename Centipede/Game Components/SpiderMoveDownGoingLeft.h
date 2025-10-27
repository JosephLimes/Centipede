#ifndef _SpiderMoveDownGoingLeft
#define _SpiderMoveDownGoingLeft

#include "TEAL\CommonElements.h"
#include "SpiderMoveState.h"

class SpiderMoveDownGoingLeft : public SpiderMoveState
{
public:
	SpiderMoveDownGoingLeft();
	SpiderMoveDownGoingLeft(const SpiderMoveDownGoingLeft&) = delete;
	SpiderMoveDownGoingLeft& operator=(const SpiderMoveDownGoingLeft&) = delete;
	~SpiderMoveDownGoingLeft() = default;

	virtual const SpiderMoveState* GetNextState(sf::Vector2f pos) const override;
	virtual void GetMovement(Spider* s) const override;
};

#endif _SpiderMoveDownGoingLeft