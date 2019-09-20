#pragma once

#include "Globals.h"

class Button
{
public:
	Button();
	~Button();

	void setPosition(int x, int y);
	void handleEvent(SDL_Event* e);
	void render();

private:
	SDL_Point mPosition;

	ButtonSprite mCurrentSprite;
};

