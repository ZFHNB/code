#include "p3.h"
#include "v3.h"
#include <iostream>
using namespace std;

int main(void) {
    // 创建两个点
    Point3D<double> p1(1, 2, 3);
    Point3D<double> p2(3, 2, 1);

    // 默认构造
    Vector3D<double> v1;
    v1.v_display();

    // 带参构造
    Vector3D<double> v2(4, 5, 6);
    v2.v_display();

    // 一点构造
    Vector3D<double> v3(p1);
    v3.v_display();

    //两点构造
    Vector3D<double> v4(p1, p2);
    v4.v_display();

    // 模长
    double norm = v2.norm();
    cout << "Norm: " << norm << endl;

    // x
    cout << "v2.x = " << v2.get_x() << endl;

    // y
    cout << "v2.y = " << v2.get_y() << endl;

    // z
    cout << "v2.z = " << v2.get_z() << endl;

    // 单位向量
    Vector3D<double> v_unit = v2.unit();
    v_unit.v_display();

    // 加
    Vector3D<double> v_add = v1 + v2;
    v_add.v_display();

    // 减
    Vector3D<double> v_sub = v2 - v1;
    v_sub.v_display();

    // 标量向量乘
    Vector3D<double> v_scale = v2 * 2.5;
    v_scale.v_display();

    // 向量标量除
    Vector3D<double> v_divide = v2 / 2.0;
    v_divide.v_display();

    // 叉积
    Vector3D<double> v_cross = v2.cross(v4);
    v_cross.v_display();

    // 投影
    Vector3D<double> v_projection = v2.project_to(v4);
    cout << "Projection: " << endl;
    v_projection.v_display();

    // 点积
    double dot_product = v2.dot(v4);
    cout << "Dot Product: " << dot_product << endl;

    // 夹角
    double angle = v2.included_angle(v4);
    cout << "Angle: " << angle << endl;

    return 0;
}