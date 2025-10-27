#include "HighScoreEnterUpdater.h"
#include "GameManager.h"
#include "GlyphStringLA.h"
#include "GlyphStringRA.h"

HighScoreEnterUpdater::HighScoreEnterUpdater()
{
	RegisterInput(InputFlags::TextEntered);

	std::string gameOverStr = "GAME OVER";
	std::string congratsStr = "GREAT SCORE";
	std::string enterInitStr = "ENTER YOUR INITIALS";

	float midScreenX = (ScreenWidth * TileSize) / 2;
	float midScreenY = (ScreenHeight * TileSize) / 2;


	gameOverGS = new GlyphStringLA(sf::Vector2f(midScreenX - (gameOverStr.length() * TileSize / 2), midScreenY));
	gameOverGS->UpdateString(gameOverStr);

	congratsGS = new GlyphStringLA(sf::Vector2f(midScreenX - (congratsStr.length() * TileSize / 2), midScreenY + (TileSize * 3)));
	congratsGS->UpdateString(congratsStr);

	enterInitGS = new GlyphStringLA(sf::Vector2f(midScreenX - (enterInitStr.length() * TileSize / 2), midScreenY + (TileSize * 4)));
	enterInitGS->UpdateString(enterInitStr);

	initialsGS = new GlyphStringLA(sf::Vector2f(midScreenX - (initialsLength * TileSize / 2), midScreenY + (TileSize * 6)));
}

void HighScoreEnterUpdater::TextEntered(sf::Uint32 UnicodeValue)
{
	if (UnicodeValue == 8) // backspace
	{
		if (initials.length() > 0)
		{
			initials.erase(initials.length() - 1);
			initialsGS->UpdateString(initials);
		}
	}
	else if (UnicodeValue == 13 && initials.length() == initialsLength) // enter pressed, end only if length of 3
	{
		GameManager::highScoreEntered(initials);
	}
	else if (initials.length() < initialsLength) // add character, keep length at 3 or less
	{
		initials += (char)UnicodeValue;
		initialsGS->UpdateString(initials);
	}
}

void HighScoreEnterUpdater::Draw()
{
	gameOverGS->Draw();
	congratsGS->Draw();
	enterInitGS->Draw();
	initialsGS->Draw();
}

void HighScoreEnterUpdater::Destroy()
{
	delete gameOverGS;
	delete congratsGS;
	delete enterInitGS;
	delete initialsGS;
}