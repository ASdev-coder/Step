
#region Generic

//User a = new User() { Id = 101, Email = "vasia@mail.com" };
//User b = new User() { Id = "identity", Email = "petya@mail.com" };

//int idA = (int)a.Id;
//string? idB = b.Id as string;
//// int ccc = (int)b.Id;         ERROR

//class User
//{
//    public object? Id { get; set; }
//    public string Email { get; set; } = string.Empty;
//}



//User<int> a = new User<int>() { Id = 101, Email = "vasia@mail.com" };
//User<string> b = new User<string>() { Id = "identity", Email = "petya@mail.com" };
//// b = a;

//int idA = a.Id;
//string idB = b.Id;
//class User<T>
//{
//    public T Id { get; set; }
//    public string Email { get; set; } = string.Empty;
//}



//User<int, Role<int>> user = new User<int, Role<int>>(101, "vasia@mail.com")
//{ 
//    Role = new Role<int>() { Id = 505 },
//};

//class Role<T>
//{
//    public T Id { get; set; }
//}

//class User<K, T>
//{
//    public K Id { get; set; }
//    public string Email { get; set; }
//    public T Role { get; set; }
//    public User(K id, string email)
//    {
//        Id = id;
//        Email = email;
//    }
//}

#endregion

#region Static

//User<int> a = new User<int>()
//{ 
//    Id = 101,
//    Name = "Vasia",
//};
//User<int>.maxId = 1;

//User<string> b = new User<string>()
//{
//    Id = "1000",
//    Name = "petya",
//};
//User<string>.maxId = "0000";

//class User<T>
//{
//    public static T maxId;
//    public T Id { get; set; }
//    public string Name { get; set; }
//}

#endregion

#region Multiple types parameters

//User<int, string, bool> user = new User<int, string, bool>()
//{ 
//    TProp = 1,
//    KProp = "vasia",
//    UProp = true,
//};
//class User<T, K, U>
//{
//    public T TProp { get; set; }
//    public K KProp { get; set; }
//    public U UProp { get; set; }
//}

#endregion

#region Generic methods

//Logger logger = new Logger();

//Logger.Write<int>(123);
//Logger.Write<Entry>(new Entry() { Data = "Vasia" });

//class Entry
//{
//    public string Data { get; set; }
//    public override string ToString()
//    {
//        return $"DATA: {Data}";
//    }
//}
//class Logger
//{
//    //
//    //
//    public static void Write<T>(T value)
//    {
//        Console.WriteLine(value);
//    }
//}

#endregion

#region Generic methods constraints

//// Renderer.Render<string>("Vasia");        // ERROR
//Renderer.Render<Archer>(new Archer(100));

//class Unit
//{
//    public int Hp { get; set; }
//    public Unit(int hp) => Hp = hp;
//}
//class Archer : Unit
//{
//    public Archer(int hp) : base(hp)
//    {}
//}
//class Warrior : Unit
//{
//    public Warrior(int hp) : base(hp)
//    { }
//}
//class Renderer
//{ 
//    public static void Render<T>(T obj)
//        where T : Unit
//    {
//        Console.WriteLine($"Renderer: hp: {obj.Hp}");
//    }
//}

#endregion

#region Generic Type constraints

//Renderer<Archer>.Render(new Archer(100));

//class Unit
//{
//    public int Hp { get; set; }
//    public Unit(int hp) => Hp = hp;
//}
//class Archer : Unit
//{
//    public Archer(int hp) : base(hp)
//    { }
//}
//class Warrior : Unit
//{
//    public Warrior(int hp) : base(hp)
//    { }
//}
//class Renderer<T>
//    where T : Unit
//{
//    public static void Render(T obj)
//    {
//        Console.WriteLine($"Renderer: hp: {obj.Hp}");
//    }
//}

#endregion

#region Constraints types
// where T : _1_, _2_, _3_

// _1_
// Конкретный класс     (T -> конкретный тип или его наследники)
// или
// class                (T -> ссылочный тип)
// или
// struct               (T -> значимый тип)

// _2_
// Конкретный интерфейс

// _3_
// new()                (T -> должен иметь конструктор по-умолчанию)


//Logger<Document> logger = new Logger<Document>();

//class Document
//{
//    public int Id { get; set; }
//    public Document() { }
//    public Document(int id) => Id = id;
//}

//class Logger<T>
//    // where T : class, new()
//    // where T : new()
//    where T: class
//{
//    public void Execute()
//    {
//        // T obj = new T();
//    }
//}

//class Compressor<T, K>
//    //where T : class, new()
//    //where K : Logger<T>

//    where T : class
//    where K : Logger<string>
//{}

#endregion

#region Inheritance

//class Unit<T>
//    where T : new()
//{
//    public T Id { get; set; }
//    public Unit(T id) => Id = id;
//}

// 1. Наследник с тем же типом
//class Archer<Kotik> : Unit<Kotik>
//    where Kotik : new()
//{
//    public Archer(Kotik id) :
//        base(id)
//    { }
//}
//Archer<int> archer = new Archer<int>(23);
//Unit<int> unit = new Unit<int>(23);
//Unit<int> unit2 = new Archer<int>(23);


// 2. Необобщённый(нетипизированный) наследник
//class Warrior : Unit<int>
//{
//    public Warrior(int id) 
//        : base(id)
//    {}
//}
//Warrior archer = new Warrior(23);
//Unit<int> unit = new Unit<int>(23);
//Unit<int> unit2 = new Warrior(23);


// 3. Типизация наследника отдельным типом
//class Archer<T> : Unit<int>
//{
//    public Archer(int id) 
//        : base(id)
//    {}
//}
//Archer<string> archer = new Archer<string>(23);
//Unit<int> unit = new Unit<int>(23);
//Unit<int> unit2 = new Archer<bool>(23);



// 4. Совмещение разных вариантов
//class Archer<T, K> : Unit<T>
//    where T : new()
//{
//    public Archer(T id) 
//        : base(id)
//    {}
//}
//Archer<int, string> archer = new Archer<int, string>(23);

#endregion
