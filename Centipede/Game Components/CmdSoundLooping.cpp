#include "CmdSoundLooping.h"

CmdSoundLooping::CmdSoundLooping(sf::SoundBuffer& _sound)
	: CmdSound(_sound)
{
	sound.setLoop(true);
}

void CmdSoundLooping::Execute()
{
	// Execute toggles playing
	if (sound.getStatus() != sound.Playing)
	{
		sound.play();
	}
	else
	{
		sound.stop();
	}
}