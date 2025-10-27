#ifndef _HighScoreEnter
#define _HighScoreEnter

#include "TEAL\CommonElements.h"

class HighScoreEnter : public Scene
{
public:
	HighScoreEnter() = default;
	HighScoreEnter(const HighScoreEnter&) = delete;
	HighScoreEnter& operator=(const HighScoreEnter&) = delete;
	~HighScoreEnter() = default;

	virtual void Initialize();
};

#endif _HighScoreEnter