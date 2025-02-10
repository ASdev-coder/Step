#include <iostream>

//class Matrix
//{
//private:
//    int arr[5][5]{};
//public:
//    void operator()()
//    {
//        for (int i{}; i < 5; ++i)
//            for (int j{}; j < 5; ++j)
//                this->arr[i][j] = 0;
//        
//    }
//
//    int& operator()(int i, int j)
//    {
//        return this->arr[i][j];
//    }
//
//    void show()
//    {
//        for (int i{}; i < 5; ++i)
//        {
//            for (int j{}; j < 5; ++j)
//                std::cout << this->arr[i][j] << ' ';
//            std::cout << '\n';
//        }
//
//        std::cout << "\n\n";
//    }
//};
//
//
//
//int main()
//{
//    Matrix a;
//    a.show();
//
//    a(3, 4) = 101;
//    a.show();
//
//    a();
//    a.show();
//}




// ===== функтор =====
//class Storage
//{
//private:
//	int val;
//public:
//	Storage():
//		val{}
//	{}
//	int& operator()(int factor)
//	{
//		return this->val += factor;
//	}
//};
//
//int main()
//{
//	Storage store{};
//
//	store(4);
//	store(7);
//
//	std::cout << store(10);
//}





//class PredicateFunctor
//{
//private:
//	int count{};
//public:
//	bool operator()(int val)
//	{
//		if (val % 2 != 0)
//		{
//			++this->count;
//
//			return true;
//		}
//			
//		return false;
//	}
//
//	void reset()
//	{
//		this->count = 0;
//	}
//
//	int getCount()
//	{
//		return this->count;
//	}
//};
//
//
//int sum(int* arr, int count, PredicateFunctor& predicate)
//{
//	int result{};
//
//	for (int i{}; i < count; ++i)
//		if (predicate(arr[i]))				// :-)))
//			result += arr[i];
//
//	return result;
//}
//
//
//int main()
//{
//	int* arr = new int[5] {3, 4, 5, 1, 3};
//
//	// std::cout << sum(arr, 5) << '\n';
//
//	/*PredicateFunctor f{};
//	std::cout << f(3) << '\n';
//	std::cout << f(4) << '\n';*/
//
//
//	PredicateFunctor predicate{};
//	std::cout << "sum = " << sum(arr, 5, predicate) << '\n';
//	std::cout << "elements count = " << predicate.getCount() << '\n';
//}






