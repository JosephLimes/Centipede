#include "CmdScoreByDistance.h"
#include "ExplosionSpiderFactory.h"
#include "ScoreManager.h"

CmdScoreByDistance::CmdScoreByDistance(int dn, int dm, int df,
									   int vn, int vm, int vf)
	: dNear(dn), dMed(dm), dFar(df), vNear(vn), vMed(vm), vFar(vf)
{
}

void CmdScoreByDistance::setPositions(sf::Vector2f _deathPos, sf::Vector2f _playerPos)
{
	deathPos = _deathPos;
	playerPos = _playerPos;
}

void CmdScoreByDistance::Execute()
{
	float dist = deathPos.y - playerPos.y;
	if (dist < 0) dist *= -1;

	if (dist <= dNear)
	{
		ExplosionSpiderFactory::CreateExplosionSpider(deathPos, exNear);
		ScoreManager::AddScore(vNear);
	}
	else if (dist <= dMed)
	{
		ExplosionSpiderFactory::CreateExplosionSpider(deathPos, exMed);
		ScoreManager::AddScore(vMed);
	}
	else
	{
		ExplosionSpiderFactory::CreateExplosionSpider(deathPos, exFar);
		ScoreManager::AddScore(vFar);
	}
}