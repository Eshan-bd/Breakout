#include "sdl.h"
#include "dlog.h"
#include "math/Vec2d.h"

int main(int argc, char* args[])
{
	sdl s;

	//Start up SDL and create window
	if ( !s.init() )
	{
		dlog::error("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!s.load() )
		{
			dlog::error("Failed to load media!\n");
		}
		else
		{
			s.update();
		}
	}

	//Free resources and close SDL
	s.close();
	return 0;
}
