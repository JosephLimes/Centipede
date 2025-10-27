#ifndef _AttractorUpdater
#define _AttractorUpdater

#include "TEAL\CommonElements.h"

class AttractorUpdater : public GameObject
{
public:
	AttractorUpdater();
	AttractorUpdater(const AttractorUpdater&) = delete;
	AttractorUpdater& operator=(const AttractorUpdater&) = delete;
	~AttractorUpdater() = default;

	virtual void Update();
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
};

#endif _AttractorUpdater