// 7、商店销售某一商品，商店每天公布统一的折扣(discount)。
// 同时允许销售人员在销售时灵活掌握售价(price)，
// 在此基础上，对一次购10件以上者，还可以享受9.8折优惠。现已知当天3名销货员的销售情况为：
//  销货员号（num）	销货件数（quantity）	销货单价（price）
// 101	                    5	                23.5
// 102	                    12	                24.56
// 103	                    100	                21.5

// 请编程序，计算出当日此商品的总销售款sum，以及每件商品的平均售价。
// 要求用静态数据成员和静态成员函数。
// (提示： 将折扣discount、总销售款sum和商品销售总件数n声明为静态数据成员，
// 再定义静态成员函数average(求平均售价)和display(输出结果)。

#include <iostream>

class Sales {
private:
    static double discount;
    static double sum;
    static int n;

public:
    static void calculate(int quantity, double price) {
        double total = quantity * price;
        if (quantity >= 10) {
            total *= 0.98; // 享受9.8折优惠
        }
        sum += total;
        n += quantity;
    }

    static double average() {
        return sum / n;
    }

    static void display() {
        std::cout << "总销售款: " << sum << std::endl;
        std::cout << "平均售价: " << average() << std::endl;
    }
};

double Sales::discount = 0.9; // 折扣
double Sales::sum = 0.0; // 总销售款
int Sales::n = 0; // 商品销a售总件数

int main() {
    Sales::calculate(5, 23.5); // 销货员101
    Sales::calculate(12, 24.56); // 销货员102
    Sales::calculate(100, 21.5); // 销货员103

    Sales::display();

    return 0;
}
