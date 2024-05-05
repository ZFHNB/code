#include <stdio.h>
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);
int calc(int (*fp)(int, int), int, int);
int (*select(char))(int, int);

int add(int num1, int num2) {
	return num1 + num2;
}
int sub(int num1, int num2) {
	return num1 - num2;
}
int mul(int num1, int num2) {
	return num1 * num2;
}
int div(int num1, int num2) {
	return num1 / num2;
}
int calc(int (*fp)(int num1, int num2), int num1, int num2) {
	return (*fp)(num1, num2);
}
int (*select(char op))(int num1, int num2) {
	switch (op) {
		case '+':
			return add;
		case '-':
			return sub;
		case '*':
			return mul;
		case '/':
			return div;
	}
}

int main() {
	int num1, num2;
	char op;
	int (*fp)(int, int);

	printf("请输入一个式子(如1+3)：");
	scanf("%d%c%d", &num1, &op, &num2);

	fp = select(op);

	printf("%d %c %d = %d", num1, op, num2, (*fp)(num1, num2));

	return 0;
}
