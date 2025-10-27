#ifndef _SpiderMoveLeftAndDownwards
#define _SpiderMoveLeftAndDownwards

#include "TEAL\CommonElements.h"
#include "SpiderMoveState.h"

class SpiderMoveLeftAndDownwards : public SpiderMoveState
{
public:
	SpiderMoveLeftAndDownwards();
	SpiderMoveLeftAndDownwards(const SpiderMoveLeftAndDownwards&) = delete;
	SpiderMoveLeftAndDownwards& operator=(const SpiderMoveLeftAndDownwards&) = delete;
	~SpiderMoveLeftAndDownwards() = default;

	virtual const SpiderMoveState* GetNextState(sf::Vector2f pos) const override;
	virtual void GetMovement(Spider* s) const override;
};

#endif _SpiderMoveLeftAndDownwards