#ifndef _Flea
#define _Flea

#include "TEAL\CommonElements.h"

//Forward declarations
class Blaster;
class CmdScore;
class FleaSpawner;

class Flea : public GameObject
{
public:
	Flea();
	Flea(const Flea&) = delete;
	Flea& operator=(const Flea&) = delete;
	~Flea() = default;

	void Initialize(sf::Vector2f pos, FleaSpawner* _pSpawner, int _SPEED, int _mushroomChance);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void TakeDamage();

	virtual void Collision(GameObject* other) {};
	virtual void Collision(Blaster* other);

private:
	int SPEED; // keep this divisible into 16 to keep mushroom spawning clean
	bool ENRAGED;
	int frameMoveCount;
	int mushroomChance;

	CmdScore* pDeath;
	FleaSpawner* pSpawner;

	sf::Vector2f Pos;

	AnimatedSprite MainSprite;
};

#endif _Flea