#include <stdio.h>

int main(){

	int num = 520;
	const int cnum = 880;
	int * const p = &num;//指向非常量的常量指针
	int * const *pp = &p;//指向“指向非常量的常量指针”的指针

	const int *const q = &cnum;//指向常量的常量指针
	const int *const *qq = &q;//指向“指向常量的常量指针”的指针
	
	return 0;
}
