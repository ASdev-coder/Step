
CryptEngine cEngine = new(new CesarStrategy());
Console.WriteLine(cEngine.EncryptString("Vasia"));

cEngine.SetStrartegy(Strategy.Best);
Console.WriteLine(cEngine.EncryptString("Vasia"));

cEngine.EncryptStrategy = new MyStrategy();
Console.WriteLine(cEngine.EncryptString("Vasia"));

class MyStrategy: IEncryptStrategy
{
    public string Decrypt(string encriptedContent)
    {
        return $"MyStrategy Decrypt: {encriptedContent}";
    }

    public string Encrypt(string content)
    {
        return $"MyStrategy Encrypt: {content}";
    }
}

// -------
public interface IEncryptStrategy
{
    string Encrypt(string content);
    string Decrypt(string encriptedContent);
}
public class CesarStrategy : IEncryptStrategy
{
    public string Decrypt(string encriptedContent)
    {
        return $"CesarStrategy Decrypt: {encriptedContent}";
    }

    public string Encrypt(string content)
    {
        return $"CesarStrategy Encrypt: {content}";
    }
}
public class BestStrategy : IEncryptStrategy
{
    public string Decrypt(string encriptedContent)
    {
        return $"BestStrategy Decrypt: {encriptedContent}";
    }

    public string Encrypt(string content)
    {
        return $"BestStrategy Encrypt: {content}";
    }
}


public enum Strategy
{
    Cesar,
    Best,
}
public class CryptEngine
{
    public IEncryptStrategy EncryptStrategy { get; set; }
    public CryptEngine(IEncryptStrategy encryptStrategy)
    {
        EncryptStrategy = encryptStrategy;
    }

    public void SetStrartegy(Strategy strategy)
    {
        EncryptStrategy = strategy switch
        {
            Strategy.Cesar => new CesarStrategy(),
            Strategy.Best => new BestStrategy(),

            _ => throw new NotSupportedException()
        };
    }

    public string EncryptString(string content)
    {
        return EncryptStrategy.Encrypt(content);
    }

    public string DecryptToString(string encriptedContent)
    {
        return EncryptStrategy.Decrypt(encriptedContent);
    }
}
