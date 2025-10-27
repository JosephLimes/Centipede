#ifndef _ExplosionBig
#define _ExplosionBig

#include "TEAL\CommonElements.h"

class ExplosionBig : public GameObject
{
public:
	ExplosionBig() = default;
	ExplosionBig(const ExplosionBig&) = delete;
	ExplosionBig& operator=(const ExplosionBig&) = delete;
	~ExplosionBig() = default;

	void Initialize(sf::Vector2f pos);

	virtual void Update();
	virtual void Draw();

private:
	AnimatedSprite MainSprite;
};


#endif _ExplosionBig