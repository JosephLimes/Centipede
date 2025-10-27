#ifndef _Level
#define _Level

#include "TEAL\CommonElements.h"

class Level : public Scene
{
public:
	Level() = default;
	Level(const Level&) = delete;
	Level& operator=(const Level&) = delete;
	~Level() = default;

	virtual void Initialize();
	virtual void Terminate();
};

#endif _Level