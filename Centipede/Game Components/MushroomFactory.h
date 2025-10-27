#ifndef _MushroomFactory
#define _MushroomFactory

#include "TEAL\CommonElements.h"
#include "MushroomObjectPool.h"


class MushroomFactory
{
private:
	static MushroomFactory* ptrInstance;

	MushroomFactory() = default;
	MushroomFactory(const MushroomFactory&) = delete;
	MushroomFactory& operator=(const MushroomFactory&) = delete;
	~MushroomFactory() = default;

	static MushroomFactory& Instance()
	{
		if (ptrInstance == nullptr)
		{
			ptrInstance = new MushroomFactory;
		}
		return *ptrInstance;
	};

	MushroomObjectPool MushroomPool;

	Mushroom* privCreateMushroom(sf::Vector2f pos);
	void privRecycleMushroom(GameObject* m);

public:
	static Mushroom* CreateMushroom(sf::Vector2f pos) { return Instance().privCreateMushroom(pos); };
	static void RecycleMushroom(GameObject* m) { Instance().privRecycleMushroom(m); };

	static void Terminate();
};

#endif _MushroomFactory