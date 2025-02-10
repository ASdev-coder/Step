#include <iostream>
#include "Unit.h"
#include "Bow.h"

int main()
{
    // Things

    Bow a{ "elf bow", 100, 15, 20, 50, 5 };
    a.setWeight(10);



    Unit u{ {2, 2}, 100, 1, 50 };
    u.pushThingToBackpack(&a);
    
    // u.putOn(u.popThingFromBackpack(a.getId()));
    u.putOnFromBackpack(a.getId());


    std::cout << ' ';
}


