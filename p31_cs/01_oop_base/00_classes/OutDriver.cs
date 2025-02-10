using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _00_classes;

//internal class OutDriver
//{
//    public string path;
//    public int depth;

//    public OutDriver(string path): this(path, 10)
//    { }
//    public OutDriver(string path, int depth)
//    {
//        this.path = path;
//        this.depth = depth;
//    }
//    public void Show()
//    {
//        Console.WriteLine($"path: {path} depth: {depth}");
//    }
//}


// Primary ctor (Первичный конструктор)
internal class OutDriver(string path, int depth)
{
    public OutDriver(string path) : this(path, 10)
    { }
    public void Show()
    {
        Console.WriteLine($"path: {path} depth: {depth}");
    }
}
