#include <stdio.h>

//此处的x,y为实际参数，实现运算的原理为机械性的替换（与函数不同），因此需要加括号，防止优先级错误
#define MAX(x, y) (((x)>(y))?(x):(y))//注意：MAX需与其参数紧密相连，不得插入空格

#define SQUARE(x) x * x

int main() {

	int x, y;

//	printf("请输入两个正数：");
//	scanf("%d%d", &x, &y);
//	printf("%d 是较大的那个数\n", MAX(x, y));

	printf("请输入一个整数");
	scanf("%d", &x);

	printf("%d 的平方是：%d\n", x, SQUARE(x));
	printf("%d 的平方是：%d\n", x + 1, SQUARE(x + 1));//此句输出错误

	return 0;
}
