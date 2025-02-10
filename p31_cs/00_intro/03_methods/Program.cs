
//int Sum(int a, int b)
//{
//    return a + b;
//}

////void Render(string message)
////{
////    Console.WriteLine(message);
////}
//void Render(string message) => Console.WriteLine(message); // Сокращенная запись метода

//Console.WriteLine(Sum(3, 4));


// ===== parameters ======

//void Sum(int a, int b) => Console.WriteLine(a + b);
//Sum(3, 4);

//void Render(string message, bool colored = false)
//{
//    if (colored)
//        Console.ForegroundColor = ConsoleColor.Red;

//    Console.WriteLine(message);

//    Console.ResetColor();
//}

//Render("Vasia");
//Render("Petya", true);


//void Render(int id, string email = "no_email", int age = 18)
//{
//    Console.WriteLine($"id: {id} email: {email} age: {age}");
//}

//Render(101, "no_email", 23);
//Render(age: 25, id: 102);


// ==== returns ====
//string GetClearEmail(string email)
//{
//    return email.ToLower();
//}

//Console.WriteLine(GetClearEmail("VaSiA@mail.com"));

//string GetClearEmail(string email) => email.ToLower();

//Console.WriteLine(GetClearEmail("VaSiA@mail.com"));

// ==== val/ref parameters ====
// --- Передача парметра по значению ---

//void Render(int val) => Console.WriteLine(val);
//int a = 34;
//Render(a);



// --- Передача по ссылке (ref) ---

// C++
//void Modify(int& val)
//{
//    val = 100;
//}
//int main()
//{
//    int val = 34;
//    Modify(val);
//}

// C#
//void Modify(ref int val)
//{
//    val = 100;
//}

//int val = 34;
//Modify(ref val);


// C++
//class User { };
//void Modify2(User& user)
//{

//}
//int main()
//{
//    User* u = new User();
//    Modify2(*u);
//}

// C#
//void Modify2(User user)
//{

//}
//User u = new User();
//Modify3(ref u);

// C++
// class User{};

// void Modify2(User*& user)
// {}

// int main()
// {
//     User* u = new User();
//     Modify2(u);
// }

// C#
//void Modify3(ref User user)
//{

//}

//User u1 = new User();
//Modify3(ref u1);

//class User
//{

//}


// --- Передача по ссылке (out) ---
//void Calc(int a, int b, out int result)
//{
//    int q = a + b;

//    result = q;     // !!!
//}

////int result;
////Calc(2, 4, out result);
////Console.WriteLine(result);


//Calc(2, 4, out int result);
//Console.WriteLine(result);


// --- Передача по ссылке (in) ---
//void Calc(in int a, in int b, out int result)
//{
//    // a = 45; // ERROR
//    result = a + b;
//}


// --- --- Передача по ссылке (ref readonly) ---
//void Modify(ref readonly int val)
//{

//}














