#include "sdl.h"
#include "config.h"
#include "dlog.h"

bool sdl::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		//Set texture filtering to linear(Good quality)
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			dlog::error("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		mWindow = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (mWindow == NULL)
		{
			std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			//Create renderer for window
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (mRenderer == NULL)
			{
				std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
				success = false;
			}
			else
			{

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
					success = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					std::cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << TTF_GetError() << std::endl;
				}
			}
		}
	}

	return success;
}

bool sdl::load()
{
	bool success = true;
	if (!game.loadMedia(mRenderer))
	{
		success = false;
	}
	return success;
}

bool sdl::update()
{
	// Main loop flag
	bool quit = false;

	// Event handler
	SDL_Event e;

	Uint32 deltaTime, oldTime, newTime;
	oldTime = SDL_GetTicks();

	// main game loop
	while (!quit)
	{
		// Update delta time
		newTime = SDL_GetTicks();
		deltaTime = newTime - oldTime;

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			game.event(e);

			// User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		game.update();

		// lower cpu load
		SDL_Delay(10);

		oldTime = newTime;

		// Clear screen
		SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(mRenderer);

		game.render(mRenderer);

		// Update screen
		SDL_RenderPresent(mRenderer);
	}
	return true;
}

void sdl::close()
{
	//Destroy window	
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;
	mRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
