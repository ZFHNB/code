#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	//vector动态数组：
	
	//初始化：vector<elem> arr(长度,[初值]);
	vector<int> arr1(10,0);
	vector<int>::iterator it1 = arr1.begin();
	while(it1 != arr1.end())
	{
		printf("%d", *it1);
		++it1;
	}
	printf("\n");
	//初始化二维数组：vector<vector<elem>> arr(行数, vector<elem> ([列数],[初值]));
	vector<vector<int>> arr2(10, vector<int> (10,1));
	
	//尾插，尾删：
	arr1.push_back(2);//尾插
	
	vector<int>::iterator it2 = arr1.begin();
	while(it2 != arr1.end())
	{
		printf("%d", *it2);
		++it2;
	}
	
	int a = arr1.back();//访问最后一个元素
	printf("arr1的最后一个元素：%d\n",a);
	
	arr1.pop_back();//尾删
	
	vector<int>::iterator it3 = arr1.begin();
	while(it3 != arr1.end())
	{
		printf("%d",*it3);
		++it3;
	}
	printf("\n");
	
	//获取长度：.size()
	printf("arr1的长度为：%d\n",arr1.size());
	for(int i = 0; i<arr1.size(); i++)
	{
		printf("%d",arr1[i]);
	}
	printf("\n");
	
	//清空：.clear()
	//判空：.empty() 空返回true，非空返回false
	arr1.clear();
	if(arr1.empty())
	{
		printf("arr1为空！！！\n");
	}
	
	//优先队列
	priority_queue<int, vector<int>> pque1
	
	//unique()
	vector<int> arr{1, 2, 1, 4, 5, 4, 4};
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	
	return 0;
}
