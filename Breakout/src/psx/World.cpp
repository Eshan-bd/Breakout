#include "World.h"



World::World(math::Vec2d &pGravity):
	mGravity(0.0f, 0.0f), mWorld(mGravity)
{
	mGravity.Set( pGravity.getX())
}


World::~World()
{
}
