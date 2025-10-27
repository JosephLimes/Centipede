#ifndef _Scorpion
#define _Scorpion

#include "TEAL\CommonElements.h"

//Forward declarations
class Mushroom;
class CmdScore;
class ScorpionSpawner;
class ScorpionController;

enum ScorpionDirection
{
	LEFT,
	RIGHT
};

class Scorpion : public GameObject
{
public:
	Scorpion();
	Scorpion(const Scorpion&) = delete;
	Scorpion& operator=(const Scorpion&) = delete;
	~Scorpion() = default;

	void Initialize(sf::Vector2f pos, ScorpionSpawner* _pSpawner, ScorpionDirection direction, int _SPEED);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void SetOrientation(float i, float j);
	void MoveLeft();
	void MoveRight();

	void TakeDamage();

	virtual void Collision(GameObject* other) {};
	virtual void Collision(Mushroom* other);

private:
	int SPEED;

	CmdScore* pDeath;
	ScorpionSpawner* pSpawner;
	ScorpionController* controller;

	sf::Vector2f Pos;

	AnimatedSprite MainSprite;
};

#endif _Scorpion