#ifndef _ScoreSlot
#define _ScoreSlot

#include "TEAL\CommonElements.h"

class ScoreSlot
{
public:
	ScoreSlot() = default;
	ScoreSlot(std::string initials, int score);
	ScoreSlot(const ScoreSlot&) = default;
	ScoreSlot& operator = (const ScoreSlot&) = default;
	~ScoreSlot() = default;

	bool operator<(const ScoreSlot& other);

	int getScore();
	void setScore(int s);
	void setInitials(std::string i);
	std::string getInitials();
private:
	std::string initials;
	int score;

};

#endif _ScoreSlot