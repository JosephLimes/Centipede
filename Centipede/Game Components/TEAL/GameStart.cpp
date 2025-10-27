#include "Game.h"
#include "CommonElements.h"

void Game::GameStart()
{
	WindowManager::SetWindowSize(ScreenWidth * TileSize, ScreenHeight * TileSize);
	WindowManager::SetCaptionName("Centipede");
}
