#pragma once

#include "Thing.h"
#include "BodyParts.h"

class Weapon : public Thing
{
private:
	unsigned short radius;
	unsigned short min_damage;
	unsigned short max_damage;

public:
	Weapon(
		const std::string& title, 
		unsigned short price,
		BodyParts bodyPart,
		unsigned short radius = 1,
		unsigned short min_damage = 10,
		unsigned short max_damage = 50
		);

	// virtual void attack() = 0;
};

