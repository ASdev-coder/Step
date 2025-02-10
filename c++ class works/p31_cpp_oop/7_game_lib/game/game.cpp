#include <iostream>


// units:       Human, Elf
// units:       Archer, Warrior
//          Backpack
//          Items



class Backpack
{

};

class AbilityCard
{
private:
    int force;
    int speed;

};

class Unit
{
private:
    int hp;
    AbilityCard abilityCard;
    Role* role;



};

class Human : public Unit
{

};

class Elf : public Unit
{

};



class Role
{};
class Archer: public Role
{};
class Warrior: public Role
{};







int main()
{
    
}


