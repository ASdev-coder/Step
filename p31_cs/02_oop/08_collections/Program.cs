
#region List<>

//List<string> planets = new List<string>()
//{
//    "Mercury",
//    "Venus",
//    "Earth1",
//    "Earth2",
//    "Earth3"
//};

//planets.Add("Mars");

//foreach(string p in planets)
//    Console.WriteLine(p);

//planets.ForEach(p => Console.WriteLine(p));
//planets.ForEach(Console.WriteLine);

//planets.Insert(1, "Jupiter");

//planets.Remove("Jupiter");
//planets.RemoveAt(0);
//planets.RemoveAll(p => p.StartsWith('E'));

//Console.WriteLine("------");
//planets.ForEach(Console.WriteLine);


//Console.WriteLine(planets.Contains("Mars"));
//Console.WriteLine(planets.Exists(p => p.StartsWith("E")));

//string? result = planets.Find(p => p.StartsWith("E"));


//planets
//    .GetRange(planets.FindIndex(p => p.StartsWith("V")), 2)
//    .ForEach(p => Console.WriteLine(p));

#endregion

#region Extra

// LinkedList<>

// Stack<>

// Queue<>

// PriorityQueue<>

#endregion

#region Dictionary

////Dictionary<int, string> planets = new Dictionary<int, string>()
////{
////   { 101, "Mercury" },
////   { 102, "Venus" },
////   { 101, "Earth" },
////};

//Dictionary<int, string> planets = new Dictionary<int, string>()
//{
//    [101] = "Mercury",
//    [102] = "Venus",
//    [103] = "Earth",

//};

//foreach (KeyValuePair<int, string> item in planets)
//{
//    (int k, string v) = item;
//    Console.WriteLine($"key: {k}, val = {v}");
//}


//planets.Add(104, "Mars");

//Console.WriteLine(planets.ContainsKey(104));

//foreach (var key in planets.Keys)
//    Console.WriteLine(key);

#endregion

#region ObservableCollection

//using System.Collections.ObjectModel;
//using System.Collections.Specialized;

//ObservableCollection<User> users = new ObservableCollection<User>()
//{
//   new User(101, "vasia@mail.com"),
//   new User(103, "petya@mail.com"),
//   new User(106, "dima@mail.com"),
//};

//users.CollectionChanged += Users_CollectionChanged;

//users.Add(new User(111, "kolia@mail.com"));
//users.RemoveAt(0);

//void Users_CollectionChanged(object? sender, System.Collections.Specialized.NotifyCollectionChangedEventArgs e)
//{
//    switch (e.Action)
//    {
//        case NotifyCollectionChangedAction.Add:
//            if (e.NewItems?[0] is User u)
//            {
//                Console.WriteLine("Add handler");
//                Console.WriteLine(u);
//            }
//            break;
//        case NotifyCollectionChangedAction.Remove:
//            if (e.OldItems?[0] is User deletedUser)
//            {
//                Console.WriteLine("Remove handler");
//                Console.WriteLine(deletedUser);
//            }
//            break;
//    }
//}

//class User
//{
//    public int Id { get; set; }
//    public string Email { get; set; }
//    public User(int id, string email)
//    {
//        Id = id;
//        Email = email;
//    }
//    public override string ToString()
//    {
//        return $"id: {Id}, email: {Email}";
//    }
//}

#endregion
