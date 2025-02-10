
#region Intro
//interface IRenderable { }
//interface IMovable { }
//interface ILogger { }
//interface IShape { }

// Может содержать:
// 1. Методы
// 2. Свойства
// 3. События
// 4. Индексаторы
// 5. Статика (константы)

//interface ILogger
//{
//    public const double Pi = 3.14;
//    public static int count = 0;
//    public void Log(string message);
//    public string Path { get; set; }
//}

//interface IRenderable
//{
//    private static int count = 0;
//    public void Render()
//    {
//        Console.WriteLine("render");
//    }
//    public int Ratio { get => 0; }
//    public int Count
//    {
//        get => count;
//        set => count = value;
//    }
//}

#endregion

#region Example_1

//Unit a = new Unit();
//a.Render();
//IRenderable b = new Unit();
//b.Render();

//IRenderable a = new Mesh();
//a.WriteLogs();
//IRenderable b = new Unit();
//b.WriteLogs();
//Mesh mesh = new Mesh();
//// mesh.WriteLogs();           // ERROR

//interface IRenderable
//{
//    public void Render();
//    public void WriteLogs()
//    {
//        Console.WriteLine("IRenderable: WriteLogs()");
//    }
//}
//class Unit: IRenderable
//{
//    public void Render()
//    {
//        Console.WriteLine("Unit: Render()");
//    }
//    public void WriteLogs()
//    {
//        Console.WriteLine("Unit: WriteLogs()");
//    }
//}
//class Mesh: IRenderable
//{
//    public void Render()
//    {
//        Console.WriteLine("Mesh: Render()");
//    }
//}

#endregion

#region Multiple implementation

//Db db = new Db();
//if (db is IWritable)
//    db.Write();

//IWritable a = db;
//a.Write();
//IComparable b = db;
//b.Compare(null);

//interface IWritable
//{
//    public void Write();
//}
//interface IComparable
//{
//    public bool Compare(object? obj);
//}

//class Db : IWritable, IComparable
//{
//    public bool Compare(object? obj)
//    {
//        return true;
//    }
//    public void Write()
//    {
//        Console.WriteLine("Db: Write()");
//    }
//    public void Save()
//    {
//        Console.WriteLine("Db: Save()");
//    }
//}

#endregion

#region Implicit / Explicit realization (неявная / явная реализация)
//Db db = new Db();
//db.Write();
//IWritable a = db;
//a.Write();
//ISaver b = db;
//b.Write();


//Db db = new Db();
//// db.Write();             // ERROR
//IWritable a = new Db();
//a.Write();
//ISaver b = new Db();
//b.Write();


//Db db = new Db();

//((IWritable)db).Write();        // :-(((

//if (db is IWritable dbWritable) // ;-)))
//    dbWritable.Write();

//IWritable b = db;               // :-)


//interface IWritable
//{
//    public void Write();
//}
//interface ISaver
//{
//    public void Write();
//}

//class Db: IWritable, ISaver
//{
//    // === Общая неявная реализация (одна на несколько интерфейсов)
//    // является членом класса
//    //public void Write()
//    //{
//    //    Console.WriteLine("Common realization...");
//    //}

//    // === Явная реализация (каждая для своего интерфейса)
//    // не являются членами класса
//    // не может содержать модификатора
//    void IWritable.Write()
//    {
//        Console.WriteLine("Write() from Db:IWritable");
//    }
//    void ISaver.Write()
//    {
//        Console.WriteLine("Write() from Db:ISaver");
//    }
//}

#endregion

#region Modificators

//Mesh m = new Mesh();
//m.Execute();
//IRender r = m;


//interface IRender
//{
//    // int Level { get; set; }
//    // public void Show();
//    protected void Execute();
//}

//class Mesh : IRender
//{
//    public void Execute()
//    {
//        Console.WriteLine("Common");

//    }
//    void IRender.Execute()
//    {
//        Console.WriteLine("Explicit");
//    }
//}

#endregion

#region Interfaces and inheritance
// Изменение поведения базового класса, который реализует интерфейс
// 1. Переопределение (virtual --> override)
// 2. Сокрытие метода (     --> new)
// 3. Повторная реализация интерфейса
// 4. Явная реализация

