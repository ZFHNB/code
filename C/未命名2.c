#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
//From Wuhan Institute of Technology Wolf King Team
int Njz(int N,int a)//��ʮ������Nת����a�����ַ���
{
  int sum=0;
  while(N)
  {
   sum+=N%a;//������
    N/=a;
  }
  return sum;
}
int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  int i,N,sum;
  for(i=1,N=0;N<2023;i++)
  {
     if(i%Njz(i,2)==0&&i%Njz(i,8)==0&&i%Njz(i,10)==0&&i%Njz(i,16)==0) 
     {N++;sum=i;}
  }
  printf("%d\n",sum);
  return 0;
}
