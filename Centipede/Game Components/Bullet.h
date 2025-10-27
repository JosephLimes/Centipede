#ifndef _Bullet
#define _Bullet

#include "TEAL\CommonElements.h"

//Forward declarations
class Blaster;
class CentipedeHead;
class CentipedeBody;
class Flea;
class Mushroom;
class Scorpion;
class Spider;

class Bullet : public GameObject
{
public:
	Bullet();
	Bullet(const Bullet&) = delete;
	Bullet& operator=(const Bullet&) = delete;
	~Bullet() = default;

	void Initialize(sf::Vector2f p, Blaster* pBlaster);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision( GameObject *go ){};
	virtual void Collision( CentipedeHead* other );
	virtual void Collision( CentipedeBody* other );
	virtual void Collision( Mushroom *other );
	virtual void Collision( Flea* other );
	virtual void Collision( Scorpion* other );
	virtual void Collision( Spider* other );

private:
	float SPEED;

	sf::Vector2f Pos;
	sf::Sprite MainSprite;
	Blaster* parentBlaster;
};

#endif _Bullet