//interface IRenderable
//{
//    public void Render();
//    public void Calc();
//    public void Update();
//}

//abstract class Mesh: IRenderable
//{
//    public abstract void Render();
//    public virtual void Calc()
//    {
//        Console.WriteLine("Mesh.Calc()");
//    }
//    public void Update()
//    {
//        Console.WriteLine("Mesh.Update()");
//    }
//}

//class Unit : Mesh
//{
//    public override void Render()
//    {
//        Console.WriteLine("Unit.Render()");
//    }

//    public override void Calc()
//    {
//        Console.WriteLine("Unit.Calc()");
//    }

//    public new void Update()
//    {
//        Console.WriteLine("Mesh.Update()");
//    }
//}


//// === Повторная реализация интерфейса

//Mesh a = new Mesh();
//a.Render();

//IRendarable b = new Unit();
//b.Render();

//Unit c = new Unit();
//c.Render();

//interface IRendarable
//{
//    public void Render();
//}
//class Mesh : IRendarable
//{
//    public void Render()
//    {
//        Console.WriteLine("Mesh.Render()");
//    }
//}
//class Unit: Mesh, IRendarable
//{
//    public new void Render()
//    {
//        Console.WriteLine("Unit.Render()");
//    }
//}





// === Явная реализация интерфейса

//Mesh a = new Mesh();
//a.Render();

//IRendarable b = new Unit();
//b.Render();

//Unit c = new Unit();
//c.Render();

//interface IRendarable
//{
//    public void Render();
//}
//class Mesh : IRendarable
//{
//    public void Render()
//    {
//        Console.WriteLine("Mesh.Render()");
//    }
//}
//class Unit : Mesh, IRendarable
//{
//    // public override void Render() => Console.WriteLine("");
//    public new void Render() => Console.WriteLine("Unit.Render()");
//    void IRendarable.Render() => Console.WriteLine("Unit.Render() explicit");
//}

#endregion

#region Inheritance

//interface IWritable
//{
//    public void Write() => Console.WriteLine("IWritable.Write()");
//}

//interface IFileSaver: IWritable
//{
//    void Save();
//    public new void Write() => Console.WriteLine("IFileSaver.Write()");
//}

//class FileManager : IFileSaver
//{
//    public void Save()
//    {
//        throw new NotImplementedException();
//    }

//    public void Write()
//    {
//        throw new NotImplementedException();
//    }
//    void IFileSaver.Save()
//    { }
//    void IFileSaver.Write()
//    { }
//    void IWritable.Write()
//    { }
//}


#endregion

#region Interface as constraints

//FileManager<File> m = new FileManager<File>();

//interface IWritable
//{
//    public void Write();
//}
//interface ISavable
//{
//    string? Path { get; }
//}

//class File : IWritable, ISavable
//{
//    public string? Path { get; }
//    public File(string? path)
//    {
//        Path = path;
//    }
//    public void Write()
//    {
//        Console.WriteLine("File was written");
//    }
//}

//class FileManager<T>
//    where T: IWritable, ISavable
//{
//    public  void Save(T data)
//    {
//        data.Write();
//        Console.WriteLine(data.Path);
//    }
//}

#endregion

#region Generic interfaces

//IAuthenticator<string> auth1 = new Author("identity");
//// IAuthenticator<int> auth2 = new Author("identity");      ERROR

//interface IAuthenticator<T>
//{
//    T Id { get; }
//}

//class User<T> : IAuthenticator<T>
//{
//    public T Id { get; }
//    public User(T id) => Id = id;
//}

//class Admin : IAuthenticator<string>
//{
//    public string Id { get; }
//    public Admin(string id) => Id = id;
//}
//class Author : User<string>
//{
//    public Author(string id) 
//        : base(id)
//    {}
//}

#endregion

#region IComparable

// List<User> users = new List<User>()
// {
//     new User()  { Id =  101, Email = "eamil_1@mail.com", Age = 34},
//     new User()  { Id =  102, Email = "eamil_2@mail.com", Age = 21},
//     new User()  { Id =  103, Email = "eamil_3@mail.com", Age = 32},
//     new User()  { Id =  104, Email = "eamil_4@mail.com", Age = 20},
// };

// users.Sort();

