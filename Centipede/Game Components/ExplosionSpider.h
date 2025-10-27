#ifndef _ExplosionSpider
#define _ExplosionSpider

#include "TEAL\CommonElements.h"

enum SpiderDistance 
{
	exNear,
	exMed,
	exFar
};

class ExplosionSpider : public GameObject
{
public:
	ExplosionSpider() = default;
	ExplosionSpider(const ExplosionSpider&) = delete;
	ExplosionSpider& operator=(const ExplosionSpider&) = delete;
	~ExplosionSpider() = default;

	void Initialize(sf::Vector2f pos, SpiderDistance dist);

	virtual void Draw();

	void Alarm0();

private:
	AnimatedSprite MainSprite;
};


#endif _ExplosionSpider