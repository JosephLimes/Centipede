#include "CentipedeSegment.h"

const MoveState* CentipedeSegment::GetPrevState()
{
	return pPrevState;
}

const MoveState* CentipedeSegment::GetCurrentState()
{
	return pCurrentState;
}

const sf::Vector2f CentipedeSegment::GetBasePos()
{
	return basePos;
}

const sf::Vector2f CentipedeSegment::GetPos()
{
	return Pos;
}

CentipedeSegment* CentipedeSegment::GetPrev()
{
	return pPrev;
}

int CentipedeSegment::GetSpeed()
{
	return SPEED;
}

void CentipedeSegment::SetPrev(CentipedeSegment* prev)
{
	pPrev = prev;
}

void CentipedeSegment::SetNext(CentipedeSegment* next)
{
	pNext = next;
}

int CentipedeSegment::GetFrameMoveCount()
{
	return frameMoveCount;
}