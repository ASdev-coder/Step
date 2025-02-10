#include "Point.h"

Point::Point(unsigned short x, unsigned short y):
	x{x},
	y{y}
{}

void Point::set(unsigned short x, unsigned short y)
{
	this->x = x;
	this->y = y;
}

unsigned short Point::getX() const
{
	return this->x;
}

unsigned short Point::getY() const
{
	return this->y;
}
