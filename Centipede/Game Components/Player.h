#ifndef _Player
#define _Player

class Blaster;
class BlasterController;
class EnemyManager;

class Player
{
public:
	Player(BlasterController* b, bool AI);
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	~Player() = default;

	void addScore(int val);
	int getScore();
	int getLives();
	void loseLife();
	Blaster* getBlaster();

private:
	bool AI;
	BlasterController* controller;
	Blaster* blaster;
	int score;
	int lives;
	int currentWave;
	// could add: grid data field for 2P mode
};

#endif _Player