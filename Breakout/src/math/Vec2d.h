#pragma once

class Vec2d
{
public:
	int x, y;

	Vec2d(int pX, int pY);
	~Vec2d();

	inline void set(int pX, int pY) { x = pX, y = pY; }

	// Assignment operator
	Vec2d& operator=(Vec2d& other);

	// Relational operators
	bool operator==(Vec2d& other);

	// Vector products
	float dot(Vec2d& other);
	
	//Others
	float magnitude();

	Vec2d normalize();

	float lengthTo(Vec2d& other);

	float getAngleTo(Vec2d& other);
};


// Arithmatic operators
Vec2d operator+(Vec2d v1, const Vec2d& v2);

Vec2d operator-(Vec2d v1, const Vec2d& v2);
