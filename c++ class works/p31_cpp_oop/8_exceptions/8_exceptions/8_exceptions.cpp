#include <iostream>


// 1. Примитивный

//enum Result
//{
//    OK,
//    ERROR,
//};
//
//double sub(int a, int b)
//{
//    if (b == 0)
//        return 0;
//    
//    return a / b;
//}
//
//int get(int* arr, int count, int id)
//{
//    if (id > count - 1)
//        return Result::ERROR;
//
//    return arr[id];
//}
//
//int main()
//{
//   /* std::cout << "begin\n";
//    sub(3, 0);
//    std::cout << "end\n";*/
//
//    int* arr = new int[3] {2, 4, 7};
//    std::cout << get(arr, 3, 5);
//}


// 2. Код возврата по ссылке (указателю)

//enum DivCode 
//{
//	DIV_SUCCESS = 0,
//	DIV_BY_ZERO = 2,
//	DIV_BY_ONE = 4,
//	DIV_BY_MINUS_ONE = 8,
//};
//
//double div(int a, int b, DivCode& code)
//{
//	if (b == 0)
//		code = DivCode::DIV_BY_ZERO;
//	else if (b == 1)
//		code = DivCode::DIV_BY_ONE;
//	else if (b == -1)
//		code = DivCode::DIV_BY_MINUS_ONE;
//
//	if (code > 0)
//		return 0;
//
//	return static_cast<double>(a) / b;
//}
//
//int main()
//{
//	DivCode code;
//
//	double res = div(4, 1, code);
//
//	if (code > 0)
//		std::cout << "ERROR: " << code << '\n';
//	else
//		std::cout << "SUCCESS res = " << res << '\n';
//
//}


// 3. Возврат контейнера с результатом

//enum Code
//{
//	OK,
//	INTERNAL_ERROR,
//	DIV_BY_ZERO,
//	FILE_NOT_FOUND,
//	INDEX_OUT_OF_RANGE,
//};
//
//template<typename T>
//class FunctionResult
//{
//public:
//	bool success;
//	T result;
//	Code code;
//	std::string message;
//
//	FunctionResult(T result, bool success = true, Code code = Code::OK, const std::string& message = "") :
//		success{success},
//		result{result},
//		code{code},
//		message{message}
//	{}
//
//};
//
//FunctionResult<double> divide(int a, int b)
//{
//	if (b == 0)
//		return FunctionResult<double>(0, false, Code::DIV_BY_ZERO, "Divide by zero");
//
//	if (b == 1)
//		return FunctionResult<double>(0, false, Code::INTERNAL_ERROR, "Divide by one");
//
//	double result = static_cast<double>(a) / b;
//
//	return FunctionResult<double>(result);
//}
//
//FunctionResult<std::string> render(const std::string& content)
//{
//	if (content.length() <= 3)
//		return FunctionResult<std::string>("", false, Code::INTERNAL_ERROR, "String length is too short");
//
//	std::cout << "CONTENT: " << content << '\n';
//
//	return FunctionResult<std::string>("");
//}
//
//int main()
//{
//	/*FunctionResult<double> res = divide(3, 2);
//
//	if (!res.success)
//		std::cout << "ERROR: " << res.message << " CODE: " << res.code << '\n';
//	else
//		std::cout << "RESULT: " << res.result << '\n';*/
//
//
//
//	FunctionResult<std::string> res = render("vas");
//	if (!res.success)
//		std::cout << "ERROR: " << res.message << " CODE: " << res.code << '\n';
//	else
//		std::cout << "OK" << '\n';
//}


// 4. Exceptions processing (throw, try, catch)

// throw: 
//			1. останавливается нормальный поток выполнения ф-ции
//			2. "формируется" объект исключения (значение после throw)
//			3. поис блока try "вокруг в рамках ф-ции", поиск catch для обработки исключения

//int main()
//{
//	std::cout << "start\n";
//	//
//	//
//
//	throw 1;
//
//	//
//	//
//
//	std::cout << "end\n";
//}

//int main()
//{
//	try
//	{
//		std::cout << "start\n";
//		//
//		//
//
//		// throw 1;
//
//		std::string ex = "vasia error";
//		throw ex;
//
//		//
//		//
//
//		std::cout << "end\n";
//	}
//	catch (int ex)
//	{
//		std::cout << "int ERROR: " << ex << '\n';
//	}
//	catch (const std::string& ex)
//	{
//		std::cout << "string ERROR: " << ex << '\n';
//	}
//
//	std::cout << "END OF MAIN\n";
//}

