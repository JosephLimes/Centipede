#include "AttractorScore.h"
#include "GameManager.h"
#include "Grid.h"

AttractorScore::AttractorScore()
{
	float X = (ScreenWidth * TileSize) / 2; // midscreen
	float Y = TileSize * 3; // a few columns below top

	// create line one
	std::string text = "HIGH SCORES";
	GlyphStringLA* lineone = new GlyphStringLA(sf::Vector2f(X - (text.length() / 2 * TileSize), Y));
	lineone->UpdateString(text);
	GSlist.push_back(lineone);
	lineone->addToGrid(); // update grid for collision

	// create score lines
	for (int i = 0; i < highScoreListSize; i++)
	{
		ScoreSlot* scoreLine = GameManager::getHighScore(i);

		GlyphStringRA* initialsGS = new GlyphStringRA(sf::Vector2f(X, Y + (TileSize * (i + 2))));
		initialsGS->UpdateString(scoreLine->getInitials());

		GlyphStringLA* scoreGS = new GlyphStringLA(sf::Vector2f(X, Y + (TileSize * (i + 2))));
		scoreGS->UpdateString(std::to_string(scoreLine->getScore()));

		GSlist.push_back(initialsGS);
		GSlist.push_back(scoreGS);

		// update grid for collision
		initialsGS->addToGrid();
		scoreGS->addToGrid();
	}
}

void AttractorScore::Draw()
{
	std::list<GlyphString*>::iterator it;
	for (it = GSlist.begin(); it != GSlist.end(); it++)
		(*it)->Draw();
}

void AttractorScore::Destroy()
{
	std::list<GlyphString*>::iterator it;
	for (it = GSlist.begin(); it != GSlist.end(); it++)
		delete (*it);
}