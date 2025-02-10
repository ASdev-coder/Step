

//Point a = new Point();
//// EQUALS
//Point b = new();

//a.x = 12;
//a.Render();

//struct Point
//{
//    public int x;
//    public int y;

//    public void Render()
//    {
//        Console.WriteLine($"x: {x} y: {y}");
//    }
//}








//struct Point
//{
//    public int x = -1;
//    public int y = -1;

//    public Point(): this(-1, -1)
//    { }
//    public Point(int val): this(val, val)
//    { }
//    public Point(int x, int y) 
//    { 
//        this.x = x; 
//        this.y = y;
//    }

//    public void Render()
//    {
//        Console.WriteLine($"x: {x} y: {y}");
//    }
//}




//Point a = new Point();
//a.Render();

//Point b = new Point(3);
////{                         // ERROR
////    x = 1,
////    y = 2,
////};

//struct Point(int x, int y)
//{
//    public Point(int val): this(val, val)
//    { }
//    public void Render() => Console.WriteLine($"x: {x} y: {y}");
//}




//Point a = new Point();
//a.Render();

//Point b = new Point(3)
//{
//    x = 1,
//    y = 2,
//};

//struct Point
//{
//    public int x;
//    public int y;
//    public Point(int x, int y)
//    {
//        this.x = x; 
//        this.y = y;
//    }
//    public Point(int val) : this(val, val)
//    { }
//    public void Render() => Console.WriteLine($"x: {x} y: {y}");
//}





//Point a = new Point(15);
//a.Render();

//// Point b;
//// b.Render();     // ERROR

//Point c;
//c = a;
//a.x = 100;
//a.Render();
//c.Render();




//Point a = new Point(15);
//Point b = a;

//Point c = a with { x = 100 };
//// EQUALS
//Point d = a;
//d.x = 100;


//struct Point
//{
//    public int x;
//    public int y;
//    public Point(int x, int y)
//    {
//        this.x = x;
//        this.y = y;
//    }
//    public Point(int val) : this(val, val)
//    { }
//    public void Render() => Console.WriteLine($"x: {x} y: {y}");
//}




// ==============  ссылочные и значимые типы при использовании ================


PointTitle pt = new PointTitle(102, "Petya");
Point a = new Point(12, 12, pt);
Point b = a;        // ВНИМАНИЕ! Копия ссылки в поле PointTitle pointTitle !!!!
Point c = a with { pointTitle = new PointTitle(105, "Dima") };

class PointTitle
{
    public int id;
    public string title;
    public PointTitle(int id, string title)
    {
        this.id = id;
        this.title = title;
    }
    public void Render() => Console.WriteLine($"id: {id} title: {title}");
}
struct Point
{
    public int x;
    public int y;
    public PointTitle pointTitle;
    public Point(int x, int y, PointTitle pt)
    {
        this.x = x;
        this.y = y;
        this.pointTitle = pt;
    }
    public Point(int val) : this(val, val, new PointTitle(101, "Vasia"))
    { }
    public void Render() => Console.WriteLine($"x: {x} y: {y}");
}














