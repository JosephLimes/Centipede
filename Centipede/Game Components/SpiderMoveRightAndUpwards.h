#ifndef _SpiderMoveRightAndUpwards
#define _SpiderMoveRightAndUpwards

#include "TEAL\CommonElements.h"
#include "SpiderMoveState.h"

class SpiderMoveRightAndUpwards : public SpiderMoveState
{
public:
	SpiderMoveRightAndUpwards();
	SpiderMoveRightAndUpwards(const SpiderMoveRightAndUpwards&) = delete;
	SpiderMoveRightAndUpwards& operator=(const SpiderMoveRightAndUpwards&) = delete;
	~SpiderMoveRightAndUpwards() = default;

	virtual const SpiderMoveState* GetNextState(sf::Vector2f pos) const override;
	virtual void GetMovement(Spider* s) const override;
};

#endif _SpiderMoveRightAndUpwards