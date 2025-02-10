#include <iostream>


//class Point
//{
//public:
//    int* x;
//    int* y;
//};
//
//
//void show(Point p)
//{
//    std::cout << p.x << p.y << '\n';
//
//    Point temp{ new int{101}, new int{102} };
//
//    delete temp.x;
//    delete temp.y;
//}
//
//
//
//int main()
//{
//    Point a{ new int{3}, new int{4} };
//
//    show(a);
//}



//class User
//{
//private:
//	int id;
//	std::string email;
//	int* arr;
//
//public:
//	User(int newId, std::string newEmail):
//		id{newId},
//		email{newEmail},
//		arr{new int[10]}
//	{}
//
//	~User()									// деструктор
//	{
//		if (arr != nullptr)
//			delete[] arr;
//	}
//};
//
//void func()
//{
//	User* uPtr = new User{ 101, "vasia@mail.com" };
//	//
//	//
//
//	delete uPtr;
//
//}
//
//int main()
//{
//	func();
//}




// TASK
// 1. Код func() должен работать
// 2. Избежать утечек памяти

class Student
{
private:
	int id;
	int age;
	int gCount;
	int* grades;

public:
	Student(int newId, int newAge, int count):
		id{newId},
		age{newAge},
		gCount{count},
		grades{new int[count]}
	{}

	~Student()
	{
		std::cout << "for student " << id <<  " ---> destructor\n";

		if (grades != nullptr)
			delete[] grades;
	}
};


void func()
{
	Student a{ 101, 23, 50 };

	Student* b = new Student{ 102, 24, 48 };
	delete b;
}

int main()
{
	func();
}