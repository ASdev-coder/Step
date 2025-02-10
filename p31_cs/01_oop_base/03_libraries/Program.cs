using MathEngine;
using FileToolKit;
using FileToolKit.Controllers;
using _03_libraries;
using Newtonsoft.Json;

SimpleCalculator calc = new SimpleCalculator();

Console.WriteLine(calc.Execute(2, 3, Operation.Add));

FileEngine fe = new FileEngine();
fe.Show();

RouteController controller = new RouteController();
controller.Show();

User user = new User()
{ 
    id = 101,
    email = "vasia@mail.com",
    age = 23
};

string json = JsonConvert.SerializeObject(user);
Console.WriteLine(json);

User deserializedUser = JsonConvert.DeserializeObject<User>(json);
deserializedUser.Show();

