#ifndef _SpiderMoveRightAndDownwards
#define _SpiderMoveRightAndDownwards

#include "TEAL\CommonElements.h"
#include "SpiderMoveState.h"

class SpiderMoveRightAndDownwards : public SpiderMoveState
{
public:
	SpiderMoveRightAndDownwards();
	SpiderMoveRightAndDownwards(const SpiderMoveRightAndDownwards&) = delete;
	SpiderMoveRightAndDownwards& operator=(const SpiderMoveRightAndDownwards&) = delete;
	~SpiderMoveRightAndDownwards() = default;

	virtual const SpiderMoveState* GetNextState(sf::Vector2f pos) const override;
	virtual void GetMovement(Spider* s) const override;
};

#endif _SpiderMoveRightAndDownwards