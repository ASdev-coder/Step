#include <iostream>
#include "Queue.h"
#include "User.h"

// QUEUE
// FIFO (FIRST in FIRST out)

// Виды очередей
// 1. Обычная очередь
// 2. Очередь с приоритетами
//      2.1 С приоритетным включением в очередь
//      2.2 С приоритетным исключением из очереди
// 3. Кольцевая очередь

// Реализация:
//      Статический массив
//      Динамический массив
//      Односвязный список
//      Двусвязный список
//      ...

// Методы
// enqueue()        // поместить в очередь
// dequeue()        // извлечь из очереди



int main()
{
    /*Queue<int> q;

    q.enqueue(34);
    q.enqueue(17);
    q.enqueue(59);
    q.enqueue(25);

    q.show();

    std::cout << "\n\n";

    std::cout << q.dequeue() << '\n';
    q.show();*/



    Queue<User> q;

    q.enqueue(User{ 101, "vasia@mail.com" });
    q.enqueue(User{ 103, "brus@mail.com" });
    q.enqueue(User{ 105, "chack@mail.com" });
    q.enqueue(User{ 107, "Jekki@mail.com" });

    q.show();

    User u1{ q.dequeue() };
    std::cout << u1 << "\n\n";

    const User& u2 = q.dequeue();
    std::cout << u2 << "\n\n";

    q.show();
}

