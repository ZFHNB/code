#include <iostream>
using namespace std;

class Rectangular
{
private:
    double length;
    double width;
    double height;
    double volume;

public:
    void setDims()
    {
        cin >> length >> width >> height;
    }
    void calcVolume()
    {
        volume = length * width * height;
    }
    void showVolume()
    {
        cout << "此长方柱的体积为：" << volume << endl;
    }
};
int main()
{
    Rectangular r;
    for (int i = 0; i < 3; i++)
    {
        cout << "请输入第" << i + 1 << "个长方柱的长宽高:" << endl;
        r.setDims();
        r.calcVolume();
        r.showVolume();
    }

    return 0;
}
