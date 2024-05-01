//在程序中使用继承和组合。
//在定义Professor类对象prof1时给出所有数据的初值
//然后修改prof1的生日数据
//最后输出prof1的全部最新数据。
#include <iostream>
#include <string>
using namespace std;

class Teacher
{
    private:
        int num;
        string name;
        char sex;
    public:
        Teacher(int nu, string na, char s) : num(nu),name(na),sex(s){}
        void showT()
        {
            cout<<"num:"<<num<<"\t"<<"name:"<<name<<"\t"<<"sex:"<<sex<<endl;
        }
};
class BirthDate
{
    private:
        int year,month,day;
    public:
        BirthDate(int y, int m, int d) : year(y),month(m),day(d){}
        void showB()
        {
            cout<<"BirthDate:"<<year<<"-"<<month<<"-"<<day<<endl;
        }
};
class Professor:public Teacher
{
    private:
        BirthDate birthday;
    public:
        Professor(int nu = 1, string na = "zhangsan", char s = 'm', int y = 2000, int m = 1, int d = 1) : 
        Teacher(nu,na,s), birthday(y,m,d){}
        void showP()
        {
            this->showT();
            birthday.showB();
        }
};
int main()
{
    Professor prof1(2,"lisi",'w',1999,12,31);
    prof1.showP();

    return 0;
}