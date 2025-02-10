#include <iostream>

#pragma region Contructor

//class Point
//{
//private:
//	int x;
//	int y;
//
//public:
//	Point()		// конструктор по-умолчанию (без параметров)
//	{
//		std::cout << "call Point()\n";
//		x = 1;
//		y = -1;
//	}
//	void setInitialState(int newX, int newY)
//	{
//		x = newX;
//		y = newY;
//	}
//	void show()
//	{
//		std::cout << "x:" << x << " y:" << y << '\n';
//	}
//};
//
//int main()
//{
//	/*Point p;
//	p.setInitialState(3, 4);
//
//	int a;
//	int b{ 4 };*/
//
//	Point p;
//	p.show();
//}



//class Point
//{
//private:
//	int x;
//	int y;
//
//public:
//	Point(int initX, int initY)
//	{
//		x = initX;
//		y = initY;
//	}
//	void setInitialState(int newX, int newY)
//	{
//		x = newX;
//		y = newY;
//	}
//	void show()
//	{
//		std::cout << "x:" << x << " y:" << y << '\n';
//	}
//};
//
//int main()
//{
//	Point a(12, 13);		// :-(
//	Point b{ 7, 4 };		// :-)
//
//	b.show();
//
//}




//class Point
//{
//private:
//	int x;
//	int y;
//
//public:
//	Point(int initX, int initY)
//	{
//		x = initX < 0 ? 0 : initX;
//		y = initY < 0 ? 0 : initY;
//	}
//	void setInitialState(int newX, int newY)
//	{
//		x = newX;
//		y = newY;
//	}
//	void show()
//	{
//		std::cout << "x:" << x << " y:" << y << '\n';
//	}
//};
//
//int main()
//{
//	Point a(12, 13);		// :-(
//	Point b{ 7, 4 };		// :-)
//
//	b.show();
//
//	Point c{ -3, 5 };
//	c.show();
//
//	Point* ptr = new Point{ 4, 5 };
//
//}
#pragma endregion


#pragma region Class in class  !!!***!!!

//class Group
//{
//private:
//	std::string title;							// <10> (инициализация)
//
//public:
//	Group()										// <9> (находим соответствующий конструктор)
//	{
//		std::cout << "ctor Group()\n";					// <11> (выполнение тела конструктора)
//	}
//};
//
//class Role
//{
//private:
//	std::string title;		// <5> (инициализация)
//
//public:
//	Role()					// <4> (находим соответствующий конструктор)
//	{
//		std::cout << "ctor Role()\n";	// <6> (выполнение тела конструктора)
//	}
//};
//
//class User
//{
//private:
//	Role role;				// <3> (попытка инициализации)
//	int age;							// <7> (попытка инициализации ==> оставить без инициализации)
//	Group group;								// <8> (попытка инициализации)
//
//public:
//	User()					// <2> (находим соответствующий конструктор)
//	{
//		std::cout << "ctor User()\n";						// <12> (выполнение тела конструктора)
//	}
//};
//
//int main()
//{
//	User a;					// <1> (объявляем переменную (создаем объект))
//}

#pragma endregion


#pragma region Task_1
// Создать класс Circle
// Поля: координаты центра, радиус, цвет
// Методы: show();
// Оптимизируйте кол-во конструкторов
// Создать массив указателей на окружности со случайными значениями и вывести на экран каждую окружность (show())

#include <sstream>

