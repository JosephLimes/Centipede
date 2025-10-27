#ifndef _ScorpionControllerRight
#define _ScorpionControllerRight

#include "TEAL\CommonElements.h"
#include "ScorpionController.h"

class ScorpionControllerRight : public ScorpionController
{
public:
	ScorpionControllerRight(Scorpion* scorpion);
	ScorpionControllerRight() = delete;
	ScorpionControllerRight(const ScorpionControllerRight&) = delete;
	ScorpionControllerRight& operator=(const ScorpionControllerRight&) = delete;
	~ScorpionControllerRight() = default;

	virtual void SetOrientation();
	virtual void GetMovement();
};

#endif _ScorpionControllerRight