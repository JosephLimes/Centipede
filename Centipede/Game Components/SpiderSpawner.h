#ifndef _SpiderSpawner
#define _SpiderSpawner

#include "TEAL\CommonElements.h"

class SpiderSpawner
{
public:
	SpiderSpawner();
	SpiderSpawner(const SpiderSpawner&) = delete;
	SpiderSpawner& operator=(const SpiderSpawner&) = delete;
	~SpiderSpawner() = default;

	void spawn();
	void death();

	int count();
	bool isEnabled();
	float frequency();

	// setters for incoming wave data
	void setEnabled(bool val);
	void setSpeed(int val);
	void setFrequency(float val);

private:
	int spiderCount;

	// wave parameters
	bool enabled;
	int spiderSpeed;
	float spiderFrequency;
};

#endif _SpiderSpawner