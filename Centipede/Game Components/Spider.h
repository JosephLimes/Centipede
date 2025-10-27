#ifndef _Spider
#define _Spider

#include "TEAL\CommonElements.h"

//Forward declarations
class Blaster;
class Mushroom;
class CmdScore;
class SpiderSpawner;
class SpiderMoveState;

class Spider : public GameObject
{
public:
	Spider();
	Spider(const Spider&) = delete;
	Spider& operator=(const Spider&) = delete;
	~Spider() = default;

	void Initialize(sf::Vector2f pos, SpiderSpawner* _pSpawner, int _SPEED);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void MoveUpLeft();
	void MoveUpRight();
	void MoveDownLeft();
	void MoveDownRight();
	void MoveUp();
	void MoveDown();

	void TakeDamage(sf::Vector2f playerPos);

	virtual void Collision(GameObject* other) {};
	virtual void Collision(Mushroom* other);
	virtual void Collision(Blaster* other);
	const static int MoveUnitLength = (ScreenWidth * TileSize) / 6; // horizontal size of section the spider can move over at one time

private:
	int SPEED;

	int frameMoveCount;

	CmdScore* pDeath;
	SpiderSpawner* pSpawner;
	const SpiderMoveState* pCurrentState;

	sf::Vector2f Pos;

	AnimatedSprite MainSprite;
};

#endif _Spider