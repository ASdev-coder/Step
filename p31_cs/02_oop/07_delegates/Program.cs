
#region Intro


//MyDelegate md = Process;
//md = User.Render;
//md += Process;
//md -= Process;

//md();

//void Process()
//{
//    Console.WriteLine("Process()");
//}

//class User
//{
//    public static void Render()
//    {
//        Console.WriteLine("User.Render()");
//    }
//}

//delegate void MyDelegate();



//OpDelegate del = Add;
//del += Mul;

//del(3, 4);

//void Add(int a, int b) => Console.WriteLine($"a + b = {a + b}");
//void Mul(int a, int b) => Console.WriteLine($"a * b = {a * b}");

//delegate void OpDelegate(int a, int b);





//OpDelegate del = Add;
//del += Mul;
//// del += Test;        // ERROR

//int res = del(3, 4);
//Console.WriteLine(res);

//int Add(int a, int b) => a + b;
//int Mul(int a, int b) => a * b;
//void Test(int a, int b) => Console.WriteLine(a + b);

//delegate int OpDelegate(int a, int b);






//OpDelegate del1 = Add;
//OpDelegate del2 = Mul;
//OpDelegate del3 = del1 + del2;
//del3(3, 4);

//int Add(int a, int b) => a + b;
//int Mul(int a, int b) => a * b;

//delegate int OpDelegate(int a, int b);




//OpDelegate del = Add;
//Console.WriteLine(del is null);
//del -= Add;
//Console.WriteLine(del is null);

////if (del is not null)
////    del(3, 4);

//// del.Invoke(3, 4);

//del?.Invoke(3, 4);


//void Add(int a, int b) => Console.WriteLine($"a + b = {a + b}");
//void Mul(int a, int b) => Console.WriteLine($"a * b = {a * b}");

//delegate void OpDelegate(int a, int b);





//void Execute(int a, int b, OperationDelegate del)       // (......, OperationDelegate del = Add)
//{
//    Console.WriteLine($"Operation result: {del?.Invoke(a, b)}");
//}

//int Add(int a, int b) => a + b;
//int Mul(int a, int b) => a * b;

//Execute(3, 4, Mul);

//delegate int OperationDelegate(int a, int b);





//OperationDelegate GetDelegate(Op operation)
//{
//    OperationDelegate del = operation switch
//    {
//        Op.Add => Add,
//        Op.Mul => Mul,
//        Op.Div => Div,
//        _ => throw new NotSupportedException(),
//    };

//    return del;
//}

//int Add(int a, int b) => a + b;
//int Mul(int a, int b) => a * b;
//int Div(int a, int b) => a / b;

//Console.WriteLine(GetDelegate(Op.Mul)?.Invoke(3, 4));


//enum Op
//{
//    Add,
//    Div,
//    Mul,
//}
//delegate int OperationDelegate(int a, int b);


#endregion

#region Practice_1

//NotificationHandler handler = SendEmail;
//handler += SendSms;
//handler += SendTelegram;

//handler -= SendSms;

//handler?.Invoke("Hello Vasia");

//void SendEmail(string message) => Console.WriteLine($"Email: {message}");
//void SendTelegram(string message) => Console.WriteLine($"Telegram: {message}");
//void SendSms(string message) => Console.WriteLine($"Sms: {message}");


//delegate void NotificationHandler(string message);

#endregion

#region Generic delegates

//// OperationDelegate<double, int> a;

//OperationDelegate<string, int> b = Process;
//// Console.WriteLine(b(4, 5));
//Console.WriteLine(b?.Invoke(4, 5));

//string Process(int a, int b) => $"a + b = {a + b}";


//void Method1(OperationDelegate<double, string> op)
//{

//}

//string Exec(User a, User b)
//{
//    return $"{a}\t{b}";
//}
//OperationDelegate<string, User>? Method2()
//{
//    OperationDelegate<string, User> res = Exec;

//    return res;
//}

//delegate T OperationDelegate<T, P>(P a, P b);
//class User
//{

//}

#endregion

#region Practice_2 Observer dp

// ===== Классическая реализация паттерна Observer ======

