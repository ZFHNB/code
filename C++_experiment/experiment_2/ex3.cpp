//3.请编写程序，处理一个复数与一个double数相加的运算，
//结果存放在一个double型的变量d1中，
//输出d1的值，
//再以复数形式输出此值。
//定义Complex(复数)类，在成员函数中包含重载类型转换运算符： operator double( ){return real;}

#include <iostream>
using namespace std;

class Complex//定义复数类
{
private:
    double real;//实部
    double imag;//虚部
public:
    //构造函数
    Complex(){}
    Complex(double real, double imag):real(real),imag(imag){}
    //转换构造函数
    Complex(double real)
    {
        this->real = real;
        this->imag = 0;
    }

    //类对象转换为其他数据类型：类型转换函数
    operator double ()//类型转换函数
    {
        return real;
    }

    friend ostream& operator<<(ostream &output, Complex c);
};
ostream& operator<<(ostream &output, Complex c)
{
    output<<c.real<<"+"<<c.imag<<"i"<<endl;
    return output;
}
int main()
{
    Complex c1(1.1, 2.2);
    int d1 = c1 + 3.3;//调用类型转换函数
    cout<<d1<<endl;

    Complex d(d1);
    cout<<d<<endl;

    return 0;
}