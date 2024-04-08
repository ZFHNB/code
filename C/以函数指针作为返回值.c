#include <stdio.h>
int add(int,int);
int sub(int,int);
int calc(int(*fp)(int, int),int, int);

int (*select(char))(int,int);
//对此函数声明的逐层理解：
/*
	1.select(char)为一个函数，用于返回一个函数指针；
	2.(*select(char))表示返回类型为一个函数指针（指向函数的指针）；
	3.(int,int)为被返回的函数的参数列表（函数指针所指向的函数的参数列表）；
	4.最外层的int为返回值类型，即被返回的函数的结果为整型。
*/

int add(int num1, int num2){
  return num1+num2;
}
int sub(int num1,int num2){
  return num1-num2;
}
int calc(int(*fp)(int, int),int num1, int num2)
{
  return (*fp)(num1,num2);
}
int (*select(char op))(int num1, int num2)
{
  switch(op){//通过op的不同取值来决定被返回的为哪个函数的地址
    case '+': return add;
    case '-': return sub;
  }
}

int main()
{
  int num1, num2;
  char op;
  int (*fp)(int,int);//用于指向select(op)函数存放的地址的函数指针

  printf("请输入一个式子(如1+3)：");
  scanf("%d%c%d",&num1,&op,&num2);

  fp = select(op);
  printf("%d %c %d = %d",num1,op,num2,calc(fp,num1,num2));

  return 0;
}
