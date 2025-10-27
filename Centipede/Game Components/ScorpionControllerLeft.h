#ifndef _ScorpionControllerLeft
#define _ScorpionControllerLeft

#include "TEAL\CommonElements.h"
#include "ScorpionController.h"

class ScorpionControllerLeft : public ScorpionController
{
public:
	ScorpionControllerLeft(Scorpion* scorpion);
	ScorpionControllerLeft() = delete;
	ScorpionControllerLeft(const ScorpionControllerLeft&) = delete;
	ScorpionControllerLeft& operator=(const ScorpionControllerLeft&) = delete;
	~ScorpionControllerLeft() = default;

	virtual void SetOrientation();
	virtual void GetMovement();
};

#endif _ScorpionControllerLeft