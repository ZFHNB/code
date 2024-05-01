//1.有两个矩阵a和b，均为2行3列。求两个矩阵之和。重载运算符“+”，使之能用于矩阵相加。如： c=a+b。

#include  <iostream>
using namespace std;

class Matrix//创建矩阵类
{
    private:
        int matrix[2][3];
    public:
        Matrix(int a[2][3]);
        Matrix operator+(Matrix m);
        void display();
};
Matrix :: Matrix(int a[2][3])//类外初始化构造函数
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
           this->matrix[i][j] = a[i][j];
        }
    }
}
Matrix Matrix :: operator+(Matrix m)//运算符重载
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
       {
           m.matrix[i][j] += this->matrix[i][j];
        }
    }
    return m;
}
void Matrix::display()
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
           cout<<this->matrix[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    int a[2][3] = 
    {
        {1,1,1},
        {2,2,2}
    };
    int b[2][3] = 
    {
        {1,1,1},
        {2,2,2}
    };
    Matrix m1(a);
    Matrix m2(b);
    m1=m1+m2;
    m1.display();
}