// foreach (User user in users)
//     Console.WriteLine(user);


// == :-(
//class User: IComparable
//{
//    public int Id { get; set; }
//    public string? Email { get; set; }
//    public int Age { get; set; }

//    public int CompareTo(object? obj)
//    {
//        if (obj is User user)
//        {
//            //if (Age < user.Age)
//            //    return -1;
//            //else if (Age > user.Age)
//            //    return 1;
//            //else
//            //    return 0;

//            //return Age - user.Age;
//            return user.Age - Age;
//        }

//        throw new NotImplementedException();
//    }

//    public override string ToString()
//    {
//        return $"{Id} {Email} {Age}";
//    }
//}


// == :-)
// class User : IComparable<User>
// {
//     public int Id { get; set; }
//     public string? Email { get; set; }
//     public int Age { get; set; }

//     public int CompareTo(User? user)
//     {
//         if (user is null)
//             throw new NotImplementedException();

//         return Age - user.Age;
//     }

//     public override string ToString()
//     {
//         return $"{Id} {Email} {Age}";
//     }
// }

#endregion

#region IComparer

//List<User> users = new List<User>()
// {
//     new User()  { Id =  101, Email = "eamil_1@mail.com", Age = 34},
//     new User()  { Id =  102, Email = "eamil_2@mail.com", Age = 21},
//     new User()  { Id =  103, Email = "eamil_3@mail.com", Age = 32},
//     new User()  { Id =  104, Email = "eamil_4@mail.com", Age = 20},
// };

//// users.Sort(new UserAgeComparer());
//users.Sort(new UserIdComparer());

//foreach (User user in users)
//    Console.WriteLine(user);


//class User
//{
//    public int Id { get; set; }
//    public string? Email { get; set; }
//    public int Age { get; set; }
//    public override string ToString()
//    {
//        return $"{Id} {Email} {Age}";
//    }
//}

//class UserAgeComparer : IComparer<User>
//{
//    public int Compare(User? x, User? y)
//    {
//        if (x is null && y is null)
//            return 0;

//        return x.Age - y.Age;
//    }
//}
//class UserIdComparer : IComparer<User>
//{
//    public int Compare(User? x, User? y)
//    {
//        if (x is null && y is null)
//            return 0;

//        return x.Id - y.Id;
//    }
//}


#endregion

#region ICloneable

//User a = new(101, "Vasia@mail.com", new Role("admin"));

//if (a is ICloneable)
//{
//    User? b = a.Clone() as User;
//}

//class Role
//{
//    public string Title { get; set; }
//    public Role(string title) => Title = title;
//}

//class User: ICloneable
//{
//    public int Id { get; set; }
//    public string Email { get; set; }
//    public Role? Role { get; set; }
//    public User(int id, string email, Role? role)
//    {
//        Id = id;
//        Email = email;
//        Role = role;
//    }

//    public object Clone()
//    {
//        return new User(Id, Email, Role != null ? new Role(Role.Title) : null);
//    }
//}

#endregion

#region invariance (as it is) / covariance (up to types, out) / contrvariance (down to types, in)

//// =========================== обобщённый интерфейс с инвариантным универсальным параметром =============================

//MySqlManager a = new MySqlManager();

//IConnectionManager<MySqlConnection> manager_0 = a;

//IConnectionManager<MySqlConnection> manager_1 = new MySqlManager();

//// IConnectionManager<Connection> manager_2 = new MySqlManager();       // ERROR

//class Connection
//{
//    public string? ConnectionString { get; set; }
//    public Connection(string? connectionString) => ConnectionString = connectionString;
//}
//class MySqlConnection : Connection
//{
//    public MySqlConnection(string? connectionString) 
//        : base(connectionString)
//    {}
//}
//class SqlServerConnection : Connection
//{
//    public SqlServerConnection(string? connectionString) 
//        : base(connectionString)
//    {}
//}

//interface IConnectionManager<T>
//{
//    public T CreateConnection(string connectionString);
//}
//class MySqlManager : IConnectionManager<MySqlConnection>
//{
//    public MySqlConnection CreateConnection(string connectionString)
//    {
//        return new MySqlConnection(connectionString);
//    }
//}
//class SqlServerManager : IConnectionManager<SqlServerConnection>
//{
//    public SqlServerConnection CreateConnection(string connectionString)
//    {
//        return new SqlServerConnection(connectionString);
//    }
//}




