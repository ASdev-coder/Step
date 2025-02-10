#pragma once
#include "Armor.h"
class Outerwear : public Armor
{
private:
	static const BodyParts BODY_PART{ BodyParts::BODY };
public:
	Outerwear(const std::string& title, unsigned short price, unsigned short durability);
};

