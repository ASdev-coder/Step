namespace _06_chain_practice;

internal interface IHandler
{
    public IHandler SetNext(IHandler nextHandler);
    public void Processing();
    public void Rollback();
}
