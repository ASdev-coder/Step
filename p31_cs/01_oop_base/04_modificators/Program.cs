using mod_ex;

// Модификаторы доступа членов типа (классы и т.д...)
// private
// public
// protected
// private protected
// protected internal
// internal

// Модификаторы доступа для типа в целом
// public
// internal
// file



Example ex = new Example();
class ExampleChild : Example
{
    public void Method()
    {
        this.Method();

        // this.privateProtectedField = 12;        //  ERROR

        this.protectedInternalField = 34;
    }
}



