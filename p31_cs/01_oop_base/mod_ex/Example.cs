namespace mod_ex;

public class Example
{
    public int publicField;
    private int privateField;
    protected int protectedField;

    private protected int privateProtectedField;        //  ~~~ (private  protected)
    protected internal int protectedInternalField;      //  ~~~ (protected public)
    internal int internalField;                         //  ~~~ (private public)
    // file int fileField;  // TODO: ???
}