//// =========================== обобщённый интерфейс с ковариантным универсальным параметром =============================

//MySqlManager manager_0 = new MySqlManager();
//MySqlConnection conn_0 = manager_0.CreateConnection("config");

//IConnectionManager<MySqlConnection> manager_1 = new MySqlManager(); // <-- invariance
//MySqlConnection conn_1 = manager_1.CreateConnection("config");

//IConnectionManager<Connection> manager_2 = manager_0;               // <-- covariance
//Connection conn_2 = manager_2.CreateConnection("config");


//List<IConnectionManager<Connection>> list = new List<IConnectionManager<Connection>>()
//{
//    new MySqlManager(),
//    new SqlServerManager(),
//};

//foreach (IConnectionManager<Connection> m in list)
//    Console.WriteLine(m.CreateConnection("config").ConnectionString);


//class Connection
//{
//    public string? ConnectionString { get; set; }
//    public Connection(string? connectionString) => ConnectionString = connectionString;
//}
//class MySqlConnection : Connection
//{
//    public MySqlConnection(string? connectionString)
//        : base(connectionString)
//    { }
//}
//class SqlServerConnection : Connection
//{
//    public SqlServerConnection(string? connectionString)
//        : base(connectionString)
//    { }
//}

//interface IConnectionManager<out T>
//{
//    public T CreateConnection(string connectionString);
//}
//class MySqlManager : IConnectionManager<MySqlConnection>
//{
//    public MySqlConnection CreateConnection(string connectionString)
//    {
//        return new MySqlConnection(connectionString);
//    }
//}
//class SqlServerManager : IConnectionManager<SqlServerConnection>
//{
//    public SqlServerConnection CreateConnection(string connectionString)
//    {
//        return new SqlServerConnection(connectionString);
//    }
//}





// =========================== обобщённый интерфейс с контрвариантным универсальным параметром =============================

//object m0 = new MySqlManager();

//MySqlManager m1 = new MySqlManager();

//IConnectionManager<Connection> m2 = new MySqlManager();

//IConnectionManager<MySqlConnection> m3 = new MySqlManager();    // <-- contrvariance
//m3.SetConnection(new MySqlConnection("msql conn string"));

//IConnectionManager<SqlServerConnection> m4 = new MySqlManager();    // <-- contrvariance
//m4.SetConnection(new SqlServerConnection("sqlsrv conn string"));

//class Connection
//{
//    public string? ConnectionString { get; set; }
//    public Connection(string? connectionString) => ConnectionString = connectionString;
//}
//class MySqlConnection : Connection
//{
//    public MySqlConnection(string? connectionString)
//        : base(connectionString)
//    { }
//}
//class SqlServerConnection : Connection
//{
//    public SqlServerConnection(string? connectionString)
//        : base(connectionString)
//    { }
//}

//interface IConnectionManager<in T>
//{
//    public void SetConnection(T conn);
//}
//class MySqlManager : IConnectionManager<Connection>
//{
//    public void SetConnection(Connection conn)
//    {
//        Console.WriteLine($"MySqlManager: {conn.ConnectionString}");
//    }
//}
//class SqlServerManager : IConnectionManager<Connection>
//{
//    public void SetConnection(Connection conn)
//    {
//        Console.WriteLine($"SqlServerManager: {conn.ConnectionString}");
//    }
//}

#endregion

#region Совместное использование

FileLogger f0 = new FileLogger();

ILogger<A, B> f1 = new FileLogger();        // <-- ОСНОВНОЙ ИНВАРИАНТНЫЙ СЛУЧАЙ !!!

ILogger<A, A> f2 = new FileLogger();

ILogger<B, A> f3 = new FileLogger();


class A
{ };

class B: A
{}

interface ILogger<in T, out K>
{
    public void Log(T val);
    K SendMessage(string msg);
}

class FileLogger : ILogger<A, B>
{
    public void Log(A val)
    {
        throw new NotImplementedException();
    }

    public B SendMessage(string msg)
    {
        throw new NotImplementedException();
    }
}

#endregion
