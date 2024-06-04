#include "p2.h"
#include "p3.h"
#include "v3.h"

#include <iostream>
using namespace std;

int main(void){

	Point3D<int> p2(2,3,5);
	p2.p_display();
	
	Vector3D<int> v1(0,1,0);
	v1.v_display();
	v1=5*v1;
	v1.v_display();
	return 0;
}
