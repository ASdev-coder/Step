#include <iostream>

// динамический массив
//int main()
//{
//    int* a = new int {10};
//
//    int* ptr = new int[5] {3, 4, 6, 8, 1};
//
//    std::cout << *(ptr + 0) << '\n';        // ptr[0]
//    std::cout << *(ptr + 1) << '\n';
//    std::cout << *(ptr + 2) << '\n';
//    std::cout << *(ptr + 3) << '\n';
//    std::cout << *(ptr + 4) << '\n';
//}




// "2-мерный" динамический "массив"
//int main()
//{
//	srand(time(0));
//	// int********* arr = new int******** [300];  // :-)))
//
//
//	// 1. Выделение памяти
//	int** ptr = new int* [5];		// new 40b	--->  address
//
//	for (int i{}; i < 5; ++i)
//	{
//		/*int* p = *(ptr + i);
//		p = new int[5];*/
//
//		ptr[i] = new int[5];
//	}
//
//
//	// 2. Заполнение значениями
//	for (int i{}; i < 5; ++i)
//	{
//		for (int j{}; j < 5; ++j)
//		{
//			ptr[i][j] = rand() % 100;		// *(*(ptr + i)+j) = rand() % 100
//		}
//	}
//
//
//	// 3. Вывод на экран
//	for (int i{}; i < 5; ++i)
//	{
//		for (int j{}; j < 5; ++j)
//		{
//			std::cout << ptr[i][j] << '\t';
//		}
//
//		std::cout << '\n';
//	}
//}



// "2-мерный" статический "массив"

//int main()
//{
//	int arr[2][3]
//	{
//		{3, 4, 5},
//		{7, 8, 9}
//	};
//
//	std::cout << arr << "\n\n";
//
//	for (int i{}; i < 2; ++i)
//	{
//		for (int j{}; j < 3; ++j)
//		{
//			std::cout << arr[i][j] << '\t';  
//		}
//
//		std::cout << '\n';
//	}
//
//	// int arr[a][b]		arr[2][3]	<--- кол-во
//	// arr[i][j]			arr[1][2]	<--- индексы
//	// 
//	// arr + (i * b * sizeof(int)) + (j * sizeof(int))
//	//					150 + (1 * 3 * 4) + (2 * 4)
//
//
//	return 0;
//}






// TASK
// Создать числовую таблицу n*m
// Заполнить значениями от 0 до 9
// Найти суммы по столбцам и сохранить их в отдельный массив

// Например:
// 2 3 5 6
// 5 1 5 6
// 1 1 2 1

// 8 5 12 13


// ф-ция для выделения памяти под 2-мерный дин массив
int** allocateTableMemeory(int rows, int cols)
{
	int** ptr = new int* [rows];

	for (int i{}; i < rows; ++i)
		ptr[i] = new int[cols];

	return ptr;
}

// ф-ция для рандома целого числа в диапазоне
int randomInt(int min = 0, int max = 9)
{
	return (rand() % (max - min + 1)) + min;
}

// ф-ция для заполнения 2-мерного массива рандомными значениями в диапазоне
void randomFillTable(int** arr, int rows, int cols, int min = 0, int max = 9)
{
	for (int i{}; i < rows; ++i)
	{
		for (int j{}; j < cols; ++j)
		{
			arr[i][j] = randomInt(min, max);
		}
	}
}

// Ф-ция для нахождения сумм по столбцам и помещение результатов в 1-мерный массив (+ возврат)
int* sumByColumns(int** arr, int rows, int cols)
{
	int* result = new int[cols];

	for (int j{}; j < cols; ++j)
	{
		int colSum{};

		for (int i{}; i < rows; ++i)
		{
			colSum += arr[i][j];
		}

		result[j] = colSum;
	}

	return result;
}

void render1DArray(int* arr, int count)
{
	for (int i{}; i < count; ++i)
		std::cout << arr[i] << ' ';
}

void render2DArray(int** arr, int rows, int cols)
{
	for (int i{}; i < rows; ++i)
	{
		for (int j{}; j < cols; ++j)
		{
			std::cout << arr[i][j] << ' ';
		}

		std::cout << '\n';
	}
}

int getIntValueFromUser()
{

}

int main()
{
	srand(time(0));

	int rows = 5;
	int cols = 10;

	int** table = allocateTableMemeory(rows, cols);
	randomFillTable(table, rows, cols, 10, 99);
	int* result = sumByColumns(table, rows, cols);

	render2DArray(table, rows, cols);
	std::cout << "-----------------\n";
	render1DArray(result, cols);
}

