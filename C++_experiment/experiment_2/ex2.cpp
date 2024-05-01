//2.定义一个复数类Complex
//重载运算符“+”,“-”,“*”,“/”，使之能用于复数的加、减、乘、除。
//运算符重载函数作为Complex类的成员函数。
//编程序，分别求两个复数之和、差、积和商。 

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

    Complex operator+(Complex c);
    Complex operator-(Complex c);
    Complex operator*(Complex c);
    Complex operator/(Complex c);
    friend ostream& operator<<(ostream &output, Complex c);
};
Complex Complex :: operator+(Complex c)
{
    return Complex(this->real+c.real, this->imag+c.imag);
}
Complex Complex :: operator-(Complex c)
{
    return Complex(this->real-c.real, this->imag-c.imag);
}
Complex Complex :: operator*(Complex c)
{
    return Complex(this->real*c.real, this->imag*c.imag);
}
Complex Complex :: operator/(Complex c)
{
    return Complex(this->real/c.real, this->imag/c.imag);
}
ostream& operator<<(ostream &output, Complex c)
{
    output<<c.real<<"+"<<c.imag<<"i"<<endl;
    return output;
}
int main()
{
    Complex c1(5.5, 2.2);
    Complex c2(1.1, 1.1);

    cout<<"c1 = "<<c1<<"c2 = "<<c2<<endl;
    cout<<"c1 + c2 = "<<c1+c2;
    cout<<"c1 - c2 = "<<c1-c2;
    cout<<"c1 * c2 = "<<c1*c2;
    cout<<"c1 / c2 = "<<c1/c2;

    return 0;
}