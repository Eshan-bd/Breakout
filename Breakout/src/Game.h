/*
Game class is the final wrapper before main()
*/

#pragma once

#include <Box2D.h>
#include <SDL.h>

class Texture;
class Paddle;
class Ball;

class Game
{
private:
	// Physics world
	std::shared_ptr<b2World> mWorld;
	float32 mTimeStep;
	int32 mVelIter;
	int32 mPosIter;

	// Create game objects
	std::unique_ptr<Paddle> paddle;
	std::unique_ptr<Ball> ball;

	// declare textures
	std::shared_ptr<Texture> spritesheet;
	

public:
	Game();

	~Game();

	// Initialize window, sdl etc
	// bool init();
	
	// Load assests
	bool loadMedia(SDL_Renderer *renderer);

	// Game loop
	void update();

	// Render textures
	void render(SDL_Renderer *renderer);
	
	void event(SDL_Event &e);

	// Free all assets and close
	void close();

};
