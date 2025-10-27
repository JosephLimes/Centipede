#ifndef _MoveState
#define _MoveState

#include "TEAL\CommonElements.h"

class MoveState
{
public:
	MoveState() = default;
	MoveState(const MoveState&) = delete;
	MoveState& operator = (const MoveState&) = delete;
	~MoveState() = default;

	const sf::Vector2f GetMoveOffsets(int frame) const;
	const float GetRotation(int frame) const;
	virtual const MoveState* GetNextState(sf::Vector2f pos) const = 0;

protected:
	sf::Vector2f MyMoveOffsets[TileSize];
	float MyRotations[TileSize];
};

#endif _MoveState