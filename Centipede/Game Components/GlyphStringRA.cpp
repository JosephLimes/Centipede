#include "GlyphStringRA.h"

GlyphStringRA::GlyphStringRA(sf::Vector2f pos)
	: GlyphString(pos)
{
	defpos.x -= myfont.CellWidth();
	nextpos = defpos;
}

void GlyphStringRA::UpdateString(std::string str)
{
	nextpos.x = defpos.x - (myfont.CellWidth() * str.length()); // reset position as we remake string
	glyphList.clear();
	for (size_t i = 0; i < str.length(); i++)
	{
		glyphList.push_back(myfont.GetGlyph(str.at(i), nextpos));
		nextpos.x += myfont.CellWidth();
	}
}