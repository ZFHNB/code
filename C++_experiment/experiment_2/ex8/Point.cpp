#include "Point.h"
Point::Point(double a, double b){x = a; y = b;}
void Point::SetPoint(double a, double b){x = a; y = b;}
ostream& operator<<(ostream& output, const Point& p)
{
	output<<"["<<p.x<<", "<<p.y<<"]"<<endl;
	return output;
}