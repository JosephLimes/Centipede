#ifndef _CmdSoundSingle
#define _CmdSoundSingle

#include "CmdSound.h"

class CmdSoundSingle : public CmdSound
{
public:
	CmdSoundSingle(sf::SoundBuffer& _sound);
	CmdSoundSingle() = delete;
	CmdSoundSingle(const CmdSoundSingle&) = delete;
	CmdSoundSingle& operator=(const CmdSoundSingle&) = delete;
	virtual ~CmdSoundSingle() = default;

	virtual void Execute() override;
};

#endif _CmdSoundSingle