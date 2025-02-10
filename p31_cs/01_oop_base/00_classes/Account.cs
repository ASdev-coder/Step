using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _00_classes;

internal class Account
{
    public int id;
    public string title;
    public int sum;
    public User user;

    public Account(): this(0, "no_title", 0)
    { }
    public Account(int id, string title, int sum)
    {
        this.id = id;
        this.title = title;
        this.sum = sum;
    }
}
