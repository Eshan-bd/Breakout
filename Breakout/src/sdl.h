#pragma once

//Using SDL, SDL_image,SDL_ttf, standard IO, strings and math
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "include.h"

#include <iostream>
#include <string>
#include <cmath>

#include "Game.h"

class sdl
{
private:
	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;
	Game game;
public:
	bool init();

	bool load();

	bool update();

	void close();
};
