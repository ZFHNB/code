#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
int main()
{
    // 向量（动态数组）
    vector<string> names;
    names.push_back("Hello ");
    names.push_back("world!");

    //迭代器是智能指针，即取值要用*
    vector<string>::iterator iter = names.begin();
    while( iter != names.end())
    {
        cout<<*iter<<endl;
        ++iter;
    }

    return 0;
}