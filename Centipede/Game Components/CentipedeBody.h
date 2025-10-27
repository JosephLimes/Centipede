#ifndef _CentipedeBody
#define _CentipedeBody

#include "CentipedeSegment.h"

// Forward declarations
class Blaster;
class MoveState;

class CentipedeBody : public CentipedeSegment
{
public:
	CentipedeBody();
	CentipedeBody(const CentipedeBody&) = delete;
	CentipedeBody& operator=(const CentipedeBody&) = delete;
	~CentipedeBody() = default;

	void Initialize(CentipedeSegment* _pNext);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void TakeDamage();

	virtual void Collision(GameObject* other) {};
	virtual void Collision(Blaster* other);

private:

};

#endif _CentipedeBody