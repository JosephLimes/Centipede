#ifndef _ExplosionSmallObjectPool
#define _ExplosionSmallObjectPool

#include <stack>
class ExplosionSmall;

class ExplosionSmallObjectPool
{
private:
	std::stack<ExplosionSmall*> recycledItems;

public:
	ExplosionSmallObjectPool() = default;
	ExplosionSmallObjectPool(const ExplosionSmallObjectPool&) = delete;
	ExplosionSmallObjectPool& operator=(const ExplosionSmallObjectPool&) = delete;
	~ExplosionSmallObjectPool();

	ExplosionSmall* GetExplosionSmall();
	void ReturnExplosionSmall(ExplosionSmall* e);
};

#endif _ExplosionSmallObjectPool