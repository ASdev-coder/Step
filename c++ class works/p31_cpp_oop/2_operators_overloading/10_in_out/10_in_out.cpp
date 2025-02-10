#include <iostream>


// ==== дружественные ф-ции / классы
//
//class Point
//{
//private:
//    int x;
//    int y;
//public:
//    Point(int x, int y):
//        x{x},
//        y{y}
//    {}
//
//
//    friend void renderPoint(const Point& p);
//    friend class Rect;
//};
//
//class Rect
//{
//private:
//    //
//    //
//    Point p;
//public:
//    Rect(const Point& p):
//        p{p}
//    {}
//    void render() const
//    {
//        //
//        //
//        std::cout << this->p.x << ' ' << this->p.y << '\n';
//    }
//};
//
//
//void renderPoint(const Point& p)
//{
//    std::cout << p.x << ' ' << p.y << '\n';
//}
//
//
//int main()
//{
//    Point p{ 4, 5 };
//    renderPoint(p);
//}



// перегрузка << >>

class Point
{
private:
    int x;
    int y;
public:
    Point(int x, int y):
        x{x},
        y{y}
    {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p);
    friend std::istream& operator>>(std::istream& in, Point& p);
};


std::ostream& operator<<(std::ostream& out, const Point& p)
{
    out << '(' << p.x << ';' << p.y << ")\n";
    
    return out;
}

std::istream& operator>>(std::istream& in, Point& p)
{
    in >> p.x;
    in >> p.y;

    return in;
}

int main()
{
    Point p{ 3, 4 };
    std::cout << p << '\n';

    Point b{ 0, 0 };
    std::cin >> b;
    std::cout << b << '\n';
}
