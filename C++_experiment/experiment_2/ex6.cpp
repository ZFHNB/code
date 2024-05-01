#include <iostream>
using namespace std;

class Student {
public:

protected:
	int num;
	string name;
	char sex;
};
class Student1 :protected Student
{
public:
	void get_value1() {
		cin>>num>>name>>sex;
		cin>>age>>addr;
	}
	void display_1() {
		cout<<"age: "<<age<<endl;
		cout<<"address: "<<addr<<endl;
		cout<<"num: "<<num<<endl;
		cout<<"name: "<<name<<endl;
		cout<<"sex: "<<sex<<endl;
	}
private:
	int age;
	string addr;
};
int main()
{
	Student1 s1;
	s1.get_value1();
	s1.display_1();
	return 0;
}