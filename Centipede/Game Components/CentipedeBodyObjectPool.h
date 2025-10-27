#ifndef _CentipedeBodyObjectPool
#define _CentipedeBodyObjectPool

#include <stack>
class CentipedeBody;

class CentipedeBodyObjectPool
{
private:
	std::stack<CentipedeBody*> recycledItems;

public:
	CentipedeBodyObjectPool() = default;
	CentipedeBodyObjectPool(const CentipedeBodyObjectPool&) = delete;
	CentipedeBodyObjectPool& operator=(const CentipedeBodyObjectPool&) = delete;
	~CentipedeBodyObjectPool();

	CentipedeBody* GetCentipedeBody();
	void ReturnCentipedeBody(CentipedeBody* b);
};

#endif _CentipedeBodyObjectPool