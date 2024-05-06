#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include <iostream>
using namespace std;

class Circle : public Point
{
public:
	Circle(double x = 0, double y = 0, double r = 0);
	void SetRadius(double r);
	double GetRadius() const;
	double Area() const;
	friend ostream& operator<<(ostream&, const Circle&);
protected:
	double radius;
};

#endif