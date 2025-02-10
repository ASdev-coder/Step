
#region Inheritance
// Ограничения
// 1. Только одиночное наследование (:-) object; interfaces)
// 2. Модификатор доступа наследника - такой же или более строгий
// 3. Можно запретить наследоваться от класса (sealed)
// 4. Запрещено наследование от статического класса


//Admin admin = new Admin()
//{
//    Email = "vasia@mail.com",
//    Age = 23,
//};

//Admin admin = new Admin();

//internal class User
//{
//    private string email = string.Empty;
//    public string Email { get => email; set => email = value; }
//    public int Age { get; set; }
//    public User()
//    {
//        Email = "no_email";
//        Age = 18;
//    }
//    public User(string email, int age)
//    {
//        Email = email;
//        Age = age;
//    }
//}

//internal class Admin : User
//{
//    public Admin() :
//        base("petya@mail.com", 45)
//    { }
//    public Admin(string email, int age) :
//        base(email, age)
//    { }
//    public Admin(string email) :
//        this(email, 20)
//    { }
//    public void Render()
//    {
//        Console.WriteLine($"Email from Admin: {Email}");
//    }
//}

#endregion

#region Type casting

// --- upcasing (восходящее преобразование, "упаковка объекта") 
//Warrior warrior = new Warrior(100, 120);
//warrior.Hp = 150;
//warrior.Force = 200;

//Unit unit = warrior;        // <-- upcasting
//unit.Hp = 150;
//// unit.Force = 200;        // ERROR

//object obj = warrior;
//// obj.Hp = 150;           // ERROR
//// obj.Force = 200;        // ERROR

// --- downcasting (нисходящее преобразование, "распаковка объекта")
//Archer archer = new Archer(70, 15);
//Unit unit = archer;

//Archer archer2 = (Archer)unit;          // <-- downcasting
//// Warrior warrior2 = (Warrior)unit;    // ERROR
//archer2.ArrCount = 50;
//archer.Hp = 200;

//Unit unit = new Archer(70, 15);
//Archer archer = (Archer)unit;

//object obj = new Archer(70, 15);
//Unit unit = (Unit)obj;
//Archer archer = (Archer)obj;
// Warrior warrior = (Warrior)obj;      // ERROR

//--- as / is ---

//Unit unit = new Archer(100, 10);

//Archer a = (Archer)unit;                // Возможен EXCEPTION  !!!
//Archer? b = unit as Archer;             // EXCEPTION не выбрасывается, но возможен null

//b?.Render();

//if (b is not null)
//    b.Render();

////if (unit is Archer)
////{
////    Archer archer = (Archer)unit;
////    archer.ArrCount = 12;
////}
//// >>> EQUALS <<<
//if (unit is Archer archer)
//{
//    archer.ArrCount = 12;
//}

//class Unit
//{
//    public int Hp { get; set; }
//    public Unit(int hp)
//    {
//        Hp = hp;
//    }
//    public void Render() => Console.WriteLine($"hp: {Hp}");
//}

//class Archer: Unit
//{
//    public int ArrCount { get; set; } = 0;
//    public Archer(int hp, int arrCount)
//        : base(hp)
//    {
//        ArrCount = arrCount;
//    }
//}

//class Warrior: Unit
//{
//    public int Force { get; set; } = 0;
//    public Warrior(int hp, int force)
//        : base(hp)
//    {
//        Force = force;
//    }
//}

#endregion

#region virtual / override

//Student student = new Student(101);
//student.Render();

//User user = new Student(101);
// user.Render();
//user.Age = 34;

//User a = new User(101);
//a.Age = 23;
//a.Render();

//User a = new Student(101);
//a.Age = 23;
//a.Render();

//class User
//{
//    public int Id { get; set; }
//    public virtual int Age { get; set; }
//    public User(int id)
//    { 
//        Id = id; 
//    }
//    public virtual void Render() => Console.WriteLine($"Render from User: {Id}");
//}

//class Student: User
//{
//    // public override int Age { get; set; }

//    public override int Age
//    {
//        get
//        {
//            Console.WriteLine("Age get() from  Student");
//            return base.Age;
//        }
//        set
//        {
//            Console.WriteLine("Age set() from  Student");
//            base.Age = value;
//        }
//    }

//    public Student(int id):
//        base(id)
//    { }

//    public override sealed void Render()
//    {
//        base.Render();
//        Console.WriteLine($"Render from Student: {Id}");
//    }
//}

//class SuperStudent : Student
//{
//    public SuperStudent(int id) : base(id)
//    {}

//    //public override void Render()                               // ERROR
//    //{
//    //    base.Render();
//    //    Console.WriteLine($"Render from SuperStudent: {Id}");
//    //}
//}
#endregion

#region Hiding

//Admin admin = new Admin(101, "vasia@mail.com");
//// admin.Render();
//User user = new Admin(102, "petya@mail.com");
//// user.Render();

//admin.Email = "dima@mail.com";
//user.Email = "kolia@mail.com";


Console.WriteLine(User.Pi);
Console.WriteLine(Admin.Pi);

class User
{
    public int Id { get; set; }
    public readonly static int mxAge = 18;
    public const double Pi = 3.14;
    public string Email { get; set; } = "no_email";
    public User(int id, string email)
    {
        Id = id;
        Email = email;
    }
    public void Render()
    {
        Console.WriteLine($"User: {Email}");
    }
}

class Admin : User
{
    public new readonly static int mxAge = 18;
    public new const double Pi = 3.1415;
    public Admin(int id, string email) : base(id, email)
    {}

    // public string Email { get; set; }        // FU FU FU :-(((

    public new string Email
    {
        get => $"admin...{base.Email}";
        set
        {
            Console.WriteLine($"Admin setEmail with {value}");
            base.Email = value;
        }
    }

    public new void Render()
    {
        // base.Render();
        Console.WriteLine($"Admin: {Email}");
    }
}




#endregion

