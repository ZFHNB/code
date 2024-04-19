#include <iostream>
using namespace std;

class Rectangle
{
    private:
        double length;
        double width;
    public:
        Rectangle(double length, double width)
        {
            this->length = length;
            this->width = width;
        }
        double getLength()
        {
            return length;
        }
        double getWidth()
        {
            return width;
        }
        void setLength(double length)
        {
            this->length = length;
        }
        void setLWidth(double width)
        {
            this->width = width;
        }
};
int main()
{
    Rectangle r(12,12);
    double length = r.getLength();
    double width = r.getWidth();
    r.setLength(13);
    length = r.getLength();
    cout<<length<<width<<endl;
}