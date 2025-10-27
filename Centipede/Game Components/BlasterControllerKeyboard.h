#ifndef _BlasterControllerKeyboard
#define _BlasterControllerKeyboard

#include "TEAL\CommonElements.h"
#include "BlasterController.h"

class BlasterControllerKeyboard : public BlasterController
{
public:
	BlasterControllerKeyboard();
	BlasterControllerKeyboard(const BlasterControllerKeyboard&) = delete;
	BlasterControllerKeyboard& operator=(const BlasterControllerKeyboard&) = delete;
	~BlasterControllerKeyboard() = default;

	virtual void ProcessInputs();
};

#endif _BlasterControllerKeyboard