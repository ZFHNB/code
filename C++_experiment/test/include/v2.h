#ifndef _V2_H
#define _V2_H
#include "./p2.h"
//定义类模版
template<typename _Tp> class Vector2D{
	public:
	Vector2D();//默认生成零向量，也就是vx=0，vy=0
	Vector2D(_Tp x, _Tp y);//使用一组形参初始化向量，vx=x，vy=y
	Vector2D(Point2D<_Tp>& end_p);//使用坐标点end_p生成向量，表示从坐标原点到坐标点end_p的向量
	Vector2D(Point2D<_Tp>& start_p, Point2D<_Tp>& end_p);//通过一组起点和终点得到向量，向量为终点的坐标-起点的坐标
	_Tp  norm();//计算向量的模，用法a.norm()，返回值是一个标量
	_Tp  get_x();//得到向量的x分量的值，返回值是一个标量
	_Tp  get_y();//得到向量的y分量的值，返回值是一个标量
	Vector2D<_Tp> unit();//求单位向量(模为1的矢量)，用法a.unit(),返回值还是一个向量
	Vector2D<_Tp> operator+(Vector2D<_Tp>& b);//向量加法，用法a+b，返回值还是一个向量,需要用到this指针
	Vector2D<_Tp> operator-(Vector2D<_Tp>& b);//向量减法，用法a-b，返回值还是一个向量,需要用到this指针
	Vector2D<_Tp> cross(Vector2D<_Tp>& b);//向量的叉积，用法a.cross(b)，返回值还是一个向量
	Vector2D<_Tp> project_to(Vector2D<_Tp>& b);//向量的投影，用法a.project_to(b)，表示向量a在向量b所在方向的投影向量，返回值还是一个向量
	_Tp  dot(Vector2D<_Tp>& b);//向量的点积，用法a.dot(b)，返回值是一个标量
	_Tp  included_angle(Vector2D<_Tp>& b);//求向量a和向量b的夹角，用法a.included_angle(b)，返回值为弧度制
	Vector2D<_Tp> operator*( _Tp k);//标量和向量的乘法，用法V*k，返回值还是一个向量,需要用到this指针
	Vector2D<_Tp> operator/( _Tp k);//向量对标量的除法，用法V/k，返回值还是一个向量,需要用到this指针
	void v_display();
	private:
	_Tp vx;	_Tp vy;
};


//类模版显式实例化
template class Vector2D<int>;
template class Vector2D<float>;
template class Vector2D<double>;
template class Vector2D<long double>;

#endif

