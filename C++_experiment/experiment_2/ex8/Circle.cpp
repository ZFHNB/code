#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;
Circle::Circle(double a, double b, double r) : Point(a, b), radius(r) {}
void Circle::SetRadius(double r) { radius = r; }
double Circle::GetRadius() const { return radius; }
double Circle::Area() const { return 3.14 * radius * radius; }
ostream& operator<<(ostream& output, const Circle& c)
{
	output<<"Center=["<<c.x<<", "<<c.y<<"], r="<<c.radius<<", area="<<c.Area()<<endl;
	return output;
}