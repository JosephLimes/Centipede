#include "SoundManagerActive.h"

void SoundManagerActive::SendSoundCmd(CmdSound* c)
{
	QueueCmds.push(c);
}