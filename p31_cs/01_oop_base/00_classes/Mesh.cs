using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _00_classes;

internal class Mesh
{
    string title;
    int level;

    public Mesh(string title, int level)
    {
        this.title = title;
        this.level = level;
    }

    public void Deconstruct(out string title, out int level)
    {
        title = this.title;
        level = this.level;
    }
}
