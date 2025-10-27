#include "ScorpionControllerRight.h"
#include "Scorpion.h"

ScorpionControllerRight::ScorpionControllerRight(Scorpion* scorpion)
	: ScorpionController(scorpion)
{

}

void ScorpionControllerRight::SetOrientation()
{
	scorpion->SetOrientation(-1.0f, 1.0f);
}

void ScorpionControllerRight::GetMovement()
{
	scorpion->MoveRight();
}