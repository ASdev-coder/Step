#include <iostream>


//int main()
//{
//    // === 0. Обычный указатель
//    // const int a{ 34 };
//
//    /*int* ptr = &a;            // ERROR
//    *ptr = 101;*/
//
//
//    // === 1. Указатель на константное значение
//    //const int a = 12;
//    //int b = 34;
//
//    //const int* ptr1 = &a;
//    //// *ptr1 = 45;                  // ERROR
//    //ptr1 = &b;
//    //// *ptr1 = 90;                  // ERROR
//
//
//    // === 2. Константный указатель
//    //int a = 4;
//    //int b = 7;
//
//    //// int* const ptr0;                    // ERROR
//    //int* const ptr1 = &a;
//    //// ptr1 = &b;                           // ERROR
//    //*ptr1 = 34;
//
//
//    // === 3. Константный указатель на константное значение
//    //int a = 4;
//    //const int b = 7;
//
//    //const int* const ptr1 = &a;
//    //// ptr1 = &b;                           // ERROR
//    //// *ptr1 = 56;                          // ERROR
//
//
//
//
//    int a = 34;
//
//    int* ptr0 = &a;
//
//    const int* ptr1 = &a;
//
//    int* const ptr2 = &a;
//
//    const int* const ptr3 = &a;
//
//
//}





void renderArray(const int* const arr, int count)
{
	for (int i{}; i < count; ++i)
		std::cout << arr[i] << ' ';
}


int main()
{
	int* arr = new int[5] {4, 6, 7, 8, 9};

	renderArray(arr, 5);

	return 0;
}

