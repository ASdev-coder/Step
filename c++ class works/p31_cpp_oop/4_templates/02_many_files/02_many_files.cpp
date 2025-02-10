
#include "User.h"



// #define PI 3.14;         //  <--- макрос
#define FIRST
// #define SECOND



// #include <iostream>
// #pragma once
// #ifdef / #ifndef / #endif / #define




int main()
{
    User u{};
    u.render();

    std::cout << "test";

#ifdef PI
    std::cout << PI;
#endif

#ifdef FIRST
    std::cout << "first\n";
#endif // FIRST

#ifdef SECOND
    std::cout << "second";
#endif // SECOND


}




