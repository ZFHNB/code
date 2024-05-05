//定义抽象基类Shape
//由它派生出5个派生类: Circle(圆形)、Square(正方形)、Rectangle(矩形)、Trapezoid(梯形)、Triangle(三角形)。
//用虚函数分别计算几种图形面积
//并求它们的和。
//要求用基类指针数组，使它的每一个元素指向一个派生类对象。
#include <iostream>
using namespace std;

class Shape
{   public:
        virtual ~Shape(){}
        virtual void getShape() const = 0;  //纯虚函数（抽象方法）
        virtual double getArea() const = 0; //纯虚函数（抽象方法）
};
class Circle:public Shape//圆
{
    private:
        double radius;//半径
    public:
        Circle(double r) : radius(r){}
        void getShape() const override { cout<<"Circle";}
        double getArea() const override { return 3.14 * radius * radius; }
};
class Square:public Shape//正方形
{
    private:
        double side;//边长
    public:
        Square(double s) : side(s){}
        void getShape() const override { cout<<"Square";}
        double getArea() const override { return side * side; }
};
class Rectangle:public Shape//矩形
{
    private:
        double width,height;//宽和高
    public:
        Rectangle(double w, double h) : width(w), height(h){}
        void getShape() const override { cout<<"Rectangle";}
        double getArea() const override { return width * height; }
};
class Trapezoid:public Shape//梯形
{
    private:
        double topBase, bottomBase, height;
    public:
        Trapezoid(double t, double b, double h) : topBase(t), bottomBase(b), height(h) {}
        void getShape() const override { cout<<"Trapezoid";}
        double getArea() const override { return (topBase + bottomBase) * height / 2; }
};
class Triangle:public Shape//三角形
{
    private:
        double base, height;
    public:
        Triangle(double b, double h) : base(b), height(h) {}
        void getShape() const override { cout<<"Triangle";}
        double getArea() const override { return base * height / 2; }
};
int main()
{
    Shape *shapes[5];
    shapes[0] = new Circle(10);
    shapes[1] = new Square(5.5);
    shapes[2] = new Rectangle(3, 4);
    shapes[3] = new Trapezoid(4, 6, 2);
    shapes[4] = new Triangle(3, 4);

    //输出各自的面积：
    cout<<"area:"<<endl;
    for(auto a : shapes)
    {
        a->getShape();
        cout<<"："<<a->getArea()<<endl;
    }

    //输出总面积：
    double totalArea;
    for(auto a : shapes)
    {
        totalArea += a->getArea();
        delete a;
    }
    cout<<"\ntotal area："<<totalArea<<endl;

    return 0;
}