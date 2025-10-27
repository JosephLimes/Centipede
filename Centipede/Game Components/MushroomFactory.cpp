#include "MushroomFactory.h"
#include "MushroomObjectPool.h"
#include "Mushroom.h"

MushroomFactory* MushroomFactory::ptrInstance = nullptr;

Mushroom* MushroomFactory::privCreateMushroom(sf::Vector2f pos)
{
	Mushroom* m = MushroomPool.GetMushroom();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	m->SetExternalManagement(RecycleMushroom);

	m->Initialize(pos);

	return m;
}

void MushroomFactory::privRecycleMushroom(GameObject* m)
{
	MushroomPool.ReturnMushroom(static_cast<Mushroom*>(m));
}

void MushroomFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
