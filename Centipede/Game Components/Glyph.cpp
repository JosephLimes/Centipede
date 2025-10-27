#include "Glyph.h"
#include "SpriteSheet.h"
#include "TEAL\ResourceManager.h"
//#include <assert.h>

#include "GameManager.h"
#include "Grid.h"

Glyph::Glyph()
	: sprsheet(nullptr), cellIndex(0), position(sf::Vector2f(0, 0))
{
}

Glyph::Glyph( SpriteSheet* sheet, int cellInd, sf::Vector2f pos )
	: sprsheet(sheet), cellIndex(cellInd), position(pos)
{
	//GameManager::currGrid().placeText(pos); // fix later, causing crashes
}

sf::Vector2f Glyph::getPos()
{
	return position;
}

void Glyph::Draw()
{
	sprsheet->Draw(cellIndex, position);
}
