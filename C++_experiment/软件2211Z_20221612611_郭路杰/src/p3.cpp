#include "../include/p2.h"
#include "../include/p3.h"
#include <iostream>
using namespace std;
//定义类模版成员函数
template<typename _Tp> 
Point3D< _Tp>::Point3D():Point2D< _Tp>::Point2D(){
	pz=0;
}
template<typename _Tp> 
void Point3D< _Tp>::p_display(){
	cout<<"P("<<Point2D< _Tp>::px<<","<<Point2D< _Tp>::py<<","<<pz<<")"<<endl;
}
template<typename _Tp> 
Point3D< _Tp>::Point3D(_Tp x, _Tp y, _Tp z){
	Point2D< _Tp>::px=x;
	Point2D< _Tp>::py=y;
	pz=z;
}
