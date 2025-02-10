namespace _03_libraries;

internal class User
{
    public int id;
    public string email;
    public int age;

    public void Show()
    {
        Console.WriteLine($"id: {id}, email --> {email}, age: {age}");
    }
}
