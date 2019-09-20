#pragma once

#include "Texture.h"
#include <SDL.h>
#include "math/Vec2d.h"

class Sprite
{
private:
	Vec2d pos;

protected:
	SDL_Rect *mTexture;

public:
	// tex is the position of the texture on spritesheet
	Sprite(SDL_Rect *tex, int pX, int pY);
	virtual ~Sprite();
	
	// get inputs and change positions
	// pure virtual funtion
	virtual void update() = 0;

	// Render the sprite
	virtual void render(std::shared_ptr<Texture> tex);

	void move(int pX, int pY);

	inline int getX() const { return pos.x; }

	inline int getY() const { return pos.y; }

	inline int getWidth() const { return mTexture->w; }

	inline int getHeight() const { return mTexture->h;  }

protected:
	inline void setPos(int mX, int mY) { pos.set(mX, mY); }
};
