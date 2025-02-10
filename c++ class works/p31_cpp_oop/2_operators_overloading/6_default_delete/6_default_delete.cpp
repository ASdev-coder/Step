#include <iostream>

// == default

//class Box
//{
//private:
//    int val;
//
//public:
//    Box() = default;
//
//    Box(int val):
//        val{val}
//    {}
//
//    Box(const Box& obj) = default;
//
//    Box(Box&& obj) = default;
//
//    Box& operator=(const Box& obj) = default;
//
//    Box& operator=(Box&& obj) = default;
//
//    ~Box() = default;
//
//    // int getValue() = default;            // ERROR
//};




// == delete

//class Point
//{
//private:
//    double x;
//    double y;
//public:
//    Point() = delete;
//
//    Point(int) = delete;
//
//    Point(double val):
//        x{val},
//        y{val}
//    {}
//
//    void set(double val)
//    {
//        this->x = val;
//        this->y = val;
//    }
//    void set(int) = delete;
//    void set(char) = delete;
//};
//
//
//
//
//int main()
//{
//    // Box a{};
//
//    // Point a;         ERROR
//
//    /*Point b{ a };
//    a = b;*/
//
//
//    // Point a{ 3.4 };
//
//    // Point b{ 5 };       // ERROR
//
//
//    Point a{3.0};
//
//    a.set(4.5);
//    // a.set(4);            // ERROR
//    // a.set('*');          // ERROR
//
//
//}






//class Box
//{
//private:
//    Box() = default;
//};
//
//int main()
//{
//    Box* a = new Box{};
//}
