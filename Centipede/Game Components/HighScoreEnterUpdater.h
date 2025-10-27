#ifndef _HighScoreEnterUpdater
#define _HighScoreEnterUpdater

#include "TEAL\CommonElements.h"

class GlyphString;
const int initialsLength = 3;

class HighScoreEnterUpdater : public GameObject
{
public:
	HighScoreEnterUpdater();
	HighScoreEnterUpdater(const HighScoreEnterUpdater&) = delete;
	HighScoreEnterUpdater& operator=(const HighScoreEnterUpdater&) = delete;
	~HighScoreEnterUpdater() = default;

	virtual void TextEntered(sf::Uint32 UnicodeValue);
	virtual void Draw();
	virtual void Destroy();

private:
	// strings to display game over messages
	GlyphString* gameOverGS;
	GlyphString* congratsGS;
	GlyphString* enterInitGS;

	// player input
	std::string initials;
	GlyphString* initialsGS;
};

#endif _HighScoreEnterUpdater