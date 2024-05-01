#ifndef __CYLINDER_H__
#define __CYLINDER_H__

#include <iostream>
using namespace std;

class Cylinder : public Circle
{
public:
	Cylinder(double x = 0, double y = 0, double r = 0, double h = 0);
	void SetHeight(double);
	double GetHeight() const;
	double Area() const;
	double Volume() const;
	friend ostream& operator<<(ostream&, const Cylinder&);
protected:
	double height;
};

#endif