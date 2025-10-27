#ifndef _FleaSpawner
#define _FleaSpawner

#include "TEAL\CommonElements.h"


class FleaSpawner
{
public:
	FleaSpawner();
	FleaSpawner(const FleaSpawner&) = delete;
	FleaSpawner& operator=(const FleaSpawner&) = delete;
	~FleaSpawner() = default;

	void spawn();
	void spawnConditional();
	void death();

	// setters for incoming wave data
	void setEnabled(bool val);
	void setSpeed(int val);
	void setMushroomThreshold(int val);
	void setMushroomChance(int val);

private:
	int fleaCount;

	// wave parameters
	bool enabled;
	int fleaSpeed;
	int fleaMushroomThreshold;
	int fleaMushroomChance;
};

#endif _FleaSpawner