#pragma once

#include "Thing.h"
#include "BodyParts.h"

class UnitBody
{
private:
	Thing* head{ nullptr };
	Thing* body{ nullptr };
	Thing* r_hand{ nullptr };
	Thing* l_hand{ nullptr };

public:
	UnitBody();

	bool set(Thing* thing);
	Thing* unset(BodyParts part);
};

