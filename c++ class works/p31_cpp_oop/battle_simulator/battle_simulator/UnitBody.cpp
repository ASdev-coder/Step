#include "UnitBody.h"

UnitBody::UnitBody()
{}

bool UnitBody::set(Thing* thing)
{
	switch (thing->getBodyPart())
	{
	case BodyParts::HEAD:
		if (this->head != nullptr)
			return false;

		this->head = thing;
		return true;

	case BodyParts::BODY:
		if (this->body != nullptr)
			return false;

		this->body = thing;
		return true;

	case BodyParts::R_HAND:
		if (this->r_hand != nullptr)
			return false;

		this->r_hand = thing;
		return true;

	case BodyParts::L_HAND:
		if (this->l_hand != nullptr)
			return false;

		this->l_hand = thing;
		return true;
	}

	return false;
}

Thing* UnitBody::unset(BodyParts part)
{
	return nullptr;
}
