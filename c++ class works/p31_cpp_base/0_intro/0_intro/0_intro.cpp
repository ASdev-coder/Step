#include <iostream>




//void sum(int a, int b)
//{
//    std::cout << a + b << '\n';
//}
//
//
//
//int main()
//{
//    int q = 4;
//    int w = 6;
//
//    sum(q, w);
//
//    return 0;
//}





//int main()
//{
//	/*int val = 12;
//	int* p = &val;
//
//	std::cout << val << '\n';
//	std::cout << p << '\n';
//	std::cout << *p << '\n';*/
//
//
//	/*int val = 34;
//	int* ptr = &val;
//
//	std::cout << ptr << '\n';*/
//
//	return 0;
//}





void render(int* arr, int count)
{
	for (int i{}; i < count; ++i)
		std::cout << arr[i] << '\t';
}

int main()
{
	//int a = 4; // инициализация копированием
	//int b(5);  // 
	//int c{ 6 };// унифицированная инициализация		:-)

	//int d;
	//d = 56;		// присваивание

	//int c{};	// инициализация значением по-умолчанию
	//int******** ptr{};





	//int arr[5]{ 12, 24, 35, 17, 98 };		// arr --> указатель int* arr

	//std::cout << arr << '\n';
	//std::cout << *arr << '\n';

	//render(arr, 5);

	





	/*int arr[5]{ 12, 24, 35, 17, 98 };

	std::cout << arr[2];*/


	//int val = 45;
	//int* ptr = &val;

	//std::cout << ptr << '\n';		// 124
	//std::cout << ptr + 1 << '\n';	// ptr + sizeof(int) * n ==> 128
	//std::cout << ptr + 10 << '\n';	// ptr + sizeof(int) * n ==> 164







	int arr[5]{ 12, 24, 35, 17, 98 };
	std::cout << arr << "\n\n";
	for (int i{}; i < 5; ++i)
		std::cout << *(arr + i) << '\n';		// arr[i]		===>    *(arr + i)


	std::cout << "";



	return 0;
}

