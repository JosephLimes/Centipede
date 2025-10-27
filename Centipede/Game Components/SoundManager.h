#ifndef _SoundManager
#define _SoundManager

#include "TEAL\CommonElements.h"
#include <queue>

class CmdSound;

class SoundManager
{
public:
	SoundManager() = default;
	SoundManager(const SoundManager&) = delete;
	SoundManager& operator=(const SoundManager&) = delete;
	~SoundManager() = default;

	virtual void SendSoundCmd(CmdSound* c) = 0;
	void ProcessSounds();
	void ClearCommands();

protected:
	std::queue<CmdSound*> QueueCmds;
};

#endif _SoundManager