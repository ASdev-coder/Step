namespace _06_chain_practice.Handlers;

internal class DbHandler : Handler
{
    public override void Processing()
    {
        try
        {
            Console.WriteLine("Db created...");

            Next?.Processing();
        }
        catch (Exception)
        {
            Rollback();

            throw;
        }
    }

    public override void Rollback()
    {
        Console.WriteLine("Db was deleted...");
    }
}
