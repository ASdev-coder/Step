#include "Thing.h"

unsigned int Thing::MAX_ID = 0;

Thing::Thing(const std::string& title, unsigned short price, BodyParts bodyPart, unsigned short weight):
	id { ++Thing::MAX_ID },
	title {title},
	price {price},
	weight {weight},
	bodyPart{ bodyPart }
{}

unsigned short Thing::getWeight() const
{
	return this->weight;
}

unsigned int Thing::getId() const
{
	return this->id;
}

BodyParts Thing::getBodyPart() const
{
	return this->bodyPart;
}

void Thing::setWeight(unsigned short weight)
{
	this->weight = weight;
}
