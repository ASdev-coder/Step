#pragma once

#include "Point.h"
#include "AbilityCard.h"
#include "Backpack.h"
#include "UnitBody.h"

class Unit
{
protected:
	Point position;
	unsigned short hp;		// ~ 0 - 10000
	unsigned char level;	// ~ 1 - 100
	AbilityCard abilityCard;
	Backpack backpack;
	UnitBody body;

public:
	Unit(
		const Point& p,
		unsigned short hp,
		unsigned char level,
		unsigned short backPackCapacity
	);

	void pushThingToBackpack(Thing* thing);
	Thing* popThingFromBackpack(unsigned int id);

	bool putOn(Thing* thing);
	Thing* takeOff(BodyParts part);

	bool putOnFromBackpack(unsigned int id);





};