//enum Color
//{
//	RED,
//	GREEN,
//	WHITE,
//};
//
//class Point
//{
//private:
//	int x;
//	int y;
//
//public:
//	Point(int newX = 0, int newY = 0)
//	{
//		x = newX;
//		y = newY;
//	}
//	// TODO:...
//	std::string getDescription()
//	{
//		std::stringstream stream;
//		stream << '(' << x << ';' << y << ')';
//
//		return stream.str();
//	}
//};
//
//class Circle
//{
//private:
//	Point position;			// Point{0, 0} после создания
//	int radius;				// мусор после создания
//	Color color;			// мусор после создания
//
//public:
//	Circle(const Point& p = {1, 1}, int r = 1, Color c = Color::RED)
//	{
//		position = p;
//		radius = r;
//		color = c;
//	}
//
//	void setRandomState()
//	{
//		
//	}
//
//	void show()
//	{
//		std::cout << "Position: " << position.getDescription() << '\n';
//		std::cout << "Radius: " << radius << '\n';
//	}
//};
//
//
//int main()
//{
//	Point p{ 1, 2 };
//
//	Circle a{};
//	Circle b{ p };
//	Circle c{ p, 12 };
//	Circle d{ p, 12, Color::WHITE };
//
//	d.show();
//
//}

#pragma endregion


#pragma region Initializator

//class TestPoint
//{
//private:
//	int x{ 10 };
//	int y;
//
//	const char title;
//
//	int statArr[3];
//
//	int dynArrCount;
//	int* dynArr;
//	
//
//
//public:
//	TestPoint(int newX, int newY, char newTitle, int count):
//		x{ newX },
//		y{ newY },
//		title{ newTitle },
//		statArr{ 4, 5, 6 },
//		dynArrCount{ count },
//		dynArr{ new int[count] {} }
//	{}
//};
//
//
//int main()
//{
//	int x{ 10 };
//
//	TestPoint a{ 3, 4, 'A', 100};
//
//
//
//
//	return 0;
//}


#pragma endregion


#pragma region Task_2

//// Написать конструктотр для User со списком инициализации
//
//class Role
//{
//private:
//	int id;
//	std::string title;
//
//public:
//	Role(int newId, std::string title = "no_title"):
//		id{ newId },
//		title{ title }
//	{}
//
//	int getId()
//	{
//		return id;
//	}
//
//	std::string& getTitle()
//	{
//		return title;
//	}
//};
//
//
//// ---- Вариант 1
////class User
////{
////private:
////	int id;
////	std::string email;
////	Role role;
////
////public:
////	User(int newId, const std::string& newEmail, Role& newRole):
////		id{ newId },
////		email{ newEmail },
////		role{ newRole.getId(), newRole.getTitle() }
////	{}
////};
////int main()
////{
////
////	Role a{ 101 };
////	Role b{ 102, "vasia@mail.com" };
////
////	return 0;
////}
//
//
//// ---- Вариант 2
//class User
//{
//private:
//	int id;
//	std::string email;
//	Role* role;
//
//public:
//	User(int newId, const std::string& newEmail, int roleId, std::string& roleTitle):
//		id{ newId },
//		email{ newEmail },
//		// role{ new Role{ roleId, roleTitle } }
//		role{ nullptr }
//	{}
//};
//
//
//
//int main()
//{
//	int* a = nullptr;
//	int* b{ nullptr };
//	int* c{ 0 };			// :-(((
//	int* d{};
//
//	std::cout << *a;
//
//	int e{};			// 0
//	bool f{};			// false
//	char g{};			// 0
//	std::string h{};	// ""
//	
//	std::string* j;					// мусор
//	std::string* i{};				// nullptr
//	std::string* k{ nullptr };		// nullptr
//
//	
//	return 0;
//}


#pragma endregion


#pragma region Делегирование конструкторам

class User
{
private:
	int id{};							// 0 после инициализации
	std::string email{ "no_email" };	// uEmail после инициализации

public:
	User(int uId, std::string uEmail) :
		email{ uEmail }
	{
		id = uId < 0 ? 0 : uId;			// присваивание
	}

	User(std::string uEmail):
		User{-1, uEmail}				// делегирование
	{}

	User(int uId):
		User(uId, "no_email")			// делегирование
	{}
};

int main()
{
	User a{ 101, "Vasia@mail.com" };
	User b{ "petya@mail.com" };
	User c{ 103 };
}

#pragma endregion












