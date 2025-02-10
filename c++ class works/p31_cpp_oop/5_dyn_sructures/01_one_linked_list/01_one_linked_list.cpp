#include <iostream>
#include "List.h"
#include "User.h"

void f()
{
    List<int> list;

    list.pushToTail(12);
    list.pushToTail(7);
    list.pushToTail(23);
    list.pushToTail(10);

    list.render();
}


int main()
{
    // f();


    /*List<int>* list = new List<int>{};
    list->render();

    list->pushToTail(12);
    list->render();

    list->pushToTail(7);
    list->render();

    list->pushToTail(23);
    list->render();

    list->pushToTail(10);
    list->render();

    list->pushToHead(4);
    list->render();

    list->pushToHead(14);
    list->render();

    delete list;*/




    //List<int> list;

    //list.pushToTail(12);
    //list.pushToTail(7);
    //list.pushToTail(23);
    //list.pushToTail(10);

    //list.render();

    //list[2] = 100;
    //list.render();

    //list[0] = -1;
    //list.render();

    //std::cout << list[2];






    //List<int> list;

    //list.pushToTail(12);
    //list.pushToTail(7);
    //list.pushToTail(23);
    //list.pushToTail(10);

    //list.render();

    //List<int> copy{ list };
    //copy.render();



    List<User> users;
    users.pushToTail(User{ 10 });
    users.pushToTail(User{ 15 });
    users.pushToTail(User{ 8 });

}


