using _06_chain_practice;
using _06_chain_practice.Handlers;

IHandler db = new DbHandler();
IHandler domain = new DomainHandler();
IHandler deploy = new DeployHandler();

deploy.SetNext(db).SetNext(domain);

try
{
	deploy.Processing();
}
catch (Exception ex)
{
    Console.WriteLine($"ERROR: {ex.Message}");
}
