#include <iostream>
using namespace std;

float a = 13.5;

int main()
{
	int a = 5;
	
	cout<<"局部变量a = "<<a<<endl;//输出局部变量
	cout<<"全局变量a = "<<::a<<endl;//输出全局变量，注意：不能用"::"访问函数中的局部变量
	
	return 0;
}
