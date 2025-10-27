#ifndef _SpiderMoveState
#define _SpiderMoveState

#include "TEAL\CommonElements.h"

class Spider;

class SpiderMoveState
{
public:
	SpiderMoveState() = default;
	SpiderMoveState(const SpiderMoveState&) = delete;
	SpiderMoveState& operator = (const SpiderMoveState&) = delete;
	~SpiderMoveState() = default;

	const float GetRotation() const;
	virtual const SpiderMoveState* GetNextState(sf::Vector2f pos) const = 0;
	virtual void GetMovement(Spider* s) const = 0;

protected:
	float MyRotation;
};

#endif _SpiderMoveState