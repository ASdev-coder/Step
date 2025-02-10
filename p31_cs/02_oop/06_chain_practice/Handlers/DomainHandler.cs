namespace _06_chain_practice.Handlers;

internal class DomainHandler : Handler
{
    public override void Processing()
    {
        try
        {
            throw new Exception("Domain error!");
            Console.WriteLine("Domain created...");

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
        Console.WriteLine("Domain deleted...");
    }
}
