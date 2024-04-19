#include <iostream>
#include <string>
using namespace std;

class Date
{
	private:
		int year,month,day;//数据成员，不可通过"."访问
	public:
		Date(){
			cout<<"创建Date对象时，构造函数(不带参数)被调用"<<endl;
			cout<<"请输入yyyy-mm-dd"<<endl;
			cin>>year>>month>>day;
		}
		Date(int y, int m, int d)//带参数的构造函数，名字与类名一致，且没有返回类型
		{
			year = y;
			month = m;
			day = d;
			cout<<"创建Date对象时，构造函数(带参数)被调用"<<endl;
		}
		// Date(const Date &t)//拷贝构造函数
		// {
		// 	year = t.year;
		// 	month = t.month;
		// 	day = t.day;
		// 	cout<<"浅拷贝时，拷贝构造函数被调用"<<endl;
		// }

		//在函数的参数、返回值为类的对象，复制构造函数也会被调用
		Date(const Date &t)//复制构造函数,写法与拷贝构造函数相同？？？！
		{
			year = t.year;
			month = t.month;
			day = t.day;
			cout<<"复制对象时，复制构造函数被调用"<<endl;
		}
		~Date()//析构函数,调用顺序与构造函数相反
		{
			cout<<"对象生命周期结束，析构函数被调用"<<endl;
		}
		void show() const//普通的成员函数
		{
			cout<<year<<"."<<month<<"."<<day<<endl;
		}
};

//对象成员（一个对象作为另一个对象的成员）
//调用顺序：先对象成员的构造函数后自身的构造函数
class Person{
	private:
		string name;
		int age;
		char gender;
		Date date;
		static int count;//静态数据成员（是类的一部分，不是对象的一部分，而可以被对象名引用），需要在类外对其初始化
	public:
		Person(string n = " ", int a = 0, char g = 0, int y = 1, int m = 1, int d = 1):date(y, m, d)//对象成员的初始化放在初始化列表后,要注意对象成员中所需的参数要与初始化列表中的一致
		{
			name = n;
			age = a;
			gender = g;
			count++;
			cout<<"创建Person对象时，构造函数(带参数)被调用"<<endl;
		}
		~Person()//析构函数
		{
			count--;
		}
		void show() const
		{
			cout<<name<<"\t"<<age<<"\t"<<gender<<endl;
			date.show();
		}
		static void showCount()//静态函数不属于某一对象（是类的一部分，不是对象的一部分，而可以被对象名引用），因此静态函数没有this指针，因此值用来访问静态数据成员
		{
			cout<<"Person个数："<<count<<endl;
		}
		friend ostream &operator<<(ostream &q, const Person &p);//友元函数
};

ostream &operator<<(ostream &q, const Person &p)//操作符重载
{
	cout<<p.name<<"\t"<<p.age<<"\t"<<p.gender<<endl;
	p.date.show();
}

int Person::count = 0;//通过类名直接访问并初始化静态成员变量

int main()
{
	Date d1(2024,3,13);
	d1.show();
	
	Date d2 = d1;//拷贝构造函数（浅拷贝）用一个已知的对象去初始化一个未知的对象时，指向同一块内存地址
	d2.show();
	
	//在函数的参数、返回值为类的对象，复制构造函数也会被调用
	Date d3;//会调用不带参数的构造函数
	d3 = d1;//深拷贝（会调用复制构造函数），新对象与原对象的内存独立，可避免共享资源带来的潜在问题
	d3.show();

	Date d4(d1);//深拷贝（对象的复制）
	d4.show();

//	Date *p = NULL;//对象指针
//	p = &d1;
//	
//	//以下方法作用一致
//	d1.show();
//	p->show();
//	(*p).show();
//	
//	//数组方式创建多个对象
//	Date arr[3] = {Date(1,1,1), Date(2,2,2), Date()};
//	for(int i = 0; i<3 ;i++)
//	{
//		arr[i].show();
//	}
//	
//	//对象的引用
//	Date &d4 = d1;
//	d4.show();
//	
//	//动态申请空间new、delete
//	Date *pp = new Date(1998,9,8);
//	pp->show();
//	delete pp;

	// const Person p1("郭路杰", 19, 'M', 2004, 12, 24), p2("ZFH", 19, 'M', 2004, 12, 24);//常对象只能调用常成员函数，即只能调用const修饰函数
	// Person *p = new Person();
	// p1.show();
	// Person::showCount();//通过类名直接访问静态函数
	
	// cout<<"-------------------"<<endl;
	
	// cout<<p1<<endl;


	
	return 0;
}
