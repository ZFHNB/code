#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stack;
    stack.push(1);
    cout<<stack.top()<<endl;
    stack.pop();
    return 0;
}