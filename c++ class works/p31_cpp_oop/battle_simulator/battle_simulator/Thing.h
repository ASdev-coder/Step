#pragma once

#include <string>
#include "BodyParts.h"

class Thing
{
private:
	static unsigned int MAX_ID;

	unsigned int id;

	std::string title;
	unsigned short price;
	unsigned short weight;
	BodyParts bodyPart;

public:
	Thing(const std::string& title, unsigned short price, BodyParts bodyPart, unsigned short weight = 1);

	unsigned short getWeight() const;
	unsigned int getId() const;
	BodyParts getBodyPart() const;

	void setWeight(unsigned short weight);

};

