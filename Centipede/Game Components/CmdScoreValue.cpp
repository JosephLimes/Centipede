#include "CmdScoreValue.h"
#include "ScoreManager.h"

CmdScoreValue::CmdScoreValue( int val)
	:  points(val)
{
	//Trace::out("Score Command created: Points = %i\n", val);
}

void CmdScoreValue::Execute()
{
	ScoreManager::AddScore(points);
}