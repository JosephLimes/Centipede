#ifndef _GlyphStringRA
#define _GlyphStringRA

#include "GlyphString.h"

// RIGHT-ALLIGNED glyph strings

class GlyphStringRA : public GlyphString
{
public:
	GlyphStringRA(sf::Vector2f pos);
	GlyphStringRA() = delete;
	GlyphStringRA(const GlyphStringRA&) = delete;
	GlyphStringRA& operator = (const GlyphStringRA&) = delete;
	~GlyphStringRA() = default;

	virtual void GlyphStringRA::UpdateString(std::string str);
};


#endif _GlyphStringRA