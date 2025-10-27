#include "CmdSoundSingle.h"

CmdSoundSingle::CmdSoundSingle(sf::SoundBuffer& _sound)
	: CmdSound(_sound)
{}

void CmdSoundSingle::Execute()
{
	sound.play();
}