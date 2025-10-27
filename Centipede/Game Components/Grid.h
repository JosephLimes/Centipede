#ifndef _Grid
#define _Grid

#include "TEAL\CommonElements.h"

//Forward declarations
class EnemyManager;
class Mushroom;

enum TileState // for centipede head querying
{
	FREE,
	MUSHROOM,
	TEXT,
	POISONED,
	OFFBOTTOM,
	OFFSIDE
};

class Grid
{
public:
	class Tile
	{
	public:
		Tile() = default;
		Tile(const Tile&) = delete;
		Tile& operator=(const Tile&) = delete;
		~Tile() = default;

		Mushroom* mushroom;
	};

	Grid();
	Grid(const Grid&) = delete;
	Grid& operator=(const Grid&) = delete;
	~Grid();

	void setEnemyManager(EnemyManager* e);

	void placeMushroom(sf::Vector2f pos);
	void placeText(sf::Vector2f pos);
	void removeMushroom(sf::Vector2f pos);
	Tile* getTile(sf::Vector2f pos);
	TileState getTileState(sf::Vector2f pos);
	void clearPlayerSpawn();
	int getMushroomsInPlayerZone();
	void regenerateField();

	void printGrid(); // for debugging purposes
private:

	Tile* field[ScreenHeight][ScreenWidth];
	EnemyManager* pEnemyManager;
	int MushroomGenRate; // % chance to spawn mushroom on every tile
	int MushroomsInPlayerZone; // counter that tracks mushrooms in player zone
};

#endif _Grid