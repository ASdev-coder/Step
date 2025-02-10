#region Overloading

// Имена методов должны совпадать
// Другое кол-во параметров
// Другой порядок типов параметров
// Другой тип параметров
// Другие модификаторы параметров (ref, in, out)

//class Container
//{
//    public void Method(int a, int b)
//    {}

//    //public int Method(int a, int b)       // ERROR
//    //{ return 34; }

//    public void Method(double a, int b)
//    { }

//    public void Method(int a, double b)
//    { }

//    public void Method(ref int a, int b)
//    { }
//}
#endregion

#region Static

//User u = new User();
//u.Render();
//// u.maxId = 34;        // ERROR
//User.ResetMaxId();
//User.MaxId = 500;

//User u2 = new User();
//u2.Render();

//class User
//{
//    public static int maxId = 0;
//    public int id;
//    public static int MaxId 
//    {
//        get => maxId;
//        set => maxId = value;
//    }
//    public User()
//    {
//        id = ++maxId;
//    }
//    static User()
//    {
//        maxId = 101;
//    }
//    public static void ResetMaxId() => maxId = 0;
//    public void Render()
//    {
//        Console.WriteLine($"id: {id}");
//    }
//}

//internal static class Tools
//{
//    public static int MyProperty { get; set; }
//}
#endregion

#region Const / readonly / readonly struct

//User a = new User();
//// Console.WriteLine(a.DefaultRole);        // ERROR
//Console.WriteLine(User.DefaultRole);

//class User
//{
//    public const string DefaultRole = "guest"; // по сути --> public STATIC const string DefaultRole

//    public readonly string DefaultName = "no_name"; // Инициализация --> конструктор / дефолтное значение
//}


//readonly struct Shape
//{
//    public readonly int id;
//    public int Size { get; }
//    public string Title { get; init; }

//    public Shape(int size, string title)
//    {
//        Size = size;
//        Title = title;
//    }
//}

#endregion



