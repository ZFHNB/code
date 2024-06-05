#include "p2.h"
#include "v2.h"

#include <iostream>
using namespace std;

int main(void){
	
	// 默认构造
    Vector2D<double> v1;
    v1.v_display(); 

    // 带参构造
    Vector2D<double> v2(3, 4);
    v2.v_display(); 

    // 一点构造
    Point2D<double> p1(1, 2);
    Vector2D<double> v3(p1);
    v3.v_display(); 

    // 两点构造
    Point2D<double> start(-1, -1), end(2, 3);
    Vector2D<double> v4(start, end);
    v4.v_display(); 

    // 模长
    double norm = v2.norm();
    cout << "Norm: " << norm << endl;

	//x
	cout << "v1.x = " << v1.get_x() << endl;

	//y
	cout << "v1.y = " << v1.get_y() << endl;

    // 加
    Vector2D<double> v_sum = v1 + v2;
    v_sum.v_display(); 

    // 减
    Vector2D<double> v_diff = v2 - v1;
    v_diff.v_display(); 

    // 单位向量
    Vector2D<double> v_unit = v2.unit();
    v_unit.v_display(); 

    // 叉积
    Vector2D<double> cross_product = v2.cross(v4);
    cross_product.v_display();

    // 投影
    Vector2D<double> projection = v2.project_to(v4);
    cout << "Projection: " << endl;
    projection.v_display();

    // 点积
    double dot_product = v2.dot(v4);
    cout << "Dot Product: " << dot_product << endl;

    // 夹角
    double angle = v2.included_angle(v4);
    cout << "Angle: " << angle << endl;

    // 标量和向量的乘法
    Vector2D<double> v_scale = v2 * 2.5;
    v_scale.v_display();

    // 向量对标量的除法
    Vector2D<double> v_divide = v2 / 2.0;
    v_divide.v_display();
	return 0;
}
