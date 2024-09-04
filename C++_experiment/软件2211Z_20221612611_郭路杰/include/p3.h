#ifndef _P3_H
#define _P3_H
#include "./p2.h"
//定义类模版
template<typename _Tp> 
class Point3D : public Point2D< _Tp>{
	public:
	Point3D();//默认生成的点为三维直角坐标的原点，也就是px=0，py=0，pz=0
	Point3D(_Tp x, _Tp y, _Tp z);//使用一组形参初始化，px=x，py=y，pz=z
	void p_display();
	private:
	_Tp pz;

	// 声明Vector3D为友元类
	template<typename _Tp2> friend class Vector3D;
};
//类模版显式实例化
template class Point3D<int>;
template class Point3D<float>;
template class Point3D<double>;
template class Point3D<long double>;
#endif
