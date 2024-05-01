#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Cylinder.h"
using namespace std;
int main()
{
	Cylinder cy1(1.1, 2.2, 3.3, 4.4);
	cout<<"\noriginal cylinder:\nx="<<cy1.GetX()<<", y="<<cy1.GetY()<<", r="
		<< cy1.GetRadius()<<", h="<<cy1.GetHeight()<<"\narea="<<cy1.Area()
		<< ", volume="<<cy1.Volume()<<endl;
 
	cy1.SetHeight(10);
	cy1.SetRadius(9.9);
	cy1.SetPoint(5, 5);
	cout<<"\nnew cylinder:\n"<<cy1;
	Point& pRef = cy1;
	cout<<"\nPoint.pRef:"<<pRef;
	Circle& cRef = cy1;
	cout<<"\nCircle.cRef:"<<cRef;
	return 0;
}