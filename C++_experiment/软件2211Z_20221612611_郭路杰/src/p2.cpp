#include "../include/p2.h"
#include <iostream>
using namespace std;
//定义类模版成员函数
template<typename _Tp> Point2D< _Tp>::Point2D(){
	px=0;py=0;
}
template<typename _Tp> void Point2D< _Tp>::p_display(){
	cout<<"P("<<px<<","<<py<<")"<<endl;
}
template<typename _Tp> Point2D< _Tp>::Point2D(_Tp x, _Tp y){
	px=x;py=y;
}




