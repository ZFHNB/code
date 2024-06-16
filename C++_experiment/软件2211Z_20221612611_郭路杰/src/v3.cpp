#include "../include/v3.h"
#include <iostream>
#include <cmath>
using namespace std;

//默认生成零向量，也就是vx=0，vy=0，vz=0
template<typename _Tp> Vector3D< _Tp>::Vector3D(){
	vx=0;vy=0;vz=0;
}

//使用一组形参初始化向量，vx=x，vy=y，vz=z
template<typename _Tp> Vector3D< _Tp>::Vector3D(_Tp x, _Tp y, _Tp z){
	vx=x;vy=y;vz=z;
}

// 使用坐标点end_p生成向量，表示从坐标原点到坐标点end_p的向量
template<typename _Tp> Vector3D<_Tp>::Vector3D(Point3D<_Tp>& end_p){
    vx = end_p.px;
	vy = end_p.py;
	vz = end_p.pz;
}

// 通过一组起点start_p和终点end_p得到向量，向量为终点的坐标-起点的坐标
template<typename _Tp> Vector3D<_Tp>::Vector3D(Point3D<_Tp>& start_p, Point3D<_Tp>& end_p){
	vx = end_p.px - start_p.px;
    vy = end_p.py - start_p.py; 
    vz = end_p.pz - start_p.pz;
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

// 计算向量的模
template<typename _Tp>
_Tp Vector3D<_Tp>::norm() {
    return sqrt(vx * vx + vy * vy + vz * vz);
}

// 求单位向量
template<typename _Tp>
Vector3D<_Tp> Vector3D<_Tp>::unit() {
    _Tp n = norm();
    if (n == 0) return *this; // 如果向量是零向量，则返回自身
    return Vector3D<_Tp>(vx / n, vy / n, vz / n);
}

// 向量加法
template<typename _Tp> Vector3D<_Tp> Vector3D<_Tp>::operator+(Vector3D<_Tp>& b) {
    return Vector3D<_Tp>(vx + b.vx, vy + b.vy, vz + b.vz);
}

// 向量减法
template<typename _Tp> Vector3D<_Tp> Vector3D<_Tp>::operator-(Vector3D<_Tp>& b) {
    return Vector3D<_Tp>(vx - b.vx, vy - b.vy, vz - b.vz);
}

// 标量和向量的乘法
template<typename _Tp> Vector3D<_Tp> Vector3D<_Tp>::operator*(_Tp k) {
    return Vector3D<_Tp>(vx * k, vy * k, vz * k);
}

// 向量对标量的除法
template<typename _Tp> Vector3D<_Tp> Vector3D<_Tp>::operator/(_Tp k) {
    if (k == 0) cout << "不能除以零" << endl;
    return Vector3D<_Tp>(vx / k, vy / k, vz / k);
}

// 向量的叉积
template<typename _Tp> Vector3D<_Tp> Vector3D<_Tp>::cross(Vector3D<_Tp>& b) {
    return Vector3D<_Tp>(
        vy * b.vz - vz * b.vy,
        vz * b.vx - vx * b.vz,
        vx * b.vy - vy * b.vx
    );
}

// 向量的投影
template<typename _Tp> Vector3D<_Tp> Vector3D<_Tp>::project_to(Vector3D<_Tp>& b) {
    _Tp b_norm_square = b.vx * b.vx + b.vy * b.vy + b.vz * b.vz;
    if (b_norm_square == 0) return *this; // 如果向量b是零向量，则返回自身
    _Tp projection = (vx * b.vx + vy * b.vy + vz * b.vz) / b_norm_square;
    return Vector3D<_Tp>(b.vx * projection, b.vy * projection, b.vz * projection);
}

// 向量的点积
template<typename _Tp> _Tp Vector3D<_Tp>::dot(Vector3D<_Tp>& b) {
    return vx * b.vx + vy * b.vy + vz * b.vz;
}

// 求向量a和向量b的夹角
template<typename _Tp> _Tp Vector3D<_Tp>::included_angle(Vector3D<_Tp>& b) {
    _Tp dot_product = dot(b);
    _Tp norm_a = norm();
    _Tp norm_b = b.norm();
    if (norm_a == 0 || norm_b == 0) {
        cout << "数据异常" << endl;
    }
    return acos(dot_product / (norm_a * norm_b));
}