//INotifier emailNotifier = new EmailNotifier();
//INotifier telegramNotifier = new TelegramNotifier();
//INotifier smsNotifier = new SmsNotifier();

//Account acc = new Account(1000);

//acc.AddMoneyNotifiers.Add(smsNotifier);
//acc.WithdrawSuccessNotifiers.Add(emailNotifier);
//acc.WithdrawFailedNotifiers.Add(telegramNotifier);
//acc.WithdrawFailedNotifiers.Add(smsNotifier);

//acc.Add(500);
//acc.Withdraw(700);
//acc.Withdraw(1000);



//interface INotifier
//{
//    void Notify(string message);
//}
//class TelegramNotifier : INotifier
//{
//    public void Notify(string message)
//    {
//        Console.WriteLine($"Telegram: {message}");
//    }
//}
//class EmailNotifier : INotifier
//{
//    public void Notify(string message)
//    {
//        Console.WriteLine($"Email: {message}");
//    }
//}
//class SmsNotifier : INotifier
//{
//    public void Notify(string message)
//    {
//        Console.WriteLine($"Sms: {message}");
//    }
//}


//class Account
//{
//    private int sum;
//    public List<INotifier> AddMoneyNotifiers { get; } = new List<INotifier>();
//    public List<INotifier> WithdrawSuccessNotifiers { get; } = new List<INotifier>();
//    public List<INotifier> WithdrawFailedNotifiers { get; } = new List<INotifier>();

//    public Account(int sum)
//    {
//        this.sum = sum;
//    }

//    public void Add(int val)
//    {
//        sum += val;

//        foreach (INotifier notifier in AddMoneyNotifiers)
//            notifier.Notify($"Added: {val}");
//    }

//    public void Withdraw(int val)
//    {
//        if (val > sum)
//        {
//            foreach (INotifier notifier in WithdrawFailedNotifiers)
//                notifier.Notify($"ERROR: {val}");

//            return;
//        }

//        sum -= val;

//        foreach (INotifier notifier in WithdrawSuccessNotifiers)
//            notifier.Notify($"Withdrawn: {val}");
//    }
//}



// ==== Реализация паттерна Observer на делегатах ====

//Account acc = new Account(1000);

//acc.RegisterAddMoneyHandler(SmsNotifier.Notify);
//acc.RegisterWithdrawSuccessHandler(EmailNotifier.Notify);
//acc.RegisterwithdrawFailedHandler(TelegramNotifier.Notify);
//acc.RegisterwithdrawFailedHandler(SmsNotifier.Notify);

//acc.Add(500);
//acc.Withdraw(700);
//acc.Withdraw(1000);


//class TelegramNotifier
//{
//    public static void Notify(string message)
//    {
//        Console.WriteLine($"Telegram: {message}");
//    }
//}
//class EmailNotifier
//{
//    public static void Notify(string message)
//    {
//        Console.WriteLine($"Email: {message}");
//    }
//}
//class SmsNotifier
//{
//    public static void Notify(string message)
//    {
//        Console.WriteLine($"Sms: {message}");
//    }
//}


//class Account
//{
//    public delegate void NotifyHandler(string message);

//    private int sum;

//    private NotifyHandler addMoneyHandler;
//    private NotifyHandler withdrawSuccessHandler;
//    private NotifyHandler withdrawFailedHandler;

//    public Account(int sum)
//    {
//        this.sum = sum;
//    }

//    public void RegisterAddMoneyHandler(NotifyHandler handler) => addMoneyHandler += handler;
//    public void RegisterWithdrawSuccessHandler(NotifyHandler handler) => withdrawSuccessHandler += handler;
//    public void RegisterwithdrawFailedHandler(NotifyHandler handler) => withdrawFailedHandler += handler;


//    public void Add(int val)
//    {
//        sum += val;

//        addMoneyHandler?.Invoke($"Addedd: {val}");
//    }

//    public void Withdraw(int val)
//    {
//        if (val > sum)
//        {
//            withdrawFailedHandler?.Invoke($"ERROR: {val}");

//            return;
//        }

//        sum -= val;

