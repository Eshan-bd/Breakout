#pragma once

#include "Sprite.h"


class Ball : public Sprite
{
private:
	int velX, velY, mSpeed;
	bool mLaunched; // there is a isLaunched mfunction
	std::shared_ptr<Sprite> mPaddle;
public:
	b2Body* body;

	Ball(std::shared_ptr<b2World> pWorld);
	~Ball();

	void update();

	void render(std::shared_ptr<Texture> tex);

	inline bool isLaunched() const { return mLaunched; };

	void launch();

	inline void reverseX() { velX = -velX; }
	inline void reverseY() { velY = -velY; }
};

