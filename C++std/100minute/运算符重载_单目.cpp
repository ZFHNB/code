#include <iostream>
#include <unistd.h>
using namespace std;


class Time
{
    private:
        int sec;
        int minute;
    public:
        Time():minute(0),sec(0){}//若已存在任意构造方法，C++不会再提供默认无参构造方法
        Time(int m, int s):minute(m),sec(s){}
        void display()
        {
            cout<<minute<<":"<<sec<<endl;
        }
        // Time operator++();//作为类成员，可省略单目运算符中的参数
        friend Time& operator++(Time &t);//前置递增
        friend Time& operator++(Time &t, int);//后置递增

};

// Time Time::operator++()
// {
//     if(++sec>=60)
//     {
//         sec -= 60;
//         minute++;
//     }
//     return *this;
// }

//前置递增
Time& operator++(Time &t)
{
    if(++t.sec>=60)
    {
        t.sec=0;
        t.minute++;
    }
    return t;
}

//后置递增
Time& operator++(Time &t, int)
{
    return ++t;//返回临时对象
}

int main()
{
    Time t(1,50);
    
    while(1)
    {
        t++;
        t.display();
        sleep(1);
    }

    return 0;
}