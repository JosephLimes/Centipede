#ifndef _SpiderMoveUpGoingLeft
#define _SpiderMoveUpGoingLeft

#include "TEAL\CommonElements.h"
#include "SpiderMoveState.h"

class SpiderMoveUpGoingLeft : public SpiderMoveState
{
public:
	SpiderMoveUpGoingLeft();
	SpiderMoveUpGoingLeft(const SpiderMoveUpGoingLeft&) = delete;
	SpiderMoveUpGoingLeft& operator=(const SpiderMoveUpGoingLeft&) = delete;
	~SpiderMoveUpGoingLeft() = default;

	virtual const SpiderMoveState* GetNextState(sf::Vector2f pos) const override;
	virtual void GetMovement(Spider* s) const override;
};

#endif _SpiderMoveUpGoingLeft