#include <iostream>
using namespace std;

void function(int, int b = 5);//函数声明

void function(int a, int b)
{
    cout<<a<<"\t"<<b<<endl;
}

int main()
{
    function(1,2);//不使用默认参数
    function(1);//使用默认参数
    
    return 0;
}