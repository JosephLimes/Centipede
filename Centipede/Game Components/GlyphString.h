#ifndef _GlyphString
#define _GlyphString

#include "TEAL/CommonElements.h"
#include <list>
#include "HUDFont.h"

// forward declarations
class SpriteSheet;
class Glyph;

class GlyphString
{
protected:
	HUDFont myfont;
	sf::Vector2f defpos;
	sf::Vector2f nextpos;
	std::list<Glyph> glyphList;

public:
	GlyphString(sf::Vector2f pos);
	GlyphString() = delete;
	GlyphString(const GlyphString&) = delete;
	GlyphString& operator = (const GlyphString&) = delete;
	~GlyphString() = default;

	virtual void UpdateString(std::string str) = 0;
	void addToGrid();
	void Draw();
};


#endif _GlyphString