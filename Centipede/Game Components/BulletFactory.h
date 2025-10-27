#ifndef _BulletFactory
#define _BulletFactory

#include "TEAL\CommonElements.h"
#include "BulletObjectPool.h"

// Forward declarations
class Blaster;
class CmdSound;

class BulletFactory
{
private:
	static BulletFactory* ptrInstance;

	BulletFactory();
	BulletFactory(const BulletFactory&) = delete;
	BulletFactory& operator=(const BulletFactory&) = delete;
	~BulletFactory();

	static BulletFactory& Instance()
	{
		if (ptrInstance == nullptr)
		{
			ptrInstance = new BulletFactory;
		}
		return *ptrInstance;
	};

	BulletObjectPool BulletPool;
	std::vector<Bullet*> ActiveBullets;
	CmdSound* pSpawn;

	void privCreateBullet(sf::Vector2f pos, Blaster* pBlaster);
	void privRecycleBullet(GameObject* b);
	void privRecall();

public:
	static void CreateBullet(sf::Vector2f pos, Blaster* pBlaster) { Instance().privCreateBullet(pos, pBlaster); };
	static void RecycleBullet(GameObject* b) { Instance().privRecycleBullet(b); };
	static void Recall() { Instance().privRecall(); };

	static void Terminate();
};

#endif _BulletFactory