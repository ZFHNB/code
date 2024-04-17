#include <iostream>
#include "arraymax.h"
using namespace std;

void arraymax::set_value()
{
    int i;
    for(i = 0; i < 10; i++)
    {
        cin>>array[i];
    }
}

void arraymax::max_value()
{
    int i;
    for(i = 0; i < 10; i++)
    {
        if(array[i] > max)
            max = array[i];
    }
}

void arraymax::show_value()
{
    cout<<"max = "<<max<<endl;
}