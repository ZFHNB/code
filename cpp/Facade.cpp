#include <iostream>
#include <string>
using namespace std;

// 统计字符长度
class CheckWord
{
    public:
        const int basicAmount = 85;
        string advertisement;
        int amount;
        
        CheckWord(string advertisement)
        {
            this->advertisement = advertisement;
        }
        void setChargeAmount()
        {
            amount = advertisement.size() + basicAmount;
        }
        int getAmount()
        {
            return amount;
        }
};


int main()
{


    return 0;
}