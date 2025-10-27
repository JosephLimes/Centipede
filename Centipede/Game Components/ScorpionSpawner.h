#ifndef _ScorpionSpawner
#define _ScorpionSpawner

#include "TEAL\CommonElements.h"

class ScorpionSpawner
{
public:
	ScorpionSpawner();
	ScorpionSpawner(const ScorpionSpawner&) = delete;
	ScorpionSpawner& operator=(const ScorpionSpawner&) = delete;
	~ScorpionSpawner() = default;

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
	int scorpionCount;

	// wave parameters
	bool enabled;
	int scorpionSpeed;
	float scorpionFrequency;
};

#endif _ScorpionSpawner