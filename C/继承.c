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
		Date(const Date &t)
		{
			year = t.year;
			month = t.month;
			day = t.day;
			cout<<"浅拷贝时，拷贝构造函数被调用"<<endl;
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
		static int count;//静态数据成员，需要在类外对其初始化
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
		static void showCount()
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

class Student:public Person
{
	int grade,score;
	public:
		Student();
};

int main()
{

	const Person p1("郭路杰", 19, 'M', 2004, 12, 24), p2("ZFH", 19, 'M', 2004, 12, 24);//常对象只能调用常成员函数，即只能调用const修饰函数
	Student s;
	s.show();
	return 0;
}
