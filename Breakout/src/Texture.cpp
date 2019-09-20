#include "Texture.h"
#include "dlog.h"
#include <cstdio>

Texture::Texture()
	// mTexture( )
{
	// Initialize
	this->mTexture = NULL;
	this->mRenderer = NULL;
	this->mWidth = 0;
	this->mHeight = 0;
}

Texture::~Texture()
{
	//Deallocate
	free();
}

bool Texture::loadfromfile(std::string path, SDL_Renderer* renderer)
{
	//Get rid preexisting texture
	free();

	SDL_Texture* newTexture = NULL;
	this->mRenderer = renderer;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(this->mRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());

		}
		else
		{
			//Get image dimension
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	this->mTexture = newTexture;
	return this->mTexture != NULL;
}

#ifdef _SDL_TTF_H
bool Texture::loadFromRendererText(TTF_Font* font, std::string textureText,SDL_Renderer* renderer, SDL_Color textColor)
{
	//Get rid of preexisting texture
	free();

	mRenderer = renderer;

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}
		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
	//Return success
	return mTexture != NULL;
}
#endif

void Texture::free()
{
	//Free texture if it exists
	if (this->mTexture != NULL)
	{
		SDL_DestroyTexture(this->mTexture);
		this->mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Create a rendering space and render to screen
	SDL_Rect renderQuad = { x, y, this->mWidth, this->mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int Texture::getWidth()
{
	return mWidth;
}

int Texture::getHeight() {
	return mHeight;
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(this->mTexture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(this->mTexture, blending);
}

void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(this->mTexture, alpha);
}
