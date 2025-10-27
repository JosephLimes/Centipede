#ifndef _SoundManagerMuted
#define _SoundManagerMuted

#include "SoundManager.h"

class SoundManagerMuted : public SoundManager
{
public:
	SoundManagerMuted() = default;
	SoundManagerMuted(const SoundManagerMuted&) = delete;
	SoundManagerMuted& operator=(const SoundManagerMuted&) = delete;
	~SoundManagerMuted() = default;

	virtual void SendSoundCmd(CmdSound* c);
};

#endif _SoundManagerMuted