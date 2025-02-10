#include <iostream>

//class Parent
//{
//public:
//    int f_public;
//private:
//    int f_private;
//protected:
//    int f_protected;
//};
//
//class Child : public Parent
//{
//public:
//    Child()
//    {
//        this->f_public = 34;
//        // this->f_private = 12;  // ERROR
//        this->f_protected = 15;
//    }
//};
//
//
//int main()
//{
//    Parent p;
//
//    p.f_public = 5;
//    // p.f_private = 3; // ERROR
//    // p.f_protected = 7; // ERROR
//
//    Child c;
//    c.f_public = 56;
//}




// Спецификаторы наследования


// == PUBLIC (открытое, публичное наследование)
// Parent				Child
// ---------------------------------
// public				public
// private				------
// protected			protected


// == PRIVATE (закрытое наследование)
// Parent				Child
// ---------------------------------
// public				private
// private				------
// protected			private


// == PROTECTED (защищённое наследование)
// Parent				Child
// ---------------------------------
// public				protected
// private				------
// protected			protected


class Unit
{
private:
	int id;
protected:
	int level;
public:
	int hp;
};

class Human : protected Unit
{
	//	protected:
	//		int level;
	//	protected:
	//		int hp;
};

class Warrior : public Human
{
	//	protected:
	//		int level;
	//	protected:
	//		int hp;
public:
	Warrior()
	{
		this->hp = 45;
		this->level = 2;
	}
};


int main()
{
	Human h;
}