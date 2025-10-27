#ifndef _CentipedeHead
#define _CentipedeHead

#include "CentipedeSegment.h"

//Forward Declarations
class Blaster;
class CentipedeBody;
class MoveState;

class CentipedeHead : public CentipedeSegment
{
public:
	CentipedeHead();
	CentipedeHead(const CentipedeHead&) = delete;
	CentipedeHead& operator=(const CentipedeHead&) = delete;
	~CentipedeHead() = default;

	void Initialize(sf::Vector2f pos, int _SPEED);
	void Initialize(CentipedeSegment* prev);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void TakeDamage();

	virtual void Collision(GameObject* other) {};
	virtual void Collision(Blaster* other);

private:
	
};

#endif _CentipedeHead