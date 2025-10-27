#ifndef _CentipedeSegment
#define _CentipedeSegment

#include "TEAL\CommonElements.h"

// Forward declarations
class MoveState;
class CmdScore;

class CentipedeSegment : public GameObject
{
public:
	CentipedeSegment() = default;
	CentipedeSegment(const CentipedeSegment&) = delete;
	CentipedeSegment& operator=(const CentipedeSegment&) = delete;
	~CentipedeSegment() = default;

	virtual void TakeDamage() = 0;

	const MoveState* GetPrevState();
	const MoveState* GetCurrentState();
	const sf::Vector2f GetBasePos();
	const sf::Vector2f GetPos();
	CentipedeSegment* GetPrev();
	int GetSpeed();
	void SetPrev(CentipedeSegment* prev);
	void SetNext(CentipedeSegment* pNext);
	int GetFrameMoveCount();

protected:
	int SPEED;
	int frameMoveCount;
	CmdScore* pDeath;

	// Current state
	const MoveState* pCurrentState;
	// Previous state to inform segment behind us
	const MoveState* pPrevState;

	// Segment behind us
	CentipedeSegment* pPrev;
	CentipedeSegment* pNext;

	// Center of cell for calculating movement
	sf::Vector2f basePos;
	// Actual position
	sf::Vector2f Pos;

	AnimatedSprite MainSprite;
};

#endif _CentipedeSegment