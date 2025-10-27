#ifndef _GlyphStringLA
#define _GlyphStringLA

#include "GlyphString.h"

// LEFT-ALLIGNED glyph strings

class GlyphStringLA : public GlyphString
{
private:
	//virtual sf::Vector2f getNextPos();

public:
	GlyphStringLA(sf::Vector2f pos);
	GlyphStringLA() = delete;
	GlyphStringLA(const GlyphStringLA&) = delete;
	GlyphStringLA& operator = (const GlyphStringLA&) = delete;
	~GlyphStringLA() = default;

	virtual void GlyphStringLA::UpdateString(std::string str);
};


#endif _GlyphStringLA