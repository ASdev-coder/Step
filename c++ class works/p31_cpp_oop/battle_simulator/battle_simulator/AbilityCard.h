#pragma once
#include "UnitConfig.h"

class AbilityCard
{
private:
    unsigned short force;
    unsigned short speed;
    unsigned short endurance;

public:
    AbilityCard(
        unsigned short force = UnitConfig::DEFAULT_FORCE,
        unsigned short speed = UnitConfig::DEFAULT_SPEED,
        unsigned short endurance = UnitConfig::DEFAULT_ENDURANCE
    );

    unsigned short getForce() const;
    unsigned short getSpeed() const;
    unsigned short getEndurance() const;
};

