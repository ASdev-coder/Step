#pragma once

#include "Thing.h"
#include "BodyParts.h"

class Armor : public Thing
{
private:
	unsigned short durability;

public:
	Armor(const std::string& title, unsigned short price, BodyParts bodyPart, unsigned short durability);

	virtual void defence() = 0;
};

