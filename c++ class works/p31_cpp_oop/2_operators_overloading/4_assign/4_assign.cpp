#include <iostream>

class Point
{
private:
    int* x{ nullptr };
    int* y{ nullptr };
public:
    Point(int x = 0, int y = 0):
        x{ new int{ x } },
        y{ new int{ y } }
    {}

    // copy cgtor (семантика копирования)
    Point(const Point& obj):
        x{ new int{ *obj.x } },
        y{ new int{ *obj.y } }
    {}

    // оператор присваивания копированием (семантика копирования)
    Point& operator=(const Point& obj)
    {
        if (this == &obj)
            return *this;

        *this->x = *obj.x;
        *this->y = *obj.y;

        return *this;
    }

    Point& operator=(int val)
    {
        *this->x = val;
        *this->y = val;

        return *this;
    }

    void show()
    {
        std::cout << *this->x << ' ' << *this->y << '\n';
    }

    // dtor
    ~Point()
    {
        if (this->x != nullptr)
            delete this->x;
        if (this->y != nullptr)
            delete this->y;
    }

};


int main()
{
    /*Point a{ 3, 4 };
    Point x{ 6, 8 };

    Point b{ a };

    Point c{};
    c = a = x;

    c.show();*/




    Point a{ 3, 4 };
    a = a;
    a.show();

    a = 101;
    a.show();

}


