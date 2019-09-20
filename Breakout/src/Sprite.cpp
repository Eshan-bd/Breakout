#include "Sprite.h"
#include "math/Vec2d.h"


Sprite::Sprite(SDL_Rect *tex, int pX, int pY) :
	mTexture(tex), pos( pX, pY )
{}

void Sprite::update()
{

}

void Sprite::render(std::shared_ptr<Texture> tex)
{
	tex->render(pos.x-getWidth()/2, pos.y-getHeight()/2, mTexture);
}

void Sprite::move(int pX, int pY)
{
	pos.x += pX;
	pos.y += pY;
}

Sprite::~Sprite()
{}