//        withdrawSuccessHandler($"Withdrawn: {val}");
//    }
//}

#endregion

#region Anonymus method

//NotifyHandler handler = delegate (string message)
//{
//    Console.WriteLine($"Message: {message}");
//};

//handler?.Invoke("Vasia");

//delegate void NotifyHandler(string message);







//void Notify(string message, NotifyHandler handler)
//{
//    handler?.Invoke(message);
//}

//Notify("Vasia", WindowsNotifier);
//Notify("Petya", delegate(string m)
//{
//    Console.WriteLine($"Telegram: {m}");
//});


//void WindowsNotifier(string message)
//{
//    Console.WriteLine($"Windows: {message}");
//}

//delegate void NotifyHandler(string message);





//int factor = 4;

//GetResult del = delegate (int a, int b)
//{
//    return a + b * factor;
//};

//delegate int GetResult(int a, int b);

#endregion

#region Lambda expression

// ========= intro ==========

//Handler a = MethodA;

//Handler b = delegate ()
//{
//    Console.WriteLine("anonymus()");
//};

//Handler c = () => Console.WriteLine("lambda c");

//Handler d = () => 
//{ 
//    Console.ForegroundColor = ConsoleColor.Green;
//    Console.WriteLine("lambda d");
//    Console.ResetColor();
//};

//var e = () => Console.WriteLine("lambda e");

//a?.Invoke();
//b?.Invoke();
//c?.Invoke();
//d?.Invoke();
//e?.Invoke();

//void MethodA() => Console.WriteLine("MethodA()");

//delegate void Handler();




// ========= parameters =========

//OperationHandler operation1 = (int a, int b) =>
//{
//    return a + b;
//};
//// >>> Equals <<<
//OperationHandler operation2 = (a, b) => a + b;          // :-)

//int? result = operation2?.Invoke(4, 5);


//RenderHandler renderHandler = mumu => Console.WriteLine(mumu);  // :-)
//renderHandler?.Invoke("Vasia");


//OperationHandler sumHandler = (a, b) => a + b;
//OperationHandler divHandler = (a, b) => a / b;
//OperationHandler mulHandler = (a, b) => a * b;

//Console.WriteLine(sumHandler(10, 5));
//Console.WriteLine(divHandler(10, 5));
//Console.WriteLine(mulHandler(10, 5));


//delegate int OperationHandler(int a, int b);
//delegate void RenderHandler(string message);





// ======= лямбда и делегат

//Handler handler = () => Console.WriteLine("one");

//handler += () => Console.WriteLine("two");
//handler += delegate { Console.WriteLine("anonimus"); };
//handler += Show;

//handler -= Show;

//handler?.Invoke();

//void Show()
//{
//    Console.WriteLine("Show");
//}

//delegate void Handler();

#endregion

#region Practice_3 Lambda

//int[] arr = { 4, 6, 7, 8, 3, 5, 2, 8, 10 };

//int Sum(int[] arr, Predicate predicate)
//{
//    int result = 0;
//    foreach(int x in arr)
//    {
//        if (predicate(x)) 
//            result += x;
//    }   

//    return result;
//}

//int sum1 = Sum(arr, n => n % 2 == 0);
//Console.WriteLine($"sum1: {sum1}");

//int sum2 = Sum(arr, n => n > 0 && n % 2 > 0);
//Console.WriteLine($"sum2: {sum2}");

//delegate bool Predicate(int n);


#endregion

#region Practice_4 Lambda HW
// Написать метод для поиска пользователя (-ей) по разным критериям

//List<User> users = new List<User>()
//{

//};

//// Find()           // <<<<< !!!!!!!

//// Find<T>()        // <<<<< !!!!!!!    ***



//class User
//{
//    public int Id { get; set; }
//    public string? Email { get; set; }
//    public int Age { get; set; }
//    public User(int id, string? email, int age)
//    {
//        Id = id;
//        Email = email;
//        Age = age;
//    }
//    public override string ToString()
//    {
//        return $"{Id} {Email} {Age}";
//    }
//}

#endregion

#region return delegate

