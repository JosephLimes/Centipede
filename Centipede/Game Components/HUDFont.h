#ifndef _HUDFont
#define _HUDFont

#include "SpriteSheet.h"

class HUDFont : public SpriteSheet
{
public:
	HUDFont();

	HUDFont(const HUDFont&) = delete;
	HUDFont& operator=(const HUDFont&) = delete;
	virtual ~HUDFont() = default;

private:
	virtual int CharToIndex( char& c ); 
};


#endif _HUDFont