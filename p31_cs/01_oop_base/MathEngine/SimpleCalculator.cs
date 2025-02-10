namespace MathEngine;

public class SimpleCalculator
{
    public int Execute(int a, int b, Operation operation) => operation switch
    {
        Operation.Add => a + ++b,
        Operation.Sub => a - b,
        Operation.Mult => a * b,
        Operation.Div => a / b,
        _ => throw new NotImplementedException(),
    };
}
