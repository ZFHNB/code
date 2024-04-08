#include <iostream>
#include <string>
using namespace std;

class PenCore // 抽象产品
{
public:
    string color;
    virtual void writeWord(string s) = 0;
};

// 具体产品
class RedPenCore : public PenCore
{
public:
    RedPenCore()
    {
        color = "红色";
    }

    void writeWord(string s) override
    {
        cout << "写出" << color << "的字:" << s << endl;
    }
};

// 构造者
class BallPen
{
public:
    BallPen(PenCore* core) : penCore(core)
    {
        cout << "生产了一只装有" << penCore->color <<"笔芯的圆珠笔"<< endl;
    }

private:
    PenCore* penCore;
};

// 具体构造者
class RedBallPen : public BallPen
{
public:
    RedBallPen() : BallPen(new RedPenCore())
    {
        return new RedPenCore();
    }
};

int main()
{
	PenCore *pencore = new RedPenCore();
	BallPen *ballpen = new RedBallPen();
	pencore = RedBallPen;
	return 0;
}

