#include <iostream>
// НАСЛЕДОВАНИЕ (является)


#pragma region Intro
//// базовый, родительский, родитель, суперкласс
//class Human
//{
//public:
//    std::string name;
//    int age;
//    bool isMale;
//
//    Human(const std::string& name = "no_name", int age = 18, bool isMale = true) :
//        name{ name },
//        age{ age },
//        isMale{ isMale }
//    {}
//
//    const std::string& getName() const
//    {
//        return this->name;
//    }
//    int getAge() const
//    {
//        return this->age;
//    }
//    void show() const
//    {
//        std::cout << "name: " << this->name << " age: " << this->age << '\n';
//    }
//};
//
//// производный, наследник
//class User : public Human
//{
//public:
//    std::string email;
//    std::string password;
//    std::string token;
//};
//
//class Student : public Human
//{
//public:
//    std::string group;
//};
//
//class Admin : public User
//{
//public:
//    std::string permition;
//};
//
//
//int main()
//{
//    Human h{ "Vasia", 23, true };
//    h.show();
//
//    User u{};
//    u.show();
//}
#pragma endregion


#pragma region Построение объектов

//class Base
//{
//public:
//	int val;
//	std::string title = "";
//
//	Base(int val = 1) :
//		val{ val }
//	{
//		std::cout << "Base ctor\n";
//	}
//};
//
//class Child : public Base
//{
//public:
//	double dVal;
//	bool flag = true;
//
//	Child(double dVal = 1.0) :
//		dVal{ dVal }
//	{
//		std::cout << "Child ctor\n";
//	}
//};
//
//
////class ChildComp
////{
////public:
////	Base base;
////	double dVal;
////	ChildComp(double dVal = 1.0) :
////		dVal{ dVal }
////	{
////		std::cout << "Child ctor\n";
////	}
////};
//
//
//int main()
//{
//	// Base a{};
//
//	Child b{};
//	b.val = 15;
//
//	/*ChildComp c{};
//	c.base.val = 12;*/
//
//}




//class A
//{
//public:
//	A()
//	{
//		std::cout << "A ctor\n";
//	}
//};
//
//class B: public A
//{
//public:
//	B()
//	{
//		std::cout << "B ctor\n";
//	}
//};
//
//class C: public B
//{
//public:
//	C()
//	{
//		std::cout << "C ctor\n";
//	}
//};
//
//class D: public C
//{
//public:
//	D()
//	{
//		std::cout << "D ctor\n";
//	}
//};
//
//int main()
//{
//	std::cout << "A creation:\n";
//	A a;
//
//	std::cout << "B creation:\n";
//	B b;
//
//	std::cout << "C creation:\n";
//	C c;
//
//	std::cout << "D creation:\n";
//	D d;
//}

#pragma endregion


#pragma region Вызов базового конструктора

//class Base
//{
//public:
//	int a;
//
//	Base(int a):											// 5
//		a{a}												// 6
//	{
//		std::cout << "Base ctor\n";							// 7
//	}
//	int getVal() const
//	{
//		return this->a;
//	}
//};
//
//
//// Выделяется память под объект Child (12 bytes)		// 2
//
//class Child : public Base
//{
//private:
//	double b;
//public:
//
//	Child(int a, double b):								// 3
//		Base { a },										// 4
//		b{ b }														// 8
//	{
//		std::cout << "Child ctor\n";								// 9
//		this->a = 45;
//	}
//	void render() const
//	{
//		std::cout << "a = " << this->a << " b = " << this->b << '\n';
//	}
//};
//
//
//int main()
//{
//	Child c{ 10, 12.3 };									// 1
//	c.render();
//
//	Base b{ 34 };
//	// b.render();		// ERROR
//
//
//	return 0;
//}

#pragma endregion


#pragma region Task1
// Создать класс Student (email, grades(int*)), который базируется на классе Human (name, age)

//class Human
//{
//private:
//	std::string name;
//	int age;
//
//public:
//	Human(const std::string& name, int age):
//		name{ name },
//		age { age }
//	{
//		std::cout << "Human ctor\n";
//	}
//
//	std::string getName() const
//	{
//		return this->name;
//	}
//	int getAge() const
//	{
//		return this->age;
//	}
//	~Human()
//	{
//		std::cout << "Human dctor\n";
//	}
//
//};
//
//class Student: public Human
//{
//private:
//	const int DEFAULT_COUNT = 10;
//
//	std::string email;
//	int count;
//	int* grades;
//
//public:
//	Student(const std::string& name, int age, const std::string& email):
//		Human { name, age },
//		email {email},
//		count { Student::DEFAULT_COUNT },
//		grades { new int [Student::DEFAULT_COUNT] }
//	{
//		std::cout << "Student ctor\n";
//	}
//
//	Student(const Student& obj):
//		Human{ obj.getName(), obj.getAge() },
//		email{ obj.email },
//		count{ obj.count },
//		grades{ new int[obj.count] }
//	{
//		for (int i{}; i < this->count; ++i)
//			this->grades[i] = obj.grades[i];
//	}
//
//	~Student()
//	{
//		if (this->grades != nullptr)
//			delete[] grades;
//		std::cout << "Student dctor\n";
//	}
//};
//
//int main()
//{
//	Student* s = new Student{ "Vasia", 23, "vasia@mail.com" };
//
//	delete s;
//
//
//}

#pragma endregion


#pragma region Task2 HW
// Написать систему классов для будущей игры
// Классы: Unit, Point, Archer, Warrior
// Класс Unit сделать базовым
// Класс Point использовать как указатель внутри базового класса





#pragma endregion




