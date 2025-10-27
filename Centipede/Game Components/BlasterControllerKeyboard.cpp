#include "BlasterControllerKeyboard.h"
#include "Blaster.h"

BlasterControllerKeyboard::BlasterControllerKeyboard()
	: BlasterController()
{}

void BlasterControllerKeyboard::ProcessInputs()
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left)) blaster->MoveLeft();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right)) blaster->MoveRight();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up)) blaster->MoveUp();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down)) blaster->MoveDown();
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) blaster->FireBullet();
}