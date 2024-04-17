// 建立一个对象数组，内放5个学生的数据（学号、成绩），
// 设立一个函数max,
// 用指向对象的指针作函数参数，在max函数中找出5个学生中成绩最高者，并输出其学号。
#include <iostream>
using namespace std;

class Student
{
public:
    int num;
    int score;

    void input()
    {
        cout << "请输入学号：" << endl;
        cin >> num;
        cout << "请输入成绩：" << endl;
        cin >> score;
    }
};
Student max(Student *s)
{
    int index = 0;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (s[index].score < s[i].score)
        {
            index = i;
        }
    }
    return s[index];
}
int main()
{
    Student s[5];
    for (int i = 0; i < 5; i++)
    {
        s[i].input();
    }
    cout<<"成绩最高者的学号为："<<max(s).num<<endl;

    return 0;
}