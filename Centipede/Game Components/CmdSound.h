#ifndef _CmdSound
#define _CmdSound

#include "TEAL\CommonElements.h"

class CmdSound
{
public:
	CmdSound(sf::SoundBuffer& _sound);
	CmdSound() = delete;
	CmdSound(const CmdSound&) = delete;
	CmdSound& operator=(const CmdSound&) = delete;
	virtual ~CmdSound() = default;

	virtual void Execute() = 0;

protected:
	sf::Sound sound;
	float volume = 5;
};

#endif _CmdSound