#include <stdio.h>

int main(){

	int num = 520;
	const int cnum = 880;
	int * const p = &num;//ָ��ǳ����ĳ���ָ��
	int * const *pp = &p;//ָ��ָ��ǳ����ĳ���ָ�롱��ָ��

	const int *const q = &cnum;//ָ�����ĳ���ָ��
	const int *const *qq = &q;//ָ��ָ�����ĳ���ָ�롱��ָ��
	
	return 0;
}
