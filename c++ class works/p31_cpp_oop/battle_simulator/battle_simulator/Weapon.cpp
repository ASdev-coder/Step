#include "Weapon.h"

Weapon::Weapon(const std::string& title, unsigned short price, BodyParts bodyPart, unsigned short radius, unsigned short min_damage, unsigned short max_damage):
	Thing{ title, price, bodyPart },
	radius{radius},
	min_damage{min_damage},
	max_damage{max_damage}
{}
