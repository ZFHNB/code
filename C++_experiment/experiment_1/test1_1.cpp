// （1）将数据成员改为私有的；
// （2）将输入和输出的功能改为由成员函数实现；
// （3）在类体内定义成员函数。
#include <iostream>
using namespace std;

class Time
{
    private:
        int hour;
        int minute;
        int sec;
    public:
        void input_time()
        {
            cin>>hour>>minute>>sec;
        }
        void show_time()
        {
            cout<<hour<<":"<<minute<<":"<<sec<<endl;
        }
};

int main()
{
    Time t1;
    t1.input_time();
    t1.show_time();

    return 0;
}