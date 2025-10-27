#ifndef _ExplosionBigObjectPool
#define _ExplosionBigObjectPool

#include <stack>
class ExplosionBig;

class ExplosionBigObjectPool
{
private:
	std::stack<ExplosionBig*> recycledItems;

public:
	ExplosionBigObjectPool() = default;
	ExplosionBigObjectPool(const ExplosionBigObjectPool&) = delete;
	ExplosionBigObjectPool& operator=(const ExplosionBigObjectPool&) = delete;
	~ExplosionBigObjectPool();

	ExplosionBig* GetExplosionBig();
	void ReturnExplosionBig(ExplosionBig* e);
};

#endif _ExplosionBigObjectPool