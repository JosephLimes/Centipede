#ifndef _SpiderMoveUpGoingRight
#define _SpiderMoveUpGoingRight

#include "TEAL\CommonElements.h"
#include "SpiderMoveState.h"

class SpiderMoveUpGoingRight : public SpiderMoveState
{
public:
	SpiderMoveUpGoingRight();
	SpiderMoveUpGoingRight(const SpiderMoveUpGoingRight&) = delete;
	SpiderMoveUpGoingRight& operator=(const SpiderMoveUpGoingRight&) = delete;
	~SpiderMoveUpGoingRight() = default;

	virtual const SpiderMoveState* GetNextState(sf::Vector2f pos) const override;
	virtual void GetMovement(Spider* s) const override;
};

#endif _SpiderMoveUpGoingRight