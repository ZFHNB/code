#include <vector>
#include <iostream>
using namespace std;

int main()
{
	//vector��̬���飺
	
	//��ʼ����vector<elem> arr(����,[��ֵ])
	vector<int> arr(100,0);
	vector<int>::iterator it = arr.begin();
	while(it != arr.end())
	{
		printf("%d", *it);
	}
	
	return 0;
}
