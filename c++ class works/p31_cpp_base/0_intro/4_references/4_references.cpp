#include <iostream>
#include <vector>


//int main()
//{
//    /*int a{ 12 };
//
//    int* ptr = &a;
//
//    int& ref = a;*/
//
//
//
//    /*int a{ 34 };
//    int& ref = a;
//
//    std::cout << &a << '\n';
//    std::cout << &ref << '\n';*/
//
//
//
//    // 1. Ссылка может быть проинициализирована ТОЛЬКО неконстантной переменной (неконстантным l-value)
//    //int a{ 45 };
//    //const int b{ 56 };
//
//    //int* const ptr1 = &a;
//    //// int* const ptr2 = &b;    // ERROR
//
//    //int& ref1 = a;
//    //// int& ref2 = b;           // ERROR
//
//
//    // 2. Ссылка должна быть проинициализирована при объявлении (создании)
//    //int a{ 34 };
//    //int& ref1 = a;
//    //// int& ref2;                      // ERROR
//
//
//    // 3. Ссылку нельзя переопределить (перебросить на другую переменную)
//    //int a{ 34 };
//    //int b{ 56 };
//
//    //int& ref = a;
//    //ref = b;            // ПРОСТО присваивание переменной a
//
//
//
//    // QUESTION *
//    // указатель на ссылку (бред, не имеющий смысла) 
//     
//  /*  int val{ 45 };
//    int& ref = val;
//
//    int* ptr = &ref;*/
//     
//     
//    // ссылка на указатель (OK)
//
//    int val{ 56 };
//    int* ptr = &val;
//    int** ptr2 = nullptr;
//
//    int*& ref = ptr;
//    int**& ref2 = ptr2;
//
//}


//struct Point
//{
//	char title;
//	int x;
//	int y;
//	int z;
//};
//
//
//void renderPoint1(Point a) // Point a{ 'A', 3, 4, 7 }		---> копирование объекта (13 byte)
//{
//	std::cout << a.title << ' ' << a.x << ' ' << a.y << ' ' << a.z << '\n';
//}
//
//void renderPoint2(Point* a) // Point* a { 0xAF76764ACEF }	---> создание указателя (8 byte)
//{
//	std::cout << a->title << ' ' << a->x << ' ' << a->y << ' ' << a->z << '\n';
//}
//
//void renderPoint3(const Point* a) // cosnt Point* a { 0xAF76764ACEF }	---> создание указателя (8 byte)
//{
//	// a->x = 100; // ERROR
//	std::cout << a->title << ' ' << a->x << ' ' << a->y << ' ' << a->z << '\n';
//}
//
//void renderPoint4(Point& a) // Point& a {p}  ---> создание ссылки (указателя) (8 byte)
//{
//	std::cout << a.title << ' ' << a.x << ' ' << a.y << ' ' << a.z << '\n';
//}
//
//void renderPoint5(const Point& a)
//{
//	// a.x = 101; // ERROR
//	std::cout << a.title << ' ' << a.x << ' ' << a.y << ' ' << a.z << '\n';
//}
//
//int main()
//{
//	Point p{ 'A', 3, 4, 7 };
//	const Point q{ 'B', 7, 7, 9 };
//
//	renderPoint1(p);
//	renderPoint1({ 'B', 7, 1, 3});
//	renderPoint2(&p);
//	renderPoint3(&p);
//	renderPoint4(p);
//	renderPoint5(p);
//
//	renderPoint1(q);
//	// renderPoint2(&q);	// ERROR
//	renderPoint3(&q);
//	// renderPoint4(q);		// ERROR
//	renderPoint5(q);
//
//}