//Operation<int> GetOperation(OpType optype) => optype switch
//{ 
//    OpType.Sum => (a, b) => a + b,
//    OpType.Div => (a, b) => a / b,

//    _ => throw new NotSupportedException(),
//};

//Operation<int> res = GetOperation(OpType.Div);
//Console.WriteLine(res?.Invoke(6, 3));


//enum OpType
//{
//    Sum,
//    Div,
//}


//delegate T Operation<T>(T a, T b);

#endregion

#region Practice_5 Lambda
// Написать метод, который проверяет валидность email'a
// Метод должен использовать 2 колбэка (1 - на случай успеха, 2 - на случай неудачи)
// Метод должен принимать предикат для проверки email'a
// Оформить в виде класса EmailValidator


//EmailValidator validator = new EmailValidator();
//validator.Validate(
//    "vasiamail.com",
//    email => Console.WriteLine($"{email} is valid"),
//    email => Console.WriteLine($"{email} is invalid"),
//    email => email.Contains('@'));

//class EmailValidator
//{
//    public void Validate(string email, Callback success, Callback fail, ValidateHandler validateHandler)
//    {
//        if (validateHandler(email))
//            success(email);
//        else
//            fail(email);
//    }
//}

//delegate void Callback(string email);
//delegate bool ValidateHandler(string email);

#endregion

#region Covariance / Contrvariance

// ==== Ковариантность

//PgConnection ConnectToPg(string config)
//{
//    return new PgConnection(config);
//}

//ConnectionHandler handler = ConnectToPg;        // Ковариантность

//Connection conn = handler("config string");
//PgConnection? conn2 = handler("config string") as PgConnection;

//delegate Connection ConnectionHandler(string config);




// ==== Контрвариантность

//void RunConnection(Connection conn) => conn.Connect();

//ConnectionHandler handler = RunConnection;
//handler(new PgConnection("pg config"));

//delegate void ConnectionHandler(PgConnection conn);






// ==== Ковариантность в обобщённых делегатах

//// -- Инвариантность
//ConnectionHandler<MySqlConnection> mySqlHandler = (string config) => new MySqlConnection(config);
//// -- ковариантность
//ConnectionHandler<Connection> handler = new ConnectionHandler<MySqlConnection>((string config) => new MySqlConnection(config));

//Connection conn = handler("config");
//conn.Connect();

//delegate T ConnectionHandler<out T>(string config);







// ==== Контрвариантность в обобщённых делегатах

//// -- Инвариантность
//ConnectionHandler<Connection> handler = (Connection conn) => conn.Connect();

//handler(new MySqlConnection("config"));
//handler(new PgConnection("config"));
//handler(new Connection("config"));

//// -- контрвариантность
//ConnectionHandler<MySqlConnection> mySqlHandler = new ConnectionHandler<Connection>((Connection conn) => conn.Connect());
//mySqlHandler(new MySqlConnection("vasia"));


//delegate void ConnectionHandler<in T>(T conn);




//class Connection
//{
//    public string Config { get; set; }
//    public Connection(string config) => Config = config;
//    public virtual void Connect() => Console.WriteLine($"Connection: Connect() with config {Config}");
//}

//class MySqlConnection : Connection
//{
//    public MySqlConnection(string config) :
//        base(config)
//    { }
//    public override void Connect() => Console.WriteLine($"MySqlConnection: Connect() with config {Config}");
//}

//class PgConnection : Connection
//{
//    public PgConnection(string config) :
//        base(config)
//    { }
//    public override void Connect() => Console.WriteLine($"PgConnection: Connect() with config {Config}");
//}

#endregion

#region Imbeded delegates

// ---- Action / Action<T...>

//RenderMessage("Vasia", m => Console.WriteLine($"Message: {m}"));
//CastToString(3, 4, (a, b) => Console.WriteLine($"{a}, {b}"));
//CastToString2(3, 4, (a, b) => Console.WriteLine($"{a}, {b}"));

//void RenderMessage(string message, Action<string> handler)
//{
//    handler(message);
//}
//void CastToString(int a, int b, Action<int, int> handler)
//{
//    handler(a, b);
//}
//void CastToString2(int a, int b, RenderHandler handler)
//{
//    handler(a, b);
//}

