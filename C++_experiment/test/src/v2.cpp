#include "../include/v2.h"
#include <iostream>
using namespace std;

template<typename _Tp> Vector2D< _Tp>::Vector2D(){
	vx=0; vy=0;
}
template<typename _Tp> Vector2D< _Tp>::Vector2D(_Tp x, _Tp y){
	vx=x; vy=y;
}
template<typename _Tp> _Tp Vector2D< _Tp>::get_x(){
	return vx;
}
template<typename _Tp> _Tp Vector2D< _Tp>::get_y(){
	return vy;
}
template<typename _Tp> void Vector2D< _Tp>::v_display(){
	cout<<"V["<<vx<<","<<vy<<"]"<<endl;
}


