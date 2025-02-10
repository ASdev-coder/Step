namespace _04_extra
{
    //internal class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        //int val = 3;

    //        //switch(val)
    //        //{
    //        //    case 0:
    //        //        Console.WriteLine(0);
    //        //        break;
    //        //    case 1:
    //        //        Console.WriteLine(1);
    //        //        break;
    //        //    case 2:
    //        //    case 3:
    //        //        //
    //        //        //
    //        //        // return;
    //        //        // throw;
    //        //        // goto case 1;
    //        //        break;
    //        //    default:

    //        //        break;
    //        //}


    //        //int getVal(string operation, int a, int b)
    //        //{
    //        //    switch(operation)
    //        //    {
    //        //        case "add":
    //        //            return a + b;
    //        //            break;
    //        //    }
    //        //}


    //        //int getVal(string operation, int a, int b)
    //        //{
    //        //    return operation switch
    //        //    {
    //        //        "add" => a + b,
    //        //        "mul" => a * b,
    //        //        _ => throw new Exception("Invalid operation")
    //        //    };
    //        //}



    //        //int getVal(string operation, int a, int b) => operation switch
    //        //{
    //        //    "add" => a + b,
    //        //    "mul" => a * b,
    //        //    _ => throw new Exception("Invalid operation")
    //        //};

    //    }
    //}




    enum Operation
    {
        Add = 2,
        Mul = 4,
    }

    enum Permission: byte
    {
        Read,
        Write,
        Create,
    }

    enum Role : byte
    { 
        Admin = 2,
        Guest = 4,
        Author = 4,
    }


    internal class Programm
    {
        static void Main()
        {
            // Operation a = 1;     // ERROR
            Operation b = Operation.Add;


        }
    }
}
