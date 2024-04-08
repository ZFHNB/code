#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	
	int a = 9, b = 0;
	
	cout<<"交换前：\na = "<<a<<'\t'<<"b = "<<b<<endl;
	
	swap(a, b);
	
	cout<<"交换后：\na = "<<a<<'\t'<<"b = "<<b<<endl;

	return 0;
}
