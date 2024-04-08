#include <iostream>
#include <string.h>
using namespace std;

typedef struct{
	char name[10];
	int num;
	char sex;
}Student;

int main()
{
	Student *p = new Student;
	
	strcpy(p->name,"Wang Yun");
	p->num = 10123;
	p->sex = 'M';
	
	cout<<p->name<<"  "<<p->num<<"  "<<p->sex<<endl;
	
	delete p;
	
	return 0;
}
