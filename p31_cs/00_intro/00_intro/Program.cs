using System.Collections.Specialized;
using System.Reflection.Metadata;
using System.Runtime.InteropServices;

namespace _00_intro;

internal class Program
{
    //static void Main(string[] args)
    //{
    //    // comment
    //    /*
    //        comment
    //        comment
    //     */
    //    // Console.WriteLine("Hello, World!");

    //    //int a = 3;

    //    //int b;
    //    //b = 45;

    //    //string a = "vasia";
    //    //a = "Petya";

    //    //const string name = "DIMA";
    //    //// name = "PETYA";              // ERROR
    //    ///

    //}

    //static void Main(string[] args)
    //{
    //    // === types

    //    // = значимые типы (структуры)
    //    bool a;

    //    byte b;         // 0 -> 255

    //    sbyte c;        // -128 -> 127

    //    short d;        // -32768 -> 32767

    //    ushort e;       // 0 -> 65535

    //    int f;

    //    uint g;

    //    long h;

    //    ulong i;

    //    float j;

    //    double k;

    //    decimal l;      // 16 bytes (.28 signs)

    //    char m;

    //    // Ссылочные типы (классы)
    //    string n;

    //    object o;

    //    // var (неявная типизация)

    //    // var p;      // ERROR
    //    var p = 76;
    //}

    static void Main(string[] args)
    {
        //Console.WriteLine("Vasia");
        //Console.Write("Vasia");

        //int id = 101;
        //string email = "vasia@mail.com";

        //string info = $"id: {id}, email: {email}";
        //Console.WriteLine(info);
        //Console.WriteLine("id: {0}, email: {1}", id, email); 

        //Console.ForegroundColor = ConsoleColor.Green;
        //// Console.BackgroundColor = ConsoleColor.White;
        //Console.SetCursorPosition(10, 3);
        //Console.WriteLine("Test string");
        //Console.ResetColor();


        //Console.Write("Enter your email: ");
        //string email = Console.ReadLine();
        //Console.WriteLine($"Your email is {email}");

        Console.Write("Enter first number: ");
        int a = Convert.ToInt32(Console.ReadLine());
        Console.Write("Enter second number: ");
        int b = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine($"Result: {a + b}");
    }

}


