#include "Collision.h"
#include "Sprite.h"


Collision::Collision()
{
}


Collision::~Collision()
{
}

bool checkCollision(std::shared_ptr<Sprite> col1, std::shared_ptr<Sprite> col2)
{
	/*
	// Calculate the sides of sprite 1 and sprite 2
	int left1, left2, right1, right2, top1, top2, bot1, bot2;
	left1 = col1->getX();
	right1 = col1->getX() + col1->getWidth();
	top1 = col1->getY();
	bot1 = col1->getY() + col1->getHeight();

	left2 = col2->getX();
	right2 = col2->getX() + col2->getWidth();
	top2 = col2->getY();
	bot2 = col2->getY() + col2->getHeight();

	if (left1 >= right2) return false;
	if (right1 <= left2) return false;
	if (top1 >= bot2) return false;
	if (bot1 <= top2) return false;

	return true;
	*/

	SDL_Rect *rect1 = { col1->getX(), col1->getY(), col1->getWidth(), col1->getHeight(); }
	SDL_Rect *rect2 = { col2->getX(), col2->getY(), col2->getWidth(), col2->getHeight(); }

	SDL_HasIntersection(rect1, rect2);
}
