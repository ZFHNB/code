#include <stdio.h>
int add(int, int);
int sub(int, int);
int calc(int (*fp)(int, int),int,int);//将函数指针作为参数，要求参数的类型以及返回值与被引用函数的相同
int add(int num1, int num2)
{
  return num1 + num2;
}
int sub(int num1, int num2)
{
  return num1-num2;
}
int calc(int(*fp)(int, int),int num1, int num2)//此处需要传入的为需要被引用的函数的地址，即函数名
{
  return (*fp)(num1,num2);
}
int main()
{
  printf("3 + 5 = %d\n",calc(add,3,5));
  printf("3 - 5 = %d",calc(sub,3,5));
  return 0;
}
