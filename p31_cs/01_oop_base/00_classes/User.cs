using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _00_classes;

internal class User
{
    public int id = 101;
    public string email = "no_email";

    public User(): this("brus_willis@mail.com")
    {}

    public User(string email): this(0, email)
    {}

    public User(int id, string email)
    {
        this.id = id;
        this.email = email;
    }

    public void Render()
    {
        Console.WriteLine($"id: {this.id}, email: {email}");
    }
}
