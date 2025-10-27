#include "BlasterControllerAI.h"
#include "Blaster.h"

BlasterControllerAI::BlasterControllerAI()
	: BlasterController(), movingUp(true), movingLeft(true), moveUnitLength((ScreenWidth* TileSize) / horizontalSectionCount), frameMoveCount(moveUnitLength / 2)
{
}

void BlasterControllerAI::ProcessInputs()
{
	frameMoveCount += (int)blaster->getSpeed();
	if (frameMoveCount >= moveUnitLength) // change state
	{
		frameMoveCount -= moveUnitLength;
		if (movingLeft)
		{
			if (blaster->getPos().x - moveUnitLength < 0) movingLeft = false;
		}
		else
		{
			if (blaster->getPos().x + moveUnitLength > (ScreenWidth * TileSize)) movingLeft = true;
		}
		if (movingUp)
		{
			if (blaster->getPos().y - moveUnitLength < playerZoneHeight) movingUp = false;
		}
		else
		{
			if (blaster->getPos().y + moveUnitLength > (ScreenHeight * TileSize)) movingUp = true;
		}
	}

	// do movement and fire
	if (movingLeft) blaster->MoveLeft();
	else blaster->MoveRight();
	if (movingUp) blaster->MoveUp();
	else blaster->MoveDown();
	blaster->FireBullet();
}