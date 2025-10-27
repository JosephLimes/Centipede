#ifndef _HUD
#define _HUD

#include "TEAL/CommonElements.h"
#include <list>
#include "HUDFont.h"
#include "GlyphStringLA.h"
#include "GlyphStringRA.h"

class HUD : public GameObject
{
public:
	HUD() = default;
	HUD(const HUD&) = delete;
	HUD& operator=(const HUD&) = delete;
	~HUD() = default;

	void updateScore(int s);
	void updateLives(int l);
	void Initialize();

	virtual void Draw();
	virtual void Destroy();

private:
	GlyphString* currScore;
	GlyphString* lives;
	GlyphString* highScore;
};


#endif _SimpleTextDemo