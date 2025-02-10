#include <iostream>

// Проблема 1: конфликт имён

//class A
//{
//public:
//    A() { std::cout << "A ctor\n"; }
//    void test()
//    {
//        std::cout << "testA\n";
//    }
//};
//
//class B
//{
//public:
//    B() { std::cout << "B ctor\n"; }
//    void test()
//    {
//        std::cout << "testB\n";
//    }
//};
//
//class C : public A, public B
//{
//public:
//    C() { std::cout << "C ctor\n"; }
//    void testC()
//    {
//        std::cout << "testC\n";
//    }
//};
//
//
//
//
//
//int main()
//{
//    C c;
//    // c.test();
//}




// Проблема 2: Алмаз смерти (ромб безысходности)
class Device
{
public:
	int points;

	Device()
	{
		std::cout << "Device ctor\n";
	}
};

class Printer : public Device
{

};

class Scaner : public Device
{

};

class MFU : public Printer, public Scaner
{

};






