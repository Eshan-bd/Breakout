#pragma once

//Using SDL, SDL_image,SDL_ttf, standard IO, and strings
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

#include "include.h"


//Texture wrapper class
class Texture
{

private:
	//The actual hardware texture
	SDL_Texture *mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;

	//The renderer where the image will be rendered to
	SDL_Renderer* mRenderer;
public:

	//initializes variables
	Texture();

	//Deallocate memory
	~Texture();

	//loads image at specified path
	bool loadfromfile(std::string path, SDL_Renderer* renderer);

	#ifdef _SDL_TTF_H
	//Creates image from font string
	bool loadFromRendererText(TTF_Font* font, std::string textureText, SDL_Renderer* renderer, SDL_Color textColor);
	#endif

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending eg: transition etc.
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Deallocates texture
	void free();

	/*
	Renders texture at given point
	(x, y) is the positon of the texture in the window
	clip is the position and size of a sprite in the texture {x, y, w, h}
	*/
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimension
	int getWidth();
	int getHeight();

};

struct TextureDeleter
{
	void operator()(SDL_Texture* tp) {
		SDL_DestroyTexture(tp);
	}
};
