#pragma once

#include "Texture.h"
#include "config.h"

class DynamicObject
{
protected:
	SDL_Rect gSprite;
	int posX, posY, velX, velY, speed;

public:
	DynamicObject();

	void update(Uint32& dt);

	void render(Texture& tex);

	void free();

	~DynamicObject();
};

