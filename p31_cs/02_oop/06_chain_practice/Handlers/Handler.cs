namespace _06_chain_practice.Handlers;

internal abstract class Handler : IHandler
{
    protected IHandler? Next { get; set; } = null;
    public IHandler SetNext(IHandler nextHandler)
    {
        Next = nextHandler;

        return Next;
    }
    public abstract void Processing();
    public abstract void Rollback();
}
