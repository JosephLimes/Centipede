#include "BlasterController.h"

BlasterController::BlasterController()
	: blaster(nullptr)
{
}

void BlasterController::SetBlaster(Blaster* b)
{
	blaster = b;
}