#ifndef _AttractorScore
#define _AttractorScore

#include "TEAL/CommonElements.h"
#include <list>

#include "HUDFont.h"
#include "ScoreSlot.h"
#include "GlyphStringLA.h"
#include "GlyphStringRA.h"

class AttractorScore : public GameObject
{
public:

	AttractorScore();
	AttractorScore(const AttractorScore&) = delete;
	AttractorScore& operator=(const AttractorScore&) = delete;
	~AttractorScore() = default;

	virtual void Draw();
	virtual void Destroy();

private:
	std::list<GlyphString*> GSlist;
	std::list<ScoreSlot> highScores;
};


#endif _SimpleTextDemo