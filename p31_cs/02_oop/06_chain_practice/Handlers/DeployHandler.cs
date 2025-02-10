namespace _06_chain_practice.Handlers;

internal class DeployHandler : Handler
{
    public override void Processing()
    {
        try
        {
            Console.WriteLine("deployment successfully...");

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
        Console.WriteLine("deployment cancelled...");
    }
}
