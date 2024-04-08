#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
//From Wuhan Institute of Technology Wolf King Team
int Njz(int N,int a)//把十进制数N转换成a进制字符串
{
  int sum=0;
  while(N)
  {
   sum+=N%a;//逆序存放
    N/=a;
  }
  return sum;
}
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int i,N,sum;
  for(i=1,N=0;N<2023;i++)
  {
     if(i%Njz(i,2)==0&&i%Njz(i,8)==0&&i%Njz(i,10)==0&&i%Njz(i,16)==0) 
     {N++;sum=i;}
  }
  printf("%d\n",sum);
  return 0;
}