//delegate void RenderHandler(int a, int b);





// ---- Predicate<T>
//int[] arr = {3, 5, 7, 2, 9, 1};
//Console.WriteLine(Sum(arr, n => n % 2 == 0));

//int Sum(int[] arr, Predicate<int> predicate)
//{
//    int res = 0;
//    foreach (var item in arr)
//        if (predicate(item))
//            res += item;

//    return res;
//}




// ---- Func<...>

//Func<int, int, double> GetOperation(OpType opType) => opType switch
//{
//    OpType.Add => (a, b) => a + b,
//    OpType.Sub => (a, b) => a - b,
//    OpType.Div => (a, b) => (double)a / b,

//    _ => throw new NotSupportedException(),
//};
//// >>> EQUALS <<<
////Func<int, int, double> GetOperation(OpType opType)
////{
////    switch(opType)
////    {
////        case OpType.Add:
////            return new Func<int, int, double>((a, b) => a + b);
////        case OpType.Sub:
////            return new Func<int, int, double>((a, b) => a - b);
////        case OpType.Div:
////            return new Func<int, int, double>((a, b) => (double)a / b);
////        default:
////            throw new NotSupportedException();

////    }
////};


//Func<int, int, double> del = GetOperation(OpType.Div);
//Console.WriteLine(del(3, 4));


//enum OpType
//{
//    Add,
//    Sub,
//    Div
//}

#endregion

#region Events

//Server server = new Server();
//server.ClientDisconnected += s => Console.WriteLine(s);
//server.ClientDisconnected += RenderColoredMessage;
////
//server.ClientDisconnected -= RenderColoredMessage;


//void RenderColoredMessage(string message)
//{
//    Console.ForegroundColor = ConsoleColor.Green;
//    Console.WriteLine(message);
//    Console.ResetColor();
//}

//class Server
//{
//    public event Action? ClientConnected;

//    private Action<string>? clientDisconnected;

//    public event Action<string> ClientDisconnected
//    {
//        add             // +=
//        {
//            clientDisconnected += value;
//            Console.WriteLine($"{value?.Method.Name} added...");
//        }
//        remove          // -=
//        {
//            clientDisconnected -= value;
//            Console.WriteLine($"{value?.Method.Name} removed...");
//        }
//    }

//    public void Connect()
//    {
//        //
//        //
//        ClientConnected?.Invoke();              // <---- event Invoked
//    }

//    public void Disconnect()
//    {
//        //
//        //
//        clientDisconnected?.Invoke("Vasia");    // <---- delegate Invoked
//    }
//}





//Server server = new Server();
//server.Connected += (sender, args) =>
//{
//    Console.WriteLine("Connected:");
//    Console.WriteLine($"Time: {args.Date.ToShortTimeString()}");
//    Console.WriteLine("USER:");
//    Console.WriteLine(args.User);
//};

//User user = new()
//{
//    Id = 101,
//    Email = "vasia@mail.com",
//};
//server.Connect(user);


//class ServerEventArgs
//{
//    public User User { get; set; }
//    public DateTime Date { get; set; }
//    public ServerEventArgs(User user, DateTime date)
//    {
//        User = user;
//        Date = date;
//    }
//}
//class User
//{
//    public int Id { get; set; }
//    public string Email { get; set; }
//    public override string ToString()
//    {
//        return $"id: {Id}, email: {Email}";
//    }
//}

//class Server
//{
//    public event Action<Server, ServerEventArgs>? Connected;
//    public List<User> Users { get; set; } = new List<User>();

//    public void Connect(User user)
//    {
//        Users.Add(user);
//        //
//        //

//        Connected?.Invoke(this, new ServerEventArgs(user, DateTime.Now));
//    }
//}







// HW
// Создать класс Account (+ User...)
// События: OnAdded, OnWithdrawen, OnError
// Предусмотреть несколько каналов оповещения пользователя (Telegram, Email, SMS)
// Каждый Account настраивается отдельно в плане оповещения при разных событиях.



#endregion
