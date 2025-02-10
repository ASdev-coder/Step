
#region Null and reference types
//#nullable disable
//string a;
//string b = null;
//#nullable restore

//string? email = null;
//Console.WriteLine(email);

//string? input = Console.ReadLine();

//if (input != null)
//{
//    int v = Convert.ToInt32(input);
//}





//string? data = Console.ReadLine();

////void Render(string? content)
////{
////    if (content == null)
////        return;

////    Console.WriteLine($"CONTENT: {content}");
////}

////Render(data);

//void Render(string content)
//{
//    Console.WriteLine($"CONTENT: {content}");
//}

//Render(data!);      // <-- Null-forgiven operator
#endregion

#region Null and value types

// int a = null;

//int? b = null; // ~~~ Nullable<int> b = null;

//if (b.HasValue)
//    Console.WriteLine(b.Value);

//int a = 45;
//int? b = a;

#endregion

#region Null gurad

//void Render(string? content)
//{
//    //if (content == null)
//    //    return;

//    //if (content is null)
//    //    return;
//    //Console.WriteLine(content.ToUpper());

//    //if (content is not null)
//    //    Console.WriteLine(content.ToUpper());

//    //if (content is string)
//    //    Console.WriteLine(content.ToUpper());
//}

#endregion

#region Null union
//string email = string.Empty;

//string? input = null;

////if (input is null)
////    email = "no_email";
//// >>>EQUALS<<<
//email = input ?? "no_email";

//Console.WriteLine($"EMAIL: {email}");

#endregion

#region Conditional Null (условный Null)

//User a = new User()
//{
//    //Role = new Role()
//    //{
//    //    Title = "admin",
//    //}

//    Role = null,
//};

//Process(a);
//void Process(User? user)
//{
//    // user.Role.Render();

//    //if (user is not null && user.Role is not null && user.Role.Title is not null)
//    //    user.Role.Render();
//    // >>>EQUALS<<<
//    // user?.Role?.Render();
//}

//class Role
//{
//    public string? Title { get; set; }
//    public void Render() => Console.WriteLine($"Title: {Title}");
//}
//class User
//{
//    public Role? Role { get; set; }
//}

#endregion
