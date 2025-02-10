#pragma once
class Point
{
private:
	unsigned short x;
	unsigned short y;

public:
	Point(unsigned short x = 0, unsigned short y = 0);

	void set(unsigned short x, unsigned short y);
	unsigned short getX() const;
	unsigned short getY() const;
};

