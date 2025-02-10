#pragma once
#include "Unit.h"


class Archer : public Unit
{
public:
	Archer(
		const Point& p,
		unsigned short hp,
		unsigned char level,
		unsigned short backPackCapacity
	);
};
