#ifndef _ScorpionObjectPool
#define _ScorpionObjectPool

#include <stack>
class Scorpion;

class ScorpionObjectPool
{
private:
	std::stack<Scorpion*> recycledItems;

public:
	ScorpionObjectPool() = default;
	ScorpionObjectPool(const ScorpionObjectPool&) = delete;
	ScorpionObjectPool& operator=(const ScorpionObjectPool&) = delete;
	~ScorpionObjectPool();

	Scorpion* GetScorpion();
	void ReturnScorpion(Scorpion* s);
};

#endif _ScorpionObjectPool