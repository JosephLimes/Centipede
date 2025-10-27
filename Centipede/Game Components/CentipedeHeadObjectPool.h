#ifndef _CentipedeHeadObjectPool
#define _CentipedeHeadObjectPool

#include <stack>
class CentipedeHead;

class CentipedeHeadObjectPool
{
private:
	std::stack<CentipedeHead*> recycledItems;

public:
	CentipedeHeadObjectPool() = default;
	CentipedeHeadObjectPool(const CentipedeHeadObjectPool&) = delete;
	CentipedeHeadObjectPool& operator=(const CentipedeHeadObjectPool&) = delete;
	~CentipedeHeadObjectPool();

	CentipedeHead* GetCentipedeHead();
	void ReturnCentipedeHead(CentipedeHead* b);
};

#endif _CentipedeHeadObjectPool