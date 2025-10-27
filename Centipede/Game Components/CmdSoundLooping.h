#ifndef _CmdSoundLooping
#define _CmdSoundLooping

#include "CmdSound.h"

class CmdSoundLooping : public CmdSound
{
public:
	CmdSoundLooping(sf::SoundBuffer& _sound);
	CmdSoundLooping() = delete;
	CmdSoundLooping(const CmdSoundLooping&) = delete;
	CmdSoundLooping& operator=(const CmdSoundLooping&) = delete;
	virtual ~CmdSoundLooping() = default;

	virtual void Execute() override;
};

#endif _CmdSoundLooping