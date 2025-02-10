#include "Sward.h"

Sward::Sward(const std::string& title, unsigned short price, unsigned short radius, unsigned short min_damage, unsigned short max_damage) :
	Weapon{ title, price, Sward::BODY_PART, radius, min_damage, max_damage }
{}

