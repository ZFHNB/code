#include "p2.h"
#include "v2.h"

#include <iostream>
using namespace std;

int main(void){
	Point2D<int> p1;
	p1.p_display();
	
	Vector2D<int> v2(0,1);
	v2.v_display();
	v2=v2*2;
	v2.v_display();
	return 0;
}
