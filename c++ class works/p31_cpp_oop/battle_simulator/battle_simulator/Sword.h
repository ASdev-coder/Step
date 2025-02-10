#pragma once

#include "Weapon.h"

class Sword : public Weapon
{
private:
	static const BodyParts BODY_PART{ BodyParts::R_HAND };


public:
	Sword(
		const std::string& title,
		unsigned short price,
		unsigned short weight = 1,
		unsigned short radius = 1,
		unsigned short min_damage = 10,
		unsigned short max_damage = 50
	);
};

