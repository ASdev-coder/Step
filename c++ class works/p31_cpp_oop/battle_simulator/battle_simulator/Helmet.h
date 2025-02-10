#pragma once
#include "Armor.h"
class Helmet : public Armor
{
private:
	static const BodyParts BODY_PART{ BodyParts::HEAD };

public:
	Helmet(const std::string& title, unsigned short price, unsigned short durability);
};

