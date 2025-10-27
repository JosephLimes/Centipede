#ifndef _SpiderMoveLeftAndUpwards
#define _SpiderMoveLeftAndUpwards

#include "TEAL\CommonElements.h"
#include "SpiderMoveState.h"

class SpiderMoveLeftAndUpwards : public SpiderMoveState
{
public:
	SpiderMoveLeftAndUpwards();
	SpiderMoveLeftAndUpwards(const SpiderMoveLeftAndUpwards&) = delete;
	SpiderMoveLeftAndUpwards& operator=(const SpiderMoveLeftAndUpwards&) = delete;
	~SpiderMoveLeftAndUpwards() = default;

	virtual const SpiderMoveState* GetNextState(sf::Vector2f pos) const override;
	virtual void GetMovement(Spider* s) const override;
};

#endif _SpiderMoveLeftAndUpwards