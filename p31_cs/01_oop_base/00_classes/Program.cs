namespace _00_classes
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //User a = new User();
            //User b = new User("vasia@mail.com");
            //User c = new User(505, "vasia@mail.com");

            //// a.email = "petya@mail.com";
            //a.Render();


            //Account a = new Account();

            //Account b = new Account(101, "my account", 1000);


            //Account c = new Account();
            //c.sum = 2000;
            //c.id = 505;

            //Account d = new Account() 
            //{ 
            //    sum = 2000, 
            //    id = 505,
            //};

            //Account e = new Account()
            //{
            //    id = 707,
            //    user = new User("dima@mail.com"),
            //};



            Mesh a = new Mesh("cube", 7);

            a.Deconstruct(out string t, out int l);
            Console.WriteLine($"{t} {l}");
            // equals
            (string title, int level) = a;
            Console.WriteLine($"{title} {level}");

            (_ , int lev) = a;

            void Render(Mesh m)
            {
                (string title, int level) = m;

                Console.WriteLine();
            }

        }
    }
}
