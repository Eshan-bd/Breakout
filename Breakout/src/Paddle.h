#pragma once

#include "Sprite.h"

class Paddle : public Sprite
{
private:
	int mSpeed;
	Vec2d vel;
public:
	b2Body* body;

	Paddle(std::shared_ptr<b2World> pWorld);
	~Paddle();

	void update();

	void render(std::shared_ptr<Texture> tex);
};
