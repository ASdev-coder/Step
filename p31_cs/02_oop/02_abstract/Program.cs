//      C++                                 C#
//  чистая виртуальная ф-ция            абстрактный метод (являюется виртуальным)
//  абстрактный класс                   абстрактный класс
//  интерфейсный класс                  интерфейс

// В С# абстрактными могут быть члены класса:
// 1. Метод
// 2. Свойство
// 3. Событие
// 4. Индексатор



// Unit unit = new Unit();      // ERROR

//Unit a = new Warrior();
//Console.WriteLine(a.Hp);
//Console.WriteLine(a.Force);

//Unit b = new SuperWarrior();
//Console.WriteLine(b.Force);

//abstract class Unit
//{
//    public int Hp { get; protected set; }
//    public virtual int Level { get; set; }
//    public abstract int Force { get; set; }             // НЕ АВТОСВОЙСВО -> abstract getForce(); abstract setForce()
//    public void Attack() => Console.WriteLine("Unit.Attack()");
//    public virtual void Move() => Console.WriteLine("Unit.Move()");
//    public abstract void Defence();
//}

//class Warrior : Unit
//{
//    //private int force;
//    //public int Force
//    //{
//    //    get  => force;
//    //    set => force = value;
//    //}
//    public override int Force { get; set; }
//    public new void Attack() => Console.WriteLine("Warrior.Attack()");
//    public override void Defence() => Console.WriteLine("Warrior.Defence()");
//    public override void Move() => Console.WriteLine("Warrior.Move()");
//}

//class SuperWarrior : Warrior
//{
//    public override int Force
//    {
//        get => base.Force * 2;
//        set => base.Force = value;
//    }
//    public override void Defence() => Console.WriteLine("SuperWarrior.Defence()");
//}





// ======== virtual / abstract Object methods / GetType / typeof ==========

Product p = new();
Console.WriteLine(p);
object o = p;
Console.WriteLine(o);

Type type1 = p.GetType();
Type type2 = typeof(Product);
Console.WriteLine(type1 == type2);

class Product
{
    public int Id { get; set; }
    public string Title { get; set; } = "no_title";
    public override string ToString()
    {
        return $"id: {Id}, title: {Title}";
    }

    public override int GetHashCode()
    {
        return Id;
    }

    public override bool Equals(object? obj)
    {
        if (obj is Product p) 
        { 
            return Id == p.Id;
        }

        return false;
    }
}






