#ifndef _Blaster
#define _Blaster

#include "TEAL\CommonElements.h"

// Forward declarations
class Mushroom;
class CmdSound;
class BlasterController;
class EnemyManager;

class Blaster : public GameObject
{
public:
	Blaster() = delete;
	Blaster(BlasterController* b);
	Blaster(const Blaster&) = delete;
	Blaster& operator=(const Blaster&) = delete;
	~Blaster() = default;

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void FireBullet();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	sf::Vector2f getPos();
	float getSpeed();
	void setSpeed(float speed);
	void setBulletActive(bool val);
	void TakeDamage();
	
	virtual void Collision( GameObject *other ){};
	virtual void Collision(Mushroom* other);

private:
	float SPEED;
	bool bulletActive;

	BlasterController* controller;

	sf::Vector2f PrevPos; // for mushroom collision
	sf::Vector2f Pos;

	sf::Sprite MainSprite;
};

#endif _Blaster