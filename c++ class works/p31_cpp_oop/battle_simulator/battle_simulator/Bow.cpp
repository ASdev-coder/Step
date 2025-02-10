#include "Bow.h"

Bow::Bow(
	const std::string& title, 
	unsigned short price,
	unsigned short radius, 
	unsigned short min_damage, 
	unsigned short max_damage, 
	unsigned short min_distance
) :
	Weapon{ title, price, Bow::BODY_PART, radius, min_damage, max_damage },
	min_distance{min_distance}
{}