#include "Armor.h"

Armor::Armor(const std::string& title, unsigned short price, BodyParts bodyPart, unsigned short durability):
	Thing{ title, price, bodyPart },
	durability { durability }
{}
