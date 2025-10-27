#ifndef _Attractor
#define _Attractor

#include "TEAL\CommonElements.h"

class Attractor : public Scene
{
public:
	Attractor() = default;
	Attractor(const Attractor&) = delete;
	Attractor& operator=(const Attractor&) = delete;
	~Attractor() = default;

	virtual void Initialize();
	virtual void Terminate();
};

#endif _Attractor