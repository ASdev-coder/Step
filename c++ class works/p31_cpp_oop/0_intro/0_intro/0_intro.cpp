#include <iostream>


#pragma region intro
//struct Point
//{
//    int x;
//    int y;
//};
//
//class Point2d       // определение класса
//{
//public:
//    int x;          // поле класса (переменная-член класса)
//    int y;
//
//    void show()     // метод класса (функция-член класса)
//    {
//        std::cout << x << ' ' << y << '\n';
//    }
//};
//
//
//int main()
//{
//    Point a{3, 4};
//    Point b{5, 6};
//
//    Point2d c{ 1, 2 };      // объект класса, экземпляр класса, "инстанс" класса
//    Point2d d{ 8, 9 };
//
//    Point* ptr1;
//    Point2d* ptr2;
//
//    c.show();
//
//
//}
#pragma endregion


#pragma region examples
//class Teacher
//{
//
//};
//
//class Student
//{
//public:
//	int id;
//	std::string name;
//	std::string email;
//	int age;
//
//	void render()
//	{
//		std::cout << id << '\t' << name << '\t' << email << '\t' << age << '\n';
//	}
//
//	void setAge(int newAge)
//	{
//		age = newAge;
//	}
//
//	int getAge()
//	{
//		return age;
//	}
//};
//
//int main()
//{
//	Student a;
//	a.id = 101;
//	a.name = "Chack Norris";
//	a.email = "norris@mail.com";
//	a.age = 34;
//
//	a.render();
//
//	a.setAge(45);
//
//	a.render();
//
//	int age = a.getAge();
//
//	Student b{ 102, "Brus Willis", "willis@mail.com", 60 };
//	b.render();
//
//	Teacher t;
//	
//
//
//	return 0;
//}

#pragma endregion


#pragma region Модификаторы доступа (public, private, protected)

//class User
//{
//public:				// публичные
//	int publicVal;
//	void publicMethod()
//	{
//
//	}
//
//private:
//	int privateVal;
//
//protected:
//	int protectedVal;
//};
//
//
//int main()
//{
//	User u;
//	u.publicMethod();
//	// u.privateVal = 45;		// ERROR
//
//	return 0;
//}



//class User
//{
//private:
//	int id;
//	int age;
//
//	int generateRandomId()
//	{
//		return rand() % 1000;
//	}
//
//public:
//	void setId(int newId)					// сеттер
//	{
//		if (newId < 0)
//		{
//			id = generateRandomId();
//			return;
//		}
//			
//		id = newId;
//	}
//	void setAge(int newAge)					// сеттер
//	{
//		if (newAge < 18 || newAge > 150)
//		{
//			age = -1;
//			return;
//		}
//
//		age = newAge;
//	}
//	int getId()								// геттер
//	{
//		return id;
//	}
//	int getAge()							// геттер
//	{
//		//
//		//
//		return age;
//	}
//	bool isAdult()							// инспектор
//	{
//		return age >= 18;
//	}
//	void show()
//	{
//		std::cout << "id: " << id << " age: " << age << '\n';
//	}
//};
//
//int main()
//{
//	User a;
//	a.setId(101);
//	a.setAge(20);
//
//	a.show();
//
//	std::cout << a.getId() << ' ' << a.getAge() << '\n';
//
//	/*if (a.getAge() < 18)
//		std::cout << "permission denied\n";
//	else
//		std::cout << "hello user!\n";*/
//
//	if (! a.isAdult())
//		std::cout << "permission denied\n";
//	else
//		std::cout << "hello user!\n";
//
//}

#pragma endregion


#pragma region example

struct Point
{
	int x;
	int y;
};

class Rectangle
{
private:
	int w;
	int h;
	Point position;

public:
	void setSize(int newW, int newH)
	{
		w = newW;
		h = newH;
	}
	void setPosition(const Point& p)		// (Point p)	/  (int x, int y)	/  (const Point* p)   /   (const Point& p)
	{
		position.x = p.x;
		position.y = p.y;
	}
	long calcArea()
	{
		return h * w;
	}
	long calcPerimeter()
	{
		return 2 * (w + h);
	}

};

int main()
{
	int a;
	Rectangle rect;
	rect.setSize(80, 60);
	rect.setPosition(Point{ 3, 4 });

	std::cout << "Area: " << rect.calcArea() << '\n';
	std::cout << "Perimeter: " << rect.calcPerimeter() << '\n';


	int* b = new int;
	Rectangle* rect2 = new Rectangle;

	std::cout << *b << '\n';
	std::cout << (*rect2).calcPerimeter() << '\n';
	std::cout << rect2->calcPerimeter() << '\n';
}

#pragma endregion







