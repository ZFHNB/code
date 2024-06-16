#include <vector>
#include <iostream>
using namespace std;

int main()
{
	//vector动态数组：
	
	//初始化：vector<elem> arr(长度,[初值])
	vector<int> arr(100,0);
	vector<int>::iterator it = arr.begin();
	while(it != arr.end())
	{
		printf("%d", *it);
	}
	
	return 0;
}
