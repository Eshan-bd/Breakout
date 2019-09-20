#include "Ball.h"
#include "config.h"
#include <iostream>


Ball::Ball(std::shared_ptr<b2World> pWorld):
	Sprite(new SDL_Rect{ 1403, 652, 64, 64 }, 0, 0), velX(0), velY(0), mSpeed(8), mLaunched(false)
{
	// Ball physics body
	b2BodyDef ballBodyDef;
	ballBodyDef.type = b2_dynamicBody;
	ballBodyDef.position.Set(0, 0);
	body = pWorld->CreateBody(&ballBodyDef);
	b2PolygonShape ballShape;
	ballShape.SetAsBox(getWidth() / 2, getHeight() / 2);
	body->CreateFixture(&ballShape, 0.0f);
}

void Ball::update()
{

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	// Space to launch the ball
	if (currentKeyStates[SDL_SCANCODE_SPACE] && !mLaunched)
		launch();

	// Add movement
	move(velX, 0);
	move(0, velY);

	int top, bot, left, right;
	top = getY() - getHeight() / 2;
	bot = getY() + getHeight() / 2;
	left = getX() - getWidth() / 2;
	right = getX() + getWidth() / 2;
}

void Ball::render(std::shared_ptr<Texture> tex)
{
	tex->render(getX() - getWidth() / 2, getY() - getHeight() / 2, mTexture);
}

void Ball::launch()
{
	mLaunched = true;
	velX = mSpeed;
	velY = -mSpeed;
}

Ball::~Ball()
{
}
