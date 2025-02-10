#include "Outerwear.h"

Outerwear::Outerwear(const std::string& title, unsigned short price, unsigned short durability):
	Armor{title, price, Outerwear::BODY_PART, durability}
{}
