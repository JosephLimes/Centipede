#ifndef _BlasterController
#define _BlasterController

#include "TEAL\CommonElements.h"

//forward declaration
class Blaster;

class BlasterController
{
public:
	BlasterController();
	BlasterController(const BlasterController&) = delete;
	BlasterController& operator=(const BlasterController&) = delete;
	~BlasterController() = default;

	void SetBlaster(Blaster* b);
	virtual void ProcessInputs() = 0;

protected:
	Blaster* blaster;
};

#endif _BlasterController