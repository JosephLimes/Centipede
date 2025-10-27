#include "ScoreSlot.h"

ScoreSlot::ScoreSlot(std::string initials, int score)
	: initials(initials), score(score)
{}

bool ScoreSlot::operator<(const ScoreSlot& other)
{
	return score > other.score;
}

int ScoreSlot::getScore()
{
	return score;
}

void ScoreSlot::setScore(int s)
{
	score = s;
}

void ScoreSlot::setInitials(std::string i)
{
	initials = i;
}

std::string ScoreSlot::getInitials()
{
	return initials;
}