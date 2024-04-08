#include <iostream>
using namespace std;

class Shape
{
	public:
		virtual void area()=0;//纯虚函数，定义抽象方法
		virtual void fun()=0;
		virtual ~Shape()//析构函数最好定义为虚函数，以防止有内存为被正确释放
		{
			
		}
};

class Circle:public Shape
{
	private:
		int radius;
	public:
		Circle(int r)
		{
			radius =  r;
		}
		void area()
		{
			cout<<"Circle`s area = "<<3.14*radius*radius<<endl;
		}
		void fun()//需要实现父类中的所有抽象方法
		{
			
		}
};

class Rectangle:public Shape
{
	private:
		int weight;
		int height;
	public:
		Rectangle(int w, int h)
		{
			weight = w;
			height = h;
		}
		void area()
		{
			cout<<"Rectangle`s area = "<<weight*height<<endl;
		}
		void fun()//需要实现父类中的所有抽象方法
		{
			
		}
};

void getArea(Shape *p)
{
	p->area();
}

int main()
{
	Circle c(4);
	Rectangle r(10,10);
	
	getArea(&c);
	getArea(&r);
	
	return 0;
}
