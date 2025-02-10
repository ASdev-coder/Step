

//User user = new User("vasia@mail.com");
//Console.WriteLine(user.Email);
//user.Email = "PETYA@mail.com";
//Console.WriteLine(user.Email);

//class User
//{
//    private string email;

//    public User(string email)
//    {
//        this.email = email;
//    }

//    //public string getEmail() => this.email;
//    //public void setEmail(string email) => this.email = email;

//    //public string Email
//    //{
//    //    get
//    //    {
//    //        return this.email;
//    //    }
//    //    set
//    //    {
//    //        email = value;
//    //    }
//    //}
//    public string Email
//    {
//        get => this.email;
//        set
//        {
//            this.email = value.ToLower();
//        }
//    }
//}




//User user = new User("vasia@mail.com");
//Console.WriteLine(user.Email);
//// user.Email = "petya@mail.com";           ERROR

//user.Age = 23;
//// Console.WriteLine(user.Age);             ERROR

//Console.WriteLine(user.Info);

//class User
//{
//    private string email;
//    private int age;

//    public User(string email)
//    {
//        this.email = email;
//    }

//    public string Email                     // св-во "только для чтения"
//    {
//        get
//        {
//            return this.email;
//        }
//    }

//    public int Age                          // св-во "только для записи"
//    {
//        set
//        {
//            this.age = value;
//        }
//    }

//    public string Info                      // "Вычисляемое" св-во
//    {
//        get
//        {
//            return $"Email: {Email}, Age: {age}";
//        }
//    }

//}




//class User
//{
//    private string email;

//    public string Email
//    {
//        get
//        {
//            return email;
//        }
//        private set
//        {
//            email = value;
//        }
//    }
//}

//  Модификаторы можно использовать ТОЛЬКО при наличии обоих блоков (get и set)
//  Модификатор можно применять только к одному блоку
//  Модификатор блока должен быть СТРОЖЕ, чем модификатор св-ва  в целом



// ====== Автосвойства ========

//User user = new User();
//user.Age = 15;
//class User
//{
//    public string Email { get; private set; } = "no_email";
//    // EQUALS
//    //private string email = "no_email";
//    //public string Email
//    //{
//    //    get
//    //    {
//    //        return email;
//    //    }
//    //    set
//    //    {
//    //        email = value;
//    //    }
//    //}

//    private int age;
//    public int Age { 
//        get 
//        {
//            return age;
//        } 
//        set 
//        {
//            if (value < 18)
//                throw new ArgumentException("Age is invalid");

//            age = value;
//        }
//    }

//    // private readonly string password = "123123123";
//    public string Password { get; } = "no_password";

//    public void Render()
//    {
//        Console.WriteLine($"age: {Age}");
//        // this.password = "werwer";           // ERROR

//    }
//}


// ==== Блок init ( одноразовый set ) =====

//User u = new User("vasia@mail.com")
//{ 
//    Email = "petya@mail.com",
//};
//// u.Email = "dima@mail.com";       // ERROR
//class User
//{
//    public string Email { get; init; } = "no_email";

//    public User(string email)
//    {
//        Email = email;
//    }
//    public void Method()
//    {
//        Email = "dima@mail.com";
//    }
//}


//class User
//{
//    public int Id { get; init; }    //ИНИЦИАЛИЗАЦИЯ --> конструктор / дефолтное значение / инициализатор
//    public int Age { get; }         //ИНИЦИАЛИЗАЦИЯ --> конструктор / дефолтное значение
//}



// === сокращения для стандартных свойств ====

//class User
//{
//    private int id;
//    private string email;
//    public int Id
//    {
//        get => id;
//        set => id = value;
//    }

//    // public string Email { get { return email; } }
//    // EQUALS
//    public string Email => email;
//}

// === required ===

//User u = new User()
//{
//    Email  = "vasia@mail.com",
//    Password = "qwerty",
//};

//class User
//{
//    public int Id { get; }
//    public required string Email { get; set; }
//    public required string Password { get; set; }
//    public User()
//    {
//        Random random = new Random();
//        Id = random.Next();
//    }
//}





















