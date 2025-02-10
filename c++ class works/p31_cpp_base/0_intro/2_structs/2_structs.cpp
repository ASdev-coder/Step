#include <iostream>


#pragma region intro
//struct Point
//{
//    int x;
//    int y;
//};
//
//struct User
//{
//    int id;
//    std::string* email;
//    std::string* password;
//    short age;
//};
//
//struct Unit
//{
//    int hp;
//    std::string* title;
//    Point* position;
//    User* user;
//};
//
//
//
////int main()
////{
////    /*int a;
////    Point b;
////    User c;
////    
////    int* aPtr = new int;
////    Point* bPtr = new Point;
////    User* cPtr = new User;
////
////    Unit d;*/
////
////
////    std::string email = "vasia@mail.com";
////    std::string password = "123123123";
////
////    User a;
////    int b;
////
////    a.id = 101;
////    a.email = &email;
////    a.password = &password;
////    a.age = 34;
////
////    b = 12;
////    a = { 102, nullptr, &password, 23 };
////
////    User* aPtr = &a;
////    (*aPtr).age = 45;
////    aPtr->email = &email;
////
////}
//
//
//// Functions
////int add(int a, int b)
////{
////    int result = a + b;
////
////    return result;
////}
////
////int f1(int* a, int** b, double c)           // int* a = 0x876238764; .....
////{
////    std::cout << *a;
////
////    return 12;
////}
////
////int** f2()
////{
////
////}
////
////
////int main()
////{
////    /*int x = 34;
////    int y = 23;
////
////
////    add(23, 17);
////
////    add(x, y);
////
////    f1(new int{12}, new int*, 2.3);*/
////
////
////    std::cout << 10 + add(23, 12);
////
////    int** ptr = f2();
////
////}
//
//
////void badFunction()
////{
////    Point* p = new Point;
////    //
////    //
////}
////
////
////Point* createRandomPoint()
////{
////    Point* p = new Point;
////
////    p->x = rand() % 10;
////    p->y = rand() % 10;
////
////    return p;
////}
////
////int main()
////{
////    srand(time(0));
////
////    Point* ptr = createRandomPoint();
////
////}
//
//
//int main()
//{
//
//    Point p{ 2, 5 };
//
//    Point* ptr = &p;
//
//    std::cout << ptr->x << '\n';
//    // std::cout << ptr[0];                // ERROR:   *(ptr + 0)
//
//    Point t0{ ptr[0] };
//    Point t1{ *ptr };
//    Point t2{ p };
//    Point t3 = { 2, 5 };
//
//
//
//
//
//}
#pragma endregion



#pragma region Task
// Описать структуру Rectangle (прямоугольник).  
// Создать массив из 10 прямоугольников со случайными размерами. 
// Написать ф-цию которая возвращает указатель на прямоугольник с максимальной площадью


enum Color
{
	RED,
	GREEN,
	BLACK,
};

struct Rectangle
{
	Color color;
	int width;
	int height;
};

int randomInt(int min = 0, int max = 9)
{
	return (rand() % (max - min + 1)) + min;
}

Rectangle* getRandomRect(int min, int max)
{
	
	return new Rectangle{ (Color)randomInt(0, 2), randomInt(min, max), randomInt(min, max) };
}

Rectangle** generateRandomRectArray(int count, int min, int max)
{
	Rectangle** result = new Rectangle* [count];

	for (int i{}; i < count; ++i)
	{
		result[i] = getRandomRect(min, max);
	}

	return result;
}

int calcArea(Rectangle* rect)
{
	return rect->width * rect->height;
}

Rectangle* getRectWithMaxArray(Rectangle** arr, int count)
{
	int max{ 0 };
	Rectangle* rect{ nullptr };

	for (int i{}; i < count; ++i)
	{
		int area = calcArea(arr[i]);

		if (area > max)
		{
			max = area;
			rect = arr[i];
		}
	}


	return rect;
}

void renderRect(Rectangle* rect)
{
	std::cout << "rect --> w: " << rect->width << "; h: " << rect->height << '\n';
}



int main()
{
	srand(time(0));

	int count = 15;

	Rectangle** arr = generateRandomRectArray(count, 3, 15);

	for (int i{}; i < count; ++i)
		renderRect(arr[i]);


	std::cout << "\n\n-----------\n";
	Rectangle* rect = getRectWithMaxArray(arr, count);
	renderRect(rect);

}


#pragma endregion


