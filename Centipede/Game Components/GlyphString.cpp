#include "GlyphString.h"
#include "GameManager.h"
#include "Grid.h"

GlyphString::GlyphString(sf::Vector2f pos)
	: defpos(pos), nextpos(pos)
{
	
}

void GlyphString::addToGrid()
{
	std::list<Glyph>::iterator it;
	for (it = glyphList.begin(); it != glyphList.end(); it++)
		GameManager::currGrid().placeText(it->getPos());
}

void GlyphString::Draw()
{
	std::list<Glyph>::iterator it;
	for (it = glyphList.begin(); it != glyphList.end(); it++)
		it->Draw();
}