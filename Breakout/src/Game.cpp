#include "Game.h"
#include "dlog.h"


// Game entity classes
#include "Ball.h"
#include "Paddle.h"

Game::Game():
	mWorld(std::make_shared<b2World>(b2Vec2(0.0f, 10.0f))),
	paddle(std::make_unique<Paddle>(mWorld)), ball(std::make_unique<Ball>(mWorld) )
{
	spritesheet = std::shared_ptr<Texture>(new Texture());

}

bool Game::loadMedia(SDL_Renderer *renderer)
{
	//Loading success flag
	bool success = true;

	//Open the font
	if (!spritesheet->loadfromfile("res/spritesheet.png", renderer))
	{
		dlog::error("Failed to load sprite.png!\n");
		success = false;
	}
	return success;

	// set time step of 1/60(60Hz)
	mTimeStep = 1.0f / 60.0f;
	mVelIter = 2;
	mPosIter = 1;
}

void Game::update()
{
	// Update entities
	paddle->update();
	ball->update();

	// Update physics simulation
	mWorld->Step(mTimeStep, mVelIter, mPosIter);
}


void Game::render(SDL_Renderer *renderer)
{

	// Render sprites
	paddle->render(spritesheet);
	ball->render(spritesheet);
}


void Game::event(SDL_Event &e)
{

}

void Game::close()
{
	//Free loaded images
	spritesheet->free();
	
}

Game::~Game()
{
	close();
}
