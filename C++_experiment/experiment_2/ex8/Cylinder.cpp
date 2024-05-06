#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Cylinder.h"
using namespace std;
Cylinder::Cylinder(double a, double b, double r, double h):Circle(a, b, r), height(h) {}
void Cylinder::SetHeight(double h) { height = h; }
double Cylinder::GetHeight() const { return height; }
double Cylinder::Area() const { return 2 * Circle::Area() + 2 * 3.14159 * radius * height; }
double Cylinder::Volume() const { return Circle::Area() * height; }
ostream& operator<<(ostream& output, const Cylinder& cy)
{
	output<<"Center=["<<cy.x<<", "<<cy.y<<"], r="<<cy.radius<<", h="<<cy.height
		<< "\narea="<<cy.Area()<<", volume="<<cy.Volume()<<endl;
	return output;
}