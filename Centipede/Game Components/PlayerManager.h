#ifndef _PlayerManager
#define _PlayerManager

class EnemyManager;
class Player;

class PlayerManager
{
public:

	static void setCurrentPlayer(Player* p) { Instance().privSetCurrentPlayer(p); };

	static void playerDeath() { Instance().privPlayerDeath(); };

	static void createPlayerOne() { Instance().privCreatePlayerOne(); };
	static void createPlayerTwo() { Instance().privCreatePlayerTwo(); };
	static void createPlayerAI() { Instance().privCreatePlayerAI(); };

	static Player& CurrentPlayer();
	static Player* PlayerOne();
	static Player* PlayerTwo();
	static Player* PlayerAI();

	static void Terminate();

private:
	PlayerManager();
	PlayerManager(const PlayerManager&) = delete;
	PlayerManager& operator=(const PlayerManager&) = delete;
	~PlayerManager();

	static PlayerManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new PlayerManager;
		return *ptrInstance;
	};

	static PlayerManager* ptrInstance;

	Player* pCurrentPlayer;

	Player* pPlayerOne;
	Player* pPlayerTwo;
	Player* pPlayerAI;

	void privSetCurrentPlayer(Player* p);
	void privPlayerDeath();
	void privCreatePlayerOne();
	void privCreatePlayerTwo();
	void privCreatePlayerAI();
};

#endif _PlayerManager