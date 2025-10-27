#ifndef _Mushroom
#define _Mushroom

#include "TEAL\CommonElements.h"

class CmdScore;

class Mushroom : public GameObject
{
public:
	Mushroom();
	Mushroom(const Mushroom&) = delete;
	Mushroom& operator=(const Mushroom&) = delete;
	~Mushroom() = default;

	void Initialize(sf::Vector2f pos);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void Poison();
	bool IsPoisoned();
	void TakeDamage();
	void GetEaten();
	void Heal();

private:
	CmdScore* pDeath;
	bool Poisoned;
	AnimatedSprite MainSprite;
	sf::Vector2f Pos;
	int Damage;
};

#endif _Mushroom