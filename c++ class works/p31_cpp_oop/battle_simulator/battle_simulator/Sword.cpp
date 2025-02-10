#include "Sword.h"

Sword::Sword(
	const std::string& title,
	unsigned short price,
	unsigned short weight,
	unsigned short radius, 
	unsigned short min_damage, 
	unsigned short max_damage
) :
	Weapon{ title, price, Sword::BODY_PART, weight, radius, min_damage, max_damage }
{}

