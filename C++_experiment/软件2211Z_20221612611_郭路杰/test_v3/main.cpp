#include "p3.h"
#include "v3.h"
#include <iostream>
using namespace std;

int main(void) {
    // 默认构造
    Point3D<double> p1;
    p1.p_display();

    // 带参构造
    Point3D<double> p2(1, 2, 3);
    p2.p_display();

    // 使用Vector3D构造
    Vector3D<double> v1;
    v1.v_display();

    // 使用x, y, z构造Vector3D
    Vector3D<double> v2(4, 5, 6);
    v2.v_display();

    // 使用Point3D构造Vector3D（从原点到点p2）
    Vector3D<double> v3(p2);
    v3.v_display();

    // 使用两个Point3D构造Vector3D（从点p1到点p2）
    Vector3D<double> v4(p1, p2);
    v4.v_display();

    // 模长
    double norm = v2.norm();
    cout << "Norm: " << norm << endl;

    // x分量
    cout << "v2.x = " << v2.get_x() << endl;

    // y分量
    cout << "v2.y = " << v2.get_y() << endl;

    // z分量
    cout << "v2.z = " << v2.get_z() << endl;

    // 单位向量
    Vector3D<double> v_unit = v2.unit();
    v_unit.v_display();

    // 向量加法
    Vector3D<double> v_add = v1 + v2;
    v_add.v_display();

    // 向量减法
    Vector3D<double> v_sub = v2 - v1;
    v_sub.v_display();

    // 标量和向量的乘法
    Vector3D<double> v_scale = v2 * 2.5;
    v_scale.v_display();

    // 向量对标量的除法
    Vector3D<double> v_divide = v2 / 2.0;
    v_divide.v_display();

    // 向量的叉积
    Vector3D<double> v_cross = v2.cross(v4);
    v_cross.v_display();

    // 向量的投影
    Vector3D<double> v_projection = v2.project_to(v4);
    cout << "Projection: " << endl;
    v_projection.v_display();

    // 向量的点积
    double dot_product = v2.dot(v4);
    cout << "Dot Product: " << dot_product << endl;

    // 向量间的夹角
    double angle = v2.included_angle(v4);
    cout << "Angle: " << angle << endl;

    return 0;
}