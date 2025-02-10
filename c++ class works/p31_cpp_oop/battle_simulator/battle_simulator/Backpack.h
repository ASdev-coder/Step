#pragma once

#include <list>
#include "Thing.h"

class Backpack
{
private:
	unsigned short capacity;
	unsigned short free_space;
	std::list<Thing*> things;

public:
	Backpack(unsigned short capacity = 50);
	
	bool push(Thing* thing);
	Thing* pop(unsigned int id);
};

