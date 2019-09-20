#pragma once

#include "psx.h"
#include "../math/math.h"

class World
{
private:
	b2Vec2 mGravity;
	b2World mWorld;
public:
	World(math::Vec2d& pGravity);
	~World();
};
