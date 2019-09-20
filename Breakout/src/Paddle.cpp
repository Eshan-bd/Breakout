#include "Paddle.h"
#include "config.h"
#include "dlog.h"

// to fix error-C2061
// #include "Ball.h"

Paddle::Paddle(std::shared_ptr<b2World> pWorld) :
	Sprite(new SDL_Rect{ 1158, 462, 243, 64 }, 122, (SCREEN_HEIGHT - 32)), mSpeed(6), vel(0, 0)
{
	// Paddle physics body
	b2BodyDef paddleBodyDef;
	paddleBodyDef.type = b2_kinematicBody;
	paddleBodyDef.position.Set(122, SCREEN_HEIGHT - 32);
	body = pWorld->CreateBody(&paddleBodyDef);
	b2PolygonShape paddleShape;
	paddleShape.SetAsBox(getWidth() / 2, getHeight() / 2);
	body->CreateFixture(&paddleShape, 0.0f);
}


void Paddle::update()
{
	// Set sprite position on current keystate and make sure sprite doesn't move out of the window
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if ( currentKeyStates[SDL_SCANCODE_LEFT])
	{
		vel.x = 3;
	}
	else if (currentKeyStates[SDL_SCANCODE_RIGHT]) 
	{
		vel.x = -3;
	}
	else
	{
		vel.x = 0;
	}

	body->SetLinearVelocity(b2Vec2(vel.x, vel.y));
}

void Paddle::render(std::shared_ptr<Texture> tex)
{
	setPos(body->GetPosition().x, body->GetPosition().y);
	dlog::cout("X: ");
	dlog::cout( std::to_string(body->GetPosition().x) );
	tex->render(getX() - getWidth() / 2, getY() - getHeight() / 2, mTexture);
}

Paddle::~Paddle()
{
}
