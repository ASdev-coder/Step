#include <iostream>

// STACK
// ==========
// LIFO (last IN first OUT)
// Можно реализовать на:
//      Статический массив
//      Динамический массив
//      Односвязный список
//      Двусвязный список

// push()       // поместить элемент на вершину (в конец) стека
// pop()        // извлечь элемент с вершины стека
// peak()       // просмотр вершины стека
// isEmpty()
// getCount()
// getCapacity();


template<typename T, int step = 10>
class Stack
{
private:
    int count;
    T* arr;
    int capacity;

    bool isNotAllocateted() const
    {
        return this->arr == nullptr;
    }

    bool isFull() const
    {
        return this->count == this->capacity;
    }

    void reallocateMemory()
    {
        if (this->isNotAllocateted())
        {
            this->arr = new T[step];
            this->capacity = step;

            return;
        }

        this->capacity = this->count + step;

        T* temp = new T[this->capacity];

        for (int i{}; i < this->count; ++i)
            temp[i] = this->arr[i];

        delete[] this->arr;

        this->arr = temp;
    }

public:
    Stack():
        count{ 0 },
        arr{ nullptr },
        capacity { 0 }
    {}

    Stack(const Stack& obj) :
        count{ obj.count },
        arr{ new T[obj.capacity] },
        capacity{ obj.capacity }
    {
        for (int i{}; i < obj.count; ++i)
            this->arr[i] = obj.arr[i];
    }

    Stack(Stack&& obj) :
        count{ obj.count },
        arr{ obj.arr },
        capacity{ obj.capacity }
    {
        obj.arr = nullptr;
    }

    Stack& operator=(const Stack& obj);
    Stack& operator=(Stack&& obj);

    void push(const T& val)
    {
        if (this->isNotAllocateted() || this->isFull())
            this->reallocateMemory();

        this->arr[this->count] = val;

        ++this->count;
    }

    const T& pop()
    {
        if (! this->isEmpty())
        {
            --this->count;

            return this->arr[this->count];
        }

        return T{}; // TODO: throw....
    }
    const T& peak();

    bool isEmpty() const
    {
        return this->count == 0;
    }
    int getCount();
    int getCapacity();

    void show()
    {
        std::cout << "capacity = " << this->capacity << '\n';
        std::cout << "count = " << this->count << '\n';
        std::cout << "arr: " << '\n';

        for (int i{}; i < this->count; ++i)
            std::cout << this->arr[i] << ' ';
        std::cout << "\n\n";

    }

    ~Stack()
    {
        if (this->arr != nullptr)
            delete[] arr;
    }
};


int main()
{
    /*Stack<int, 100> a;
    Stack<double> b;*/

    Stack<int> stack;

    stack.push(5);
    stack.push(7);
    stack.push(1);
    stack.push(2);

    stack.show();

    std::cout << stack.pop() << '\n';
    stack.show();
    std::cout << stack.pop() << '\n';
    std::cout << stack.pop() << '\n';
    stack.show();
}

