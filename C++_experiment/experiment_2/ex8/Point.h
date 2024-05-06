#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using namespace std;

class Point
{
public:
	Point (double x = 0, double y = 0);
	void SetPoint(double, double);
	double GetX() const { return x; }
	double GetY() const { return y; }
	friend ostream& operator<<(ostream&, const Point&);
protected:
	double x, y;
};

#endif