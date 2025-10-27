#ifndef _ExplosionSmall
#define _ExplosionSmall

#include "TEAL\CommonElements.h"

class ExplosionSmall : public GameObject
{
public:
	ExplosionSmall() = default;
	ExplosionSmall(const ExplosionSmall&) = delete;
	ExplosionSmall& operator=(const ExplosionSmall&) = delete;
	~ExplosionSmall() = default;

	void Initialize(sf::Vector2f pos);
	virtual void Update();
	virtual void Draw();

private:
	AnimatedSprite MainSprite;
};


#endif _ExplosionSmall