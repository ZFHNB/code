#include <iostream>
using namespace std;

class Time
{
	public:
		Time(int, int, int);
		int hour;
		int minute;
		int sec;
		void get_time();
};

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	sec = s;
}

void Time::get_time()
{
	
}

int main()
{


	return 0;
}
