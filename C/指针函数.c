#include <stdio.h>

char *getward(char);

char *getward(char b){
	switch(b){
		case 'a': return "apple";
		case 'b': return "banana";
		case 'c': return "cat";
		case 'd': return "dog";
		default: return "none";
	}
}
//ע�⣺��Ҫ���ؾֲ�������ָ��
//e.g.
/*
char *getward(char c);
char *getward(char c){
	char str1[] ="Apple";
	char str2[] ="Banana";
	char str3[] ="Cat";
	char str4[] ="Dog";
	char str5[] ="None";
	switch(c){
		case 'a' return str1:
		case 'b' return str2;
		case 'c' return str3;
		case 'd' return str4;
		default: return str5;
	}
}
*/

int main(){
	
	char input;
	
	printf("������һ����ĸ��\n");
	scanf("%c",&input);
	
	printf("%s\n",getward(input));

	return 0;
}
