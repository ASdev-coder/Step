#include "Helmet.h"

Helmet::Helmet(const std::string& title, unsigned short price, unsigned short durability):
	Armor{title, price, Helmet::BODY_PART, durability}
{}
