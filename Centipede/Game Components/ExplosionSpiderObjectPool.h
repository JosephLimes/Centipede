#ifndef _ExplosionSpiderObjectPool
#define _ExplosionSpiderObjectPool

#include <stack>
class ExplosionSpider;

class ExplosionSpiderObjectPool
{
private:
	std::stack<ExplosionSpider*> recycledItems;

public:
	ExplosionSpiderObjectPool() = default;
	ExplosionSpiderObjectPool(const ExplosionSpiderObjectPool&) = delete;
	ExplosionSpiderObjectPool& operator=(const ExplosionSpiderObjectPool&) = delete;
	~ExplosionSpiderObjectPool();

	ExplosionSpider* GetExplosionSpider();
	void ReturnExplosionSpider(ExplosionSpider* e);
};

#endif _ExplosionSpiderObjectPool