#ifndef _BlasterControllerAI
#define _BlasterControllerAI

#include "TEAL\CommonElements.h"
#include "BlasterController.h"

const int horizontalSectionCount = 8; // amount of zigzags blaster will do per screen width

class BlasterControllerAI : public BlasterController
{
public:
	BlasterControllerAI();
	BlasterControllerAI(const BlasterControllerAI&) = delete;
	BlasterControllerAI& operator=(const BlasterControllerAI&) = delete;
	~BlasterControllerAI() = default;

	virtual void ProcessInputs();
private:
	bool movingUp;
	bool movingLeft;
	int moveUnitLength;
	int frameMoveCount;
};

#endif _BlasterControllerAI