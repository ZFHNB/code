#include <stdio.h>

inline int square(int x);

inline int square(int x)
{
    return x * x;
}

int main()
{
    int i = 1;

    while (i <= 100)
    {
        printf("%d 的平方是: %d \n", i - 1, square(i));
        i++;
    }

    return 0;
}
