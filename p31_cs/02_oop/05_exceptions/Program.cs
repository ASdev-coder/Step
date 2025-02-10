
// try / catch / finally
// throw

//int a = 4;
//int b = 0;

//try
//{
//    int c = a / b;

//    Console.WriteLine($"result = {c}");
//}
//catch(Exception)
//{
//    Console.WriteLine("catch");
//}
//finally
//{
//    Console.WriteLine("finally");
//}

//Console.WriteLine("END");





//void GetIntValue(string str)
//{
//    int val = int.Parse(str);
//    Console.WriteLine($"val = {val}");
//}

//string input1 = "34";
//string input2 = "vasia";

//try
//{
//    GetIntValue(input1);
//    GetIntValue(input2);
//    //
//    //
//}
//catch (Exception) when (input2 == "vasia")
//{
//    Console.WriteLine("Oooooops...");
//}

//Console.WriteLine("Hello");





// DivideByZeroException
// IndexOutOfRangeException
// NullReferenceException
// ArgumentException
// InvalidCastException





//int a = 4;
//int b = 2;
//int c = 0;
//int d = 10;

//try
//{
//    c = a / b;
//    Console.WriteLine($"Result = {c}");

//    int[] arr = [3, 4, 5];
//    Console.WriteLine(arr[d]);
//}
//catch (DivideByZeroException ex)
//{
//    Console.WriteLine(ex.Message);
//    Console.WriteLine(ex.StackTrace);
//    Console.WriteLine(ex.Source);
//    Console.WriteLine(ex.TargetSite);
//    Console.WriteLine(ex.InnerException);
//    Console.WriteLine(ex.HelpLink);
//}
//catch (IndexOutOfRangeException ex)
//{
//    Console.WriteLine(ex.Message);
//    Console.WriteLine(ex.StackTrace);
//    Console.WriteLine(ex.Source);
//    Console.WriteLine(ex.TargetSite);
//    Console.WriteLine(ex.InnerException);
//    Console.WriteLine(ex.HelpLink);
//}
//catch (Exception ex)
//{
//    Console.WriteLine(ex.Message);
//    Console.WriteLine(ex.StackTrace);
//    Console.WriteLine(ex.Source);
//    Console.WriteLine(ex.TargetSite);
//    Console.WriteLine(ex.InnerException);
//    Console.WriteLine(ex.HelpLink);
//}




//try
//{
//	Console.Write("Enter your nickname: ");
//	string? input = Console.ReadLine();

//    if (input is null || input.Length < 5)
//        throw new Exception("Invalid nickname")
//        {
//            HelpLink = "https://google.com",
//        };
//    else
//        Console.WriteLine($"Hello {input}");
//}
//catch (Exception ex)
//{
//    Console.WriteLine(ex.Message);
//    Console.WriteLine(ex.StackTrace);
//    Console.WriteLine(ex.Source);
//    Console.WriteLine(ex.TargetSite);
//    Console.WriteLine(ex.InnerException);
//    Console.WriteLine(ex.HelpLink);
//}





//try
//{
//    Account acc = new Account(1000);
//    acc.Withdraw(1500);
//}
//catch (AccountException ex)
//{
//    Console.WriteLine($"System error: {ex.Message}, your sum is {ex.Value}");
//}
//catch (AppException ex)
//{
//    Console.WriteLine($"ERROR: {ex.Message}");
//}


//class AppException: Exception
//{
//    public AppException(string? message) :
//        base(message)
//    { }
//}
//class AccountException: AppException
//{
//    public int Value { get; }
//    public AccountException(string? message, int val):
//        base(message)
//    { 
//        Value = val;
//    }
//}

//class Account
//{
//    public int Balance { get; set; }
//    public Account(int sum)
//    {
//        Balance = sum;
//    }
//    public void Withdraw(int sum)
//    {
//        if (sum > Balance)
//            throw new AccountException("Sum is unvaliable!", sum);

//        Balance -= sum;
//        Console.WriteLine("All ok");
//    }
//}





try
{
    ConnectionManager.Connect();
}
catch (ConnectionException ex)
{
    Console.WriteLine($"For admin: ERROR: {ex.Message}");
    Console.WriteLine($"For client: Sorry man...");
    Console.WriteLine(ex.StackTrace);
}



class ConnectionException: Exception
{
    public ConnectionException(string? message) :
        base(message)
    { }
}

class ConnectionManager
{
    public static void Connect()
    {
        string config = GenerateConfigString();
        Console.WriteLine($"Connected with {config}");
    }

    public static string GenerateConfigString()
    {
        return $"AFTER GENERATING: {ConfigParser.Parse()}";
    }
}

class ConfigParser
{
    public static string Parse()
    {
        //try
        //{
        //    string parsedConfig = $"AFTER PARSING: {ReadConfigFile(true)}";

        //    return parsedConfig;
        //}
        //catch (ConnectionException ex)
        //{
        //    return "DEFAULT PARSED CONFIG";
        //}

        try
        {
            return $"AFTER PARSING: {ReadConfigFile(true)}";
        }
        catch(ConnectionException ex)
        {
            Console.WriteLine("Logging...");

            throw;                                          // :-)
            // throw new Exception("Extra Exception");      // :-(
        }
        finally
        {
            Console.WriteLine("Close file stream if opened...");
        }
    }

    private static string ReadConfigFile(bool flag = true)
    {
        // Предположим, файл отсутствует
        if (flag)
            throw new ConnectionException("Config file is not exists");
        else
            return "{db: my.db; pooling: true}";
    }
}


