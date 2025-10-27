#include "HUD.h"
#include "GlyphStringLA.h"
#include "GameManager.h"

void HUD::Initialize()
{
	// set up current score string
	currScore = new GlyphStringRA(sf::Vector2f(TileSize * 7, 0));
	currScore->UpdateString("0");

	// set up current lives string
	lives = new GlyphStringLA(sf::Vector2f(TileSize * 7, 0));
	lives->UpdateString("**"); // * maps to life symbol

	// set up high score string
	highScore = new GlyphStringLA(sf::Vector2f((TileSize * ScreenWidth) / 2 - (TileSize * 2), 0));
	highScore->UpdateString(std::to_string(GameManager::getHighScore(0)->getScore()));
}

void HUD::updateScore(int s)
{
	currScore->UpdateString(std::to_string(s));
}

void HUD::updateLives(int l)
{
	std::string newLives;
	for (int i = 0; i < l - 1; i++) newLives += "*";

	lives->UpdateString(newLives);
}

void HUD::Draw()
{
	currScore->Draw();
	lives->Draw();
	highScore->Draw();
}

void HUD::Destroy()
{
	delete currScore;
	delete lives;
	delete highScore;
}