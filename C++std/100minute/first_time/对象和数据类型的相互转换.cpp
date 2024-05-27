#include <iostream>
using namespace std;

class Complex//定义复数类
{
private:
    double real;//实部
    double imag;//虚部
public:
    Complex(){}

    //其他数据类型转换为类对象：转换构造函数 （构造函数 赋值运算符重载亦可）
    Complex(double r)//2.转换构造函数,使用时的作用相当于强制类型转换
    {
        real = r;
        imag = 0;
    }

    Complex(double real, double imag):real(real),imag(imag){}

    //类对象转换为其他数据类型：类型转换函数
    operator double ()//类型转换函数
    {
        return real;
    }

    friend Complex operator+(Complex c1, Complex c2);
    friend ostream& operator<<(ostream &output, Complex c);
};

Complex operator+(Complex c1, Complex c2)
{
    return Complex(c1.real+c2.real, c1.imag+c2.imag);
}
ostream& operator<<(ostream &output, Complex c)
{
    output<<c.real<<"+"<<c.imag<<"i"<<endl;
    return output;
}
int main()
{
    Complex c1(1.1, 2.2);
    Complex c2(2.2, 3.3);
    Complex c3 = c1 + c2;
    cout<<c3<<endl;

    // Complex c4;
    // c4 = c1 + 1.1;//调用转换构造函数创建临时对象
    // cout<<c4<<endl;

    // cout<<(double)c1<<endl;//调用类型转换函数

    // double d1,d2;
    // d1=1.1;
    // d2=d1+c1;
    // //类型转换的过程会自动完成(自动调用转换构造函数)：
    // cout<<d2<<endl;


    return 0;
}