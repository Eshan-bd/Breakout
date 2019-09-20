#include "Vec2d.h"
#include <math.h>

Vec2d::Vec2d(int pX=0, int pY=0) :
	x(pX), y(pY)
{}

// Assignment operator
Vec2d& Vec2d::operator=(Vec2d& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

// Arithmatic operators
Vec2d operator+(Vec2d v1, const Vec2d& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	return v1;
}

Vec2d operator-(Vec2d v1, const Vec2d& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	return v1;
}

// Relational operators
bool Vec2d::operator==(Vec2d& other)
{
	if (x == other.x && y == other.y)
	{
		return true;
	}
	return false;
}

float Vec2d::dot(Vec2d& other)
{
	return x * other.x + y * other.y;
}

//others
float Vec2d::magnitude()
{
	return sqrt(x * x + y * y);
}

Vec2d Vec2d::normalize()
{
	float l = magnitude();
	return Vec2d(x / l, y / l);
}

float Vec2d::lengthTo(Vec2d& other)
{
	Vec2d local = other - *this;
	return sqrt( pow(x-other.x, 2) + pow(y-other.y, 2) );
}

float Vec2d::getAngleTo(Vec2d& other)
{
	// returns angle in radians
	if ((magnitude() * other.magnitude()) != 0)
	{
		return acos(dot(other) / (magnitude() * other.magnitude()));
	}
}

Vec2d::~Vec2d()
{}

