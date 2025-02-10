#pragma once

#include "Weapon.h"

class Bow : public Weapon
{
private:
	static const BodyParts BODY_PART{ BodyParts::R_HAND };

	unsigned short min_distance;
	
public:
	Bow(
		const std::string& title,
		unsigned short price,
		unsigned short radius = 1,
		unsigned short min_damage = 10,
		unsigned short max_damage = 50,
		unsigned short min_distance = 1
	);

};

