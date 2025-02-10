#include "AbilityCard.h"

AbilityCard::AbilityCard(unsigned short force, unsigned short speed, unsigned short endurance) :
    force{ force },
    speed{ speed },
    endurance{ endurance }
{}

unsigned short AbilityCard::getForce() const
{
    return this->force;
}

unsigned short AbilityCard::getSpeed() const
{
    return this->speed;
}

unsigned short AbilityCard::getEndurance() const
{
    return this->endurance;
}

