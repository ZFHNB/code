#include <stdio.h>

int main(){
    char *p = "Hello";

    p++; // p 现在指向 'e'
    printf("%c\n", *(p));//输出结果为e

    p--;
    printf("%c\n", *(p));//输出结果为H

    char *q = p + 2; // q 指向 'l'
    printf("%c\n", *(q));//输出结果为l
    /* 或 */
    p += 2;// p 现在指向 'e'
    printf("%c\n", *(q));//输出结果为l

    return 0;
}