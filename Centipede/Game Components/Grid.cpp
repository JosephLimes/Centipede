#include "Grid.h"
#include "EnemyManager.h"
#include "Mushroom.h"
#include "MushroomFactory.h"

Grid::Grid()
	: field(), MushroomGenRate(2), MushroomsInPlayerZone(0), pEnemyManager(nullptr)
{
	// Populate the field
	for (int row = 1; row < ScreenHeight - 1; row++) // we dont generate mushrooms on top (over the hud) or bottom (unkillable by player)
	{
		for (int col = 0; col < ScreenWidth; col++)
		{
			if (rand() % 100 + 1 <= MushroomGenRate)
			{
				placeMushroom(sf::Vector2f((float)(col * TileSize), (float)(row * TileSize)));
			}
		}
	}
}

void Grid::setEnemyManager(EnemyManager* e) { pEnemyManager = e; }

void Grid::placeMushroom(sf::Vector2f pos)
{
	//ConsoleMsg::WriteLine("Placing mushroom.");

	int col = (int)pos.x / TileSize;
	int row = (int)pos.y / TileSize;

	if (!field[row][col] && row > 0 && row < ScreenHeight - 1) // don't spawn mushrooms on the top (over the hud) or bottom (unkillable by player), or if tile already occupied
	{
		Mushroom* mush = MushroomFactory::CreateMushroom(sf::Vector2f((float)(col * TileSize + (TileSize / 2)), (float)(row * TileSize + (TileSize / 2))));
		Tile* tile = new Tile();
		tile->mushroom = mush;
		field[row][col] = tile;
		if (row * TileSize + (TileSize / 2) >= playerZoneHeight) MushroomsInPlayerZone++;
	}
}

void Grid::placeText(sf::Vector2f pos)
{
	int col = (int)pos.x / TileSize;
	int row = (int)pos.y / TileSize;

	if (field[row][col]) // update existing tile, remove its mushroom
	{
		if (field[row][col]->mushroom)
		{
			field[row][col]->mushroom->MarkForDestroy();
			field[row][col]->mushroom = nullptr;
			if (row * TileSize + (TileSize / 2) >= playerZoneHeight)
			{
				MushroomsInPlayerZone--;
				pEnemyManager->fleaSpawnFlagCheck();
			}
		}
	}
	else // spot is free, make new tile
	{
		Tile* tile = new Tile();
		tile->mushroom = nullptr;
		field[row][col] = tile;
	}

}

void Grid::removeMushroom(sf::Vector2f pos)
{
	int col = (int)pos.x / TileSize;
	int row = (int)pos.y / TileSize;
	if (field[row][col])
	{
		field[row][col]->mushroom->MarkForDestroy();
		delete field[row][col]; // make recylce later
		field[row][col] = nullptr;
		if (row * TileSize + (TileSize / 2) >= playerZoneHeight)
		{
			MushroomsInPlayerZone--;
			pEnemyManager->fleaSpawnFlagCheck();
		}
	}
}

Grid::Tile* Grid::getTile(sf::Vector2f pos)
{
	int col = (int)pos.x / TileSize;
	int row = (int)pos.y / TileSize;
	return field[row][col];
}

TileState Grid::getTileState(sf::Vector2f pos)
{
	if (pos.x < 0 || pos.x > ScreenWidth * TileSize) return OFFSIDE;
	if (pos.y < 0 || pos.y > ScreenHeight * TileSize) return OFFBOTTOM;
	Tile* t = getTile(pos);
	if (t)
	{
		if (t->mushroom)
		{
			if (t->mushroom->IsPoisoned()) return POISONED;
			else return MUSHROOM;
		}
		else return TEXT;
	}
	return FREE;
}

void Grid::clearPlayerSpawn()
{
	// clear 4x4 space around the player spawn
	sf::Vector2f spawn = sf::Vector2f(WindowManager::Window().getView().getSize().x / 2.0f, (WindowManager::Window().getView().getSize().y - playerZoneHeight) / 2.0f + playerZoneHeight);
	removeMushroom(sf::Vector2f(spawn.x - (float)(TileSize / 2), spawn.y));
	removeMushroom(sf::Vector2f(spawn.x - (float)(TileSize / 2), spawn.y - (float)(TileSize / 2)));
	removeMushroom(sf::Vector2f(spawn.x + (float)(TileSize / 2), spawn.y));
	removeMushroom(sf::Vector2f(spawn.x + (float)(TileSize / 2), spawn.y - (float)(TileSize / 2)));
}

int Grid::getMushroomsInPlayerZone() { return MushroomsInPlayerZone; }

void Grid::regenerateField()
{
	for (int row = 0; row < ScreenHeight; row++)
	{
		for (int col = 0; col < ScreenWidth; col++)
		{
			if (field[row][col] && field[row][col]->mushroom) field[row][col]->mushroom->Heal();
		}
	}
}

void Grid::printGrid()
{
	for (int i = 0; i < ScreenWidth + 2; i++) Trace::out("-");
	Trace::out("\n");
	for (int row = 0; row < ScreenHeight; row++)
	{
		Trace::out("|");
		for (int col = 0; col < ScreenWidth; col++)
		{
			if (field[row][col])
			{
				if (field[row][col]->mushroom) Trace::out("*");
				else Trace::out("T");
			}
			else Trace::out("#");
		}
		Trace::out("|\n");
	}
	for (int i = 0; i < ScreenWidth + 2; i++) Trace::out("-");
	Trace::out("\n");
	//Trace::out("Grid Printed. Mushrooms in player zone: %d\n", MushroomsInPlayerZone);
	Trace::out("Grid Printed.");
}

Grid::~Grid()
{
	for (int i = 0; i < ScreenHeight; i++)
	{
		for (int k = 0; k < ScreenWidth; k++)
		{
			if (field[i][k]) delete field[i][k];
		}
	}
}