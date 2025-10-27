#ifndef _CmdScoreByDistance
#define _CmdScoreByDistance

#include "CmdScore.h"

class CmdScoreByDistance : public CmdScore
{
private:
	int dNear;
	int dMed;
	int dFar;
	int vNear;
	int vMed;
	int vFar;

	sf::Vector2f deathPos;
	sf::Vector2f playerPos;

public:
	CmdScoreByDistance() = delete;
	CmdScoreByDistance(const CmdScoreByDistance&) = delete;
	CmdScoreByDistance& operator=(const CmdScoreByDistance&) = delete;
	virtual ~CmdScoreByDistance() = default;

	CmdScoreByDistance(int dNear, int dMed, int dFar,
					   int vNear, int vMed, int vFar);

	void setPositions(sf::Vector2f _deathPos, sf::Vector2f _playerPos);

	virtual void Execute() override;


};

#endif _CmdScoreByDistance