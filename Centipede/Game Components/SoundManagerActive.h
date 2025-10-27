#ifndef _SoundManagerActive
#define _SoundManagerActive

#include "SoundManager.h"

class SoundManagerActive : public SoundManager
{
public:
	SoundManagerActive() = default;
	SoundManagerActive(const SoundManagerActive&) = delete;
	SoundManagerActive& operator=(const SoundManagerActive&) = delete;
	~SoundManagerActive() = default;

	virtual void SendSoundCmd(CmdSound* c);
};

#endif _SoundManagerActive