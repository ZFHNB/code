#include <iostream>
#include <string>
using namespace std;

class Student {
	private:
		string id;
		int score;
	public:
		Student():id("f000"),score(0){};
		Student(string i, int s)
		{
			id = i;
			score = s;
		}
		friend ostream &operator<<(ostream &output, const Student &s);
		bool operator>(const Student &s)
		{
			return score>s.score;
		}
		Student& operator++()
		{
			score++;
			return *this;
		}
		Student& operator++(int)
		{
			return ++*this;
		}
};

ostream &operator<<(ostream &output, const Student &s)
{
	output<<s.id<<" "<<s.score<<endl;
	return output;
}

int main() {
	
	Student s1("f111",0), s2("f222",78);

	// cout<<s1<<s2<<endl;

	// if(s1>s2)
	// {
	// 	cout<<s1<<endl;
	// }
	// else
	// {
	// 	cout<<s2<<endl;
	// }s

	Student s3 = s1;//对象的复制
	s1++;
	s3;//整形可以连续++

	cout<<"s1:"<<s1<<endl;
	cout<<"s3:"<<s3<<endl;

	Student s4;
	s4 = s1;//对象的赋值
	s1++++;
	s4;

	cout<<"s1:"<<s1<<endl;
	cout<<"s4:"<<s4<<endl;

	return 0;
}
