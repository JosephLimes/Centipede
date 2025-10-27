#ifndef _GameUpdater
#define _GameUpdater

#include "TEAL\CommonElements.h"\

class GameUpdater : public GameObject
{
public:
	GameUpdater() = default;
	GameUpdater(const GameUpdater&) = delete;
	GameUpdater& operator=(const GameUpdater&) = delete;
	~GameUpdater() = default;

	virtual void Update();
};

#endif _GameUpdater