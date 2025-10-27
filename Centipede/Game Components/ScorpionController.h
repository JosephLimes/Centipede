#ifndef _ScorpionController
#define _ScorpionController

#include "TEAL\CommonElements.h"

//forward declaration
class Scorpion;

class ScorpionController
{
public:
	ScorpionController(Scorpion* scorpion);
	ScorpionController() = delete;
	ScorpionController(const ScorpionController&) = delete;
	ScorpionController& operator=(const ScorpionController&) = delete;
	~ScorpionController() = default;

	virtual void SetOrientation() = 0;
	virtual void GetMovement() = 0;

protected:
	Scorpion* scorpion;
};

#endif _ScorpionController