#ifndef _P2_H
#define _P2_H
//定义类模版
template<typename _Tp> class Point2D{
	public:
	Point2D();//默认生成的点为平面直角坐标的原点，也就是px=0，py=0
	Point2D(_Tp x, _Tp y);//使用一组形参初始化，px=x，py=y
	void p_display();
	protected:
	_Tp px;	_Tp py;	
};
//类模版显式实例化
template class Point2D<int>;
template class Point2D<float>;
template class Point2D<double>;
template class Point2D<long double>;
#endif
