#include <iostream>
using namespace std;

class Date
{
	private:
		int year,month,day;//数据成员，不可通过"."访问
	public:
		Date(){
			cout<<"请输入yyyy-mm-dd"<<endl;
			cin>>year>>month>>day;
			cout<<"创建对象时，构造函数(不带参数)被调用"<<endl;
		}
		Date(int y, int m, int d)//带参数的构造函数，名字与类名一致，且没有返回类型
		{
			year = y;
			month = m;
			day = d;
			cout<<"创建对象时，构造函数(带参数)被调用"<<endl;
		}
		Date(const Date &t)
		{
			year = t.year;
			month = t.month;
			day = t.day;
			cout<<"浅拷贝时，拷贝构造函数被调用"<<endl;
		}
		~Date()//析构函数
		{
			cout<<"对象生命周期结束，析构函数被调用"<<endl;
		}
		void show()//普通的成员函数
		{
			cout<<year<<"."<<month<<"."<<day<<endl;
		}
};

int main()
{
	Date d1(2024,3,13);
	
	Date *p = NULL;//对象指针
	p = &d1;
	
	//以下方法等效
	d1.show();
	p->show();
	(*p).show();
	
	return 0;
}
