#ifndef _CentipedeSpawner
#define _CentipedeSpawner

#include "TEAL\CommonElements.h"


class CentipedeSpawner
{
public:
	CentipedeSpawner();
	CentipedeSpawner(const CentipedeSpawner&) = delete;
	CentipedeSpawner& operator=(const CentipedeSpawner&) = delete;
	~CentipedeSpawner() = default;

	void startWave();
	void spawn(int _length);

	int getSoloHeadCount();
	bool getSoloHeadEnabled();

	// setters for incoming wave data
	void setSoloHeadEnabled(bool val);
	void setSoloHeadCount(int val);
	void setSpeed(int val);
	void setLength(int val);

private:
	// wave parameters
	bool soloHeadEnabled;
	int soloHeadCount;
	int speed;
	int length;
};

#endif _CentipedeSpawner