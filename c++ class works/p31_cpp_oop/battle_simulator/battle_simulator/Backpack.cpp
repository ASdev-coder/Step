#include "Backpack.h"

Backpack::Backpack(unsigned short capacity) :
	capacity{ capacity },
	free_space{ capacity }
{}

bool Backpack::push(Thing* thing)
{
	if (this->free_space < thing->getWeight())
		return false;

	this->things.push_back(thing);

	this->free_space -= thing->getWeight();

	return true;
}

Thing* Backpack::pop(unsigned int id)
{
	for (Thing* thing : this->things)
	{
		if (thing->getId() == id)
		{
			this->free_space += thing->getWeight();

			this->things.remove(thing);

			return thing;
		}
	}

	return nullptr;
}
