#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Cylinder.h"
using namespace std;
int main()
{
	Cylinder cy1(1.1, 2.2, 3.3, 4.4);
	cout<<"调用构造方法:\nx="<<cy1.GetX()<<", y="<<cy1.GetY()<<", r="
		<< cy1.GetRadius()<<", h="<<cy1.GetHeight()<<"\narea="<<cy1.Area()
		<< ", volume="<<cy1.Volume()<<endl;
 
	cy1.SetHeight(10);
	cy1.SetRadius(9.9);
	cy1.SetPoint(5, 5);
	cout<<"更新后的数据:\n"<<cy1<<endl;
	Point& pRef = cy1;
	cout<<"Point.pRef:"<<pRef<<endl;
	Circle& cRef = cy1;
	cout<<"Circle.cRef:"<<cRef<<endl;
	return 0;
}