//enum Code
//{
//	OK,
//	INTERNAL_ERROR,
//	DIV_BY_ZERO,
//	FILE_NOT_FOUND,
//	INDEX_OUT_OF_RANGE,
//};
//
//double divide(int a, int b)
//{
//	if (b == 0)
//		throw Code::DIV_BY_ZERO;
//
//	if (b == 1)
//		throw Code::INTERNAL_ERROR;
//
//	return static_cast<double>(a) / b;
//}
//
//void render(const std::string& content)
//{
//	if (content.length() <= 3)
//		throw std::string("String length is too short");
//
//	std::cout << "CONTENT: " << content << '\n';
//}
//
//int main()
//{
//	try
//	{
//		int res = divide(2, 0);
//		// render("va");
//	}
//	catch (const std::string& ex)
//	{
//		std::cout << "ERROR: " << ex << '\n';
//	}
//	catch (Code ex)
//	{
//		std::cout << "ERROR: " << ex << '\n';
//	}
//	
//	return 0;
//}

//void f1()
//{
//	std::cout << "f1() start\n";
//	throw 13;
//	std::cout << "f1() end\n";
//}
//void f2()
//{
//	std::cout << "f2() start\n";
//	try
//	{
//		f1();
//	}
//	catch (int ex)
//	{
//		std::cout << "catch in f2(): " << ex << '\n';
//	}
//	std::cout << "f2() end\n";
//}
//void f3()
//{
//	std::cout << "f3() start\n";
//	f2();
//	std::cout << "f3() end\n";
//}
//void f4()
//{
//	std::cout << "f4() start\n";
//	f3();
//	std::cout << "f4() end\n";
//}
//void f5()
//{
//	std::cout << "f5() start\n";
//	f4();
//	std::cout << "f5() end\n";
//}
//
//int main()
//{
//	std::cout << "main() start\n";
//	try
//	{
//		f5();
//	}
//	catch (int ex)
//	{
//		std::cout << "catch in main(): " << ex << '\n';
//	}
//
//	std::cout << "main() end\n";
//}

// ---- exceptions classes
//class User;
//
//class AccountException
//{
//private:
//	int requestedSum;
//	int accountState;
//	std::string message;
//	User* user;
//public:
//	AccountException(int sum, int state, User* user, const std::string& message = "") :
//		requestedSum{sum},
//		accountState{state},
//		message{message},
//		user{user}
//	{}
//
//	int getSum() const { return this->requestedSum; }
//	int getstate() const { return this->accountState; }
//	std::string getMessage() const { return this->message; }
//	User* getUser() const { return this->user; }
//};
//
//class WithdrawException : public AccountException
//{
//public:
//	WithdrawException(int sum, int state, User* user, const std::string& message = "") :
//		AccountException{sum, state, user, message}
//	{}
//};
//
//class User
//{
//private:
//	std::string email;
//public:
//	User(const std::string& email) :
//		email{ email }
//	{}
//	std::string getEmail()
//	{
//		return this->email;
//	}
//};
//
//class Account
//{
//private:
//	int id;
//	int val;
//	User* user;
//public:
//	Account(int id, int val, User* user):
//		id{id},
//		val{val},
//		user{user}
//	{}
//	void push(int sum)
//	{
//		this->val += sum;
//	}
//	int take(int sum)
//	{
//		/*if (this->val < sum)
//			throw AccountException{ sum, this->val, this->user, "Operation blocked..." };*/
//
//		if (this->val < sum)
//			throw WithdrawException{ sum, this->val, this->user, "Operation blocked..." };
//
//		this->val -= sum;
//
//		return this->val;
//	}
//};
//
//int main()
//{
//	User u{ "vasia@mail.com" };
//
//	Account acc{ 101101, 1000, &u };
//
//	try
//	{
//		acc.take(2000);
//	}
//	catch (WithdrawException& ex)
//	{
//		std::cout << "Telegram --> " << ex.getUser()->getEmail() << "Body: " << "ERROR: " << ex.getMessage() << "sum: " << ex.getSum() << '\n';
//	}
//	catch (AccountException& ex)
//	{
//		std::cout << "Email to: " << ex.getUser()->getEmail() << "Body: " << "ERROR: " << ex.getMessage() << "sum: " << ex.getSum() << '\n';
//	}
//}

// ==== std::exception
// std::exception


// ==== повторный throw ===
//try
//{
//
//}
//catch (const std::exception&)
//{
//	//
//	//
//	throw;
//}


// ==== универсальный catch ====
//void f()
//{
//	throw 12;
//}
//
//int main()
//{
//	try
//	{
//		f();
//	}
//	catch (...)
//	{
//		std::cout << "Sorry bratan...";
//	}
//}










