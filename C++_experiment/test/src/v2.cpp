#include "../include/v2.h"
#include <iostream>
#include <cmath> // 用于计算模、点积等

using namespace std;

// 默认构造函数，生成零向量
template<typename _Tp> Vector2D<_Tp>::Vector2D() {
    vx = 0; vy = 0;
}

// 通过x和y坐标初始化向量
template<typename _Tp> Vector2D<_Tp>::Vector2D(_Tp x, _Tp y) {
    vx = x; vy = y;
}

// 使用坐标点end_p生成向量，表示从原点到end_p的向量
template<typename _Tp> Vector2D<_Tp>::Vector2D(Point2D<_Tp>& end_p) {
    vx = end_p.px; vy = end_p.py;
}

// 通过起点start_p和终点end_p生成向量
template<typename _Tp> Vector2D<_Tp>::Vector2D(Point2D<_Tp>& start_p, Point2D<_Tp>& end_p) {
    vx = end_p.px - start_p.px;
    vy = end_p.py - start_p.py;
}

// 计算向量的模
template<typename _Tp> _Tp Vector2D<_Tp>::norm() {
    return sqrt(vx * vx + vy * vy);
}

// 获取向量的x分量
template<typename _Tp> _Tp Vector2D<_Tp>::get_x() {
    return vx;
}

// 获取向量的y分量
template<typename _Tp> _Tp Vector2D<_Tp>::get_y() {
    return vy;
}

// 求单位向量
template<typename _Tp> Vector2D<_Tp> Vector2D<_Tp>::unit() {
    _Tp n = norm();
    if (n == 0) return *this; // 如果向量是零向量，则返回自身
    return Vector2D<_Tp>(vx / n, vy / n);
}

// 向量加法
template<typename _Tp> Vector2D<_Tp> Vector2D<_Tp>::operator+(Vector2D<_Tp>& b) {
    return Vector2D<_Tp>(vx + b.vx, vy + b.vy);
}

// 向量减法
template<typename _Tp> Vector2D<_Tp> Vector2D<_Tp>::operator-(Vector2D<_Tp>& b) {
    return Vector2D<_Tp>(vx - b.vx, vy - b.vy);
}

// 向量的叉积（仅适用于二维向量，返回标量）
template<typename _Tp> Vector2D<_Tp> Vector2D<_Tp>::cross(Vector2D<_Tp>& b) {
    return Vector2D<_Tp>(0, 0, vy * b.vx - vx * b.vy);
}

// 向量的投影
template<typename _Tp> Vector2D<_Tp> Vector2D<_Tp>::project_to(Vector2D<_Tp>& b) {
    _Tp b_norm_sq = b.vx * b.vx + b.vy * b.vy;
    if (b_norm_sq == 0) return *this; // 如果向量b是零向量，则返回自身
    _Tp scalar_proj = (vx * b.vx + vy * b.vy) / b_norm_sq;
    return Vector2D<_Tp>(b.vx * scalar_proj, b.vy * scalar_proj);
}

// 向量的点积
template<typename _Tp> _Tp Vector2D<_Tp>::dot(Vector2D<_Tp>& b) {
    return vx * b.vx + vy * b.vy;
}

// 求向量a和向量b的夹角
template<typename _Tp> _Tp Vector2D<_Tp>::included_angle(Vector2D<_Tp>& b) {
    _Tp dot_product = dot(b);
    _Tp norm_a = norm();
    _Tp norm_b = b.norm();
    if (norm_a == 0 || norm_b == 0) {
        // 抛出异常或返回一个错误值
        throw std::invalid_argument("Cannot compute the angle with a zero vector.");
    }
    return acos(dot_product / (norm_a * norm_b));
}

// 标量和向量的乘法（友元函数）
template<typename _Tp> Vector2D<_Tp> operator*(_Tp k) {
    return Vector2D<_Tp>(k * this->vx, k * this->vy);
}

// 标量和向量的乘法（成员函数）
template<typename _Tp> Vector2D<_Tp> Vector2D<_Tp>::operator*(_Tp k) {
    return Vector2D<_Tp>(vx * k, vy * k);
}

// 向量对标量的除法
template<typename _Tp> Vector2D<_Tp> Vector2D<_Tp>::operator/(_Tp k) {
    if (k == 0) throw runtime_error("Division by zero"); // 防止除以零
    return Vector2D<_Tp>(vx / k, vy / k);
}

// 显示向量
template<typename _Tp> void Vector2D<_Tp>::v_display() {
    cout << "V[" << vx << "," << vy << "]" << endl;
}

// 类模板显式实例化
template class Vector2D<int>;
template class Vector2D<float>;
template class Vector2D<double>;
template class Vector2D<long double>;