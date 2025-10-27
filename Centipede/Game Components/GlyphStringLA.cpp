#include "GlyphStringLA.h"
#include "GameManager.h"
#include "Grid.h"

GlyphStringLA::GlyphStringLA(sf::Vector2f pos)
	: GlyphString(pos)
{
}

void GlyphStringLA::UpdateString(std::string str)
{
	nextpos.x = defpos.x; // reset position as we remake string
	glyphList.clear();
	for (size_t i = 0; i < str.length(); i++)
	{
		glyphList.push_back(myfont.GetGlyph(str.at(i), nextpos));
		nextpos.x += myfont.CellWidth();
	}
}