#include "SoundManager.h"
#include "CmdSound.h"
#include "CmdSoundLooping.h"
#include "CmdSoundSingle.h"

void SoundManager::ProcessSounds()
{
	CmdSound* c;

	if (!QueueCmds.empty())
	{
		while (!QueueCmds.empty())
		{
			c = QueueCmds.front();

			c->Execute();

			QueueCmds.pop();
		}
	}
}

void SoundManager::ClearCommands()
{
	while (!QueueCmds.empty())
	{
		QueueCmds.pop();
	}
}