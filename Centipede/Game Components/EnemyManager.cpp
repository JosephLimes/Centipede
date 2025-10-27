#include "EnemyManager.h"
#include "CentipedeHead.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBody.h"
#include "CentipedeBodyFactory.h"
#include "FleaFactory.h"
#include "Scorpion.h"
#include "ScorpionFactory.h"
#include "Spider.h"
#include "SpiderFactory.h"
#include "Grid.h"
#include "GameManager.h"
#include "FleaSpawner.h"
#include "ScorpionSpawner.h"
#include "SpiderSpawner.h"
#include "CentipedeSpawner.h"

EnemyManager::EnemyManager()
	:	
		pFleaSpawner(new FleaSpawner()),
		pScorpionSpawner(new ScorpionSpawner()),
		pSpiderSpawner(new SpiderSpawner()),
		pCentipedeSpawner(new CentipedeSpawner())
{}

void EnemyManager::Alarm0()
{
	// designated scorpion alarm

	if (pScorpionSpawner->count() < 1) pScorpionSpawner->spawn();
	SetAlarm(0, pScorpionSpawner->frequency());
}

void EnemyManager::Alarm1()
{
	// designated spider alarm

	if (pSpiderSpawner->count() < 1) pSpiderSpawner->spawn();
	SetAlarm(1, pSpiderSpawner->frequency());
}

void EnemyManager::fleaSpawnFlagCheck()
{
	pFleaSpawner->spawnConditional();
}

void EnemyManager::playerDeath()
{
	Trace::out("Player died! Recalling critters...\n");
	FleaFactory::Recall();
	ScorpionFactory::Recall();
	SpiderFactory::Recall();
	CentipedeHeadFactory::Recall();
	CentipedeBodyFactory::Recall();
}

void EnemyManager::processWaveData(int wave, std::string data)
{
	std::string wavestr = std::to_string(wave);
	int linenumber = 1;
	bool inSection = false; // for tracking our current section
	std::string variablename;

	// make all lowercase for parsing
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	std::istringstream datastream = std::istringstream(data);
	std::string line;

	try
	{
		while (std::getline(datastream, line)) {
			std::string subline = line.substr(0, 4);
			// look for section headers
			if ("wave " == line.substr(0, 5))
			{
				if (inSection == true) // end of our section, don't care about the rest of data
				{
					break;
				}
				else if (wavestr == line.substr(5, line.length())) // we found our section
				{
					inSection = true;
				}
				// else we don't care, keep looking for our section
			}
			else if (inSection) // in our section, process values
			{
				int pos = line.find(" ");
				variablename = line.substr(0, pos);
				std::string value = line.substr(pos + 1, line.length());

				// find out which variable this is... the ugly part
				if (variablename == "fleaenabled")
				{
					if (value == "true") pFleaSpawner->setEnabled(true);
					else if (value == "false") pFleaSpawner->setEnabled(false);
				}
				else if (variablename == "fleaspeed")
				{
					pFleaSpawner->setSpeed(std::stoi(value));
				}
				else if (variablename == "fleamushroomthreshold")
				{
					pFleaSpawner->setMushroomThreshold(std::stoi(value));
				}
				else if (variablename == "fleamushroomchance")
				{
					pFleaSpawner->setMushroomChance(std::stoi(value));
				}


				else if (variablename == "scorpionenabled")
				{
					if (value == "true") pScorpionSpawner->setEnabled(true);
					else if (value == "false") pScorpionSpawner->setEnabled(false);
				}
				else if (variablename == "scorpionspeed")
				{
					pScorpionSpawner->setSpeed(std::stoi(value));
				}
				else if (variablename == "scorpionfrequency")
				{
					pScorpionSpawner->setFrequency(std::stof(value));
				}


				else if (variablename == "spiderenabled")
				{
					if (value == "true") pSpiderSpawner->setEnabled(true);
					else if (value == "false") pSpiderSpawner->setEnabled(false);
				}
				else if (variablename == "spiderspeed")
				{
					pSpiderSpawner->setSpeed(std::stoi(value));
				}
				else if (variablename == "spiderfrequency")
				{
					pSpiderSpawner->setFrequency(std::stof(value));
				}


				else if (variablename == "soloheadenabled")
				{
					if (value == "true") pCentipedeSpawner->setSoloHeadEnabled(true);
					else if (value == "false") pCentipedeSpawner->setSoloHeadEnabled(false);
				}
				else if (variablename == "soloheadcount")
				{
					pCentipedeSpawner->setSoloHeadCount(std::stoi(value));
					GameManager::setHeadCount(std::stoi(value) + 1); // plus one for the main centipede
				}


				else if (variablename == "centipedespeed")
				{
					pCentipedeSpawner->setSpeed(std::stoi(value));//centipedeSpeed = std::stoi(value);
				}
				else if (variablename == "centipedelength")
				{
					pCentipedeSpawner->setLength(std::stoi(value)); //centipedeLength = std::stoi(value);
				}

				else if (variablename == "")
				{
					// blank line, ignore
				}

				else // variable not recognized
				{
					std::string errormsg = ("Wave config error: variable on line " + std::to_string(linenumber) + " not recognized.\n");
					throw std::runtime_error(errormsg);
				}
			}
			// else we don't care, keep looking for our section
			linenumber++;
		}

		if (!inSection) // never found wave header
		{
			Trace::out("Warning - could not find data for wave %d, using previous values\n", wave);
			GameManager::setHeadCount(pCentipedeSpawner->getSoloHeadCount() + 1); // still need to re-update the centipede tracking
		}
	}
	catch (const std::exception& e)
	{

		Trace::out("\n**********************************************************\nWAVE DATA ERROR:\n");
		Trace::out(e.what());
		Trace::out("**********************************************************\n");
		std::abort();
	}

	Trace::out("Starting wave %d\n", wave);
	startWave();
}

void EnemyManager::startWave()
{
	// check if flea should be spawned
	pFleaSpawner->spawnConditional();

	// set up our spawn alarms
	// scorpion alarm
	if (pScorpionSpawner->isEnabled())
	{
		SetAlarm(0, pScorpionSpawner->frequency());
	}
	else
	{
		AlarmCancel(0);
	}

	// spider alarm
	if (pSpiderSpawner->isEnabled())
	{
		SetAlarm(1, pSpiderSpawner->frequency());
	}
	else
	{
		AlarmCancel(1);
	}

	// spawn centipede(s)
	pCentipedeSpawner->startWave();

	int headCount;
	if (pCentipedeSpawner->getSoloHeadEnabled()) headCount = pCentipedeSpawner->getSoloHeadCount() + 1;
	else headCount = 1;
	GameManager::setHeadCount(headCount); // update game manager
}

EnemyManager::~EnemyManager()
{
	delete pFleaSpawner;
	delete pScorpionSpawner;
	delete pSpiderSpawner;
	delete pCentipedeSpawner;
}