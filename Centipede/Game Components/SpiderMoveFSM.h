#ifndef _SpiderMoveFSM
#define _SpiderMoveFSM

#include "SpiderMoveRightAndDownwards.h"
#include "SpiderMoveRightAndUpwards.h"
#include "SpiderMoveLeftAndDownwards.h"
#include "SpiderMoveLeftAndUpwards.h"
#include "SpiderMoveDownGoingLeft.h"
#include "SpiderMoveDownGoingRight.h"
#include "SpiderMoveUpGoingLeft.h"
#include "SpiderMoveUpGoingRight.h"

class SpiderMoveFSM
{
private:

public:
	SpiderMoveFSM() = delete;
	SpiderMoveFSM(const SpiderMoveFSM&) = delete;
	SpiderMoveFSM& operator=(const SpiderMoveFSM&) = delete;
	~SpiderMoveFSM() = delete;

	static const SpiderMoveRightAndDownwards StateMoveRightAndDownwards;
	static const SpiderMoveRightAndUpwards StateMoveRightAndUpwards;
	static const SpiderMoveLeftAndDownwards StateMoveLeftAndDownwards;
	static const SpiderMoveLeftAndUpwards StateMoveLeftAndUpwards;
	static const SpiderMoveUpGoingLeft StateMoveUpGoingLeft;
	static const SpiderMoveUpGoingRight StateMoveUpGoingRight;
	static const SpiderMoveDownGoingLeft StateMoveDownGoingLeft;
	static const SpiderMoveDownGoingRight StateMoveDownGoingRight;

};

#endif _SpiderMoveFSM