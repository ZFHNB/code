#include <iostream>
#include <string>
using namespace std;

class Student {
	private:
		string id;
		int score;
	public:
		Student(string i, int s)
		{
			id = i;
			score = s;
		}
		bool operator>(Student &s);
	friend ostream &operator<<(ostream &qq, const Student &s);
};

ostream &operator<<(ostream &output, const Student &s)
{
	output<<s.id<<"\t"<<s.score<<endl;
	return output;
}

bool Student::operator>(Student &s)
{
	if(score>s.score)
		return true;
	else
		return false;
}

int main() {
	
	Student s1("f111",89), s2("f222",78);
	
	cout<<s1<<s2<<endl;
	
	if(s1>s2)
		cout<<s1;
	else 
		cout<<s2;

	return 0;
}
