#include "ScorpionControllerLeft.h"
#include "Scorpion.h"

ScorpionControllerLeft::ScorpionControllerLeft(Scorpion* scorpion)
	: ScorpionController(scorpion)
{

}

void ScorpionControllerLeft::SetOrientation()
{
	scorpion->SetOrientation(1.0f, 1.0f);
}

void ScorpionControllerLeft::GetMovement()
{
	scorpion->MoveLeft();
}