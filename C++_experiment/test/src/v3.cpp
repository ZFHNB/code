#include "../include/v3.h"
#include <iostream>
using namespace std;

template<typename _Tp> Vector3D< _Tp>::Vector3D(){
	vx=0;vy=0;vz=0;
}
template<typename _Tp> Vector3D< _Tp>::Vector3D(_Tp x, _Tp y, _Tp z){
	vx=x;vy=y;vz=z;
}
template<typename _Tp> void Vector3D< _Tp>::v_display(){
	cout<<"V["<<vx<<","<<vy<<","<<vz<<"]"<<endl;
}

template<typename _Tp> _Tp Vector3D< _Tp>::get_x(){
	return vx;
}
template<typename _Tp> _Tp Vector3D< _Tp>::get_y(){
	return vy;
}
template<typename _Tp> _Tp Vector3D< _Tp>::get_z(){
	return vz;
}
