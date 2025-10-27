#include "CmdSound.h"

CmdSound::CmdSound(sf::SoundBuffer& _sound)
{
	sound.setBuffer(_sound);
	sound.setVolume(volume);
}