#include "DynamicObject.h"


DynamicObject::DynamicObject()
{
	velX = 0;
	velY = 0;
}


void DynamicObject::update(Uint32& dt)
{
}
void DynamicObject::render(Texture& tex)
{
	tex.render(posX, posY, &gSprite);
}


void DynamicObject::free()
{
}

DynamicObject::~DynamicObject()
{
	free();
}