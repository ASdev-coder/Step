#include "Unit.h"

Unit::Unit(const Point& p, unsigned short hp, unsigned char level, unsigned short backPackCapacity):
	position{ p },
	hp{ hp },
	level { level },
	backpack{ backPackCapacity }
{}

void Unit::pushThingToBackpack(Thing * thing)
{
	this->backpack.push(thing);
}

Thing* Unit::popThingFromBackpack(unsigned int id)
{
	return this->backpack.pop(id);
}

bool Unit::putOn(Thing* thing)
{
	return this->body.set(thing);
}

Thing* Unit::takeOff(BodyParts part)
{
	return this->body.unset(part);
}

bool Unit::putOnFromBackpack(unsigned int id)
{
	return this->putOn(this->popThingFromBackpack(id));